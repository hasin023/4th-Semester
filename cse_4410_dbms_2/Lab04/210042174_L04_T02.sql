SET SERVEROUTPUT ON;

-- Task A --
CREATE OR REPLACE PROCEDURE GET_UNCHANGED_SALARY AS
    CURSOR INSTRUCTOR_CURSOR IS
    SELECT
        I.ID,
        I.NAME,
        I.SALARY,
        NVL(SUM(C.CREDITS), 0) AS TOTAL_CREDITS
    FROM
        INSTRUCTOR I
        LEFT JOIN TEACHES T
        ON I.ID = T.ID
        LEFT JOIN COURSE C
        ON T.COURSE_ID = C.COURSE_ID
    GROUP BY
        I.ID,
        I.NAME,
        I.SALARY;
    UPDATED_SALARY NUMBER;
BEGIN
    FOR INSTRUCTOR_RECORD IN INSTRUCTOR_CURSOR LOOP
        UPDATED_SALARY := 9000 * INSTRUCTOR_RECORD.TOTAL_CREDITS;
        IF UPDATED_SALARY <> INSTRUCTOR_RECORD.SALARY THEN
            UPDATE INSTRUCTOR
            SET
                SALARY = UPDATED_SALARY
            WHERE
                ID = INSTRUCTOR_RECORD.ID;
        ELSE
            DBMS_OUTPUT.PUT_LINE('Unchanged salary -> '
                                 || INSTRUCTOR_RECORD.NAME);
        END IF;
    END LOOP;
END GET_UNCHANGED_SALARY;
/

BEGIN
    GET_UNCHANGED_SALARY;
END;
/

-- Task B --
CREATE OR REPLACE PROCEDURE ELIGIBLE_STUDENTS IS
BEGIN
    FOR COURSE_RECORDS IN (
        SELECT
            C.COURSE_ID,
            C.TITLE,
            S.NAME
        FROM
            COURSE  C
            JOIN PREREQ P
            ON C.COURSE_ID = P.COURSE_ID
            JOIN TAKES T
            ON P.PREREQ_ID = T.COURSE_ID
            JOIN STUDENT S
            ON T.ID = S.ID
    ) LOOP
        DBMS_OUTPUT.PUT_LINE('Course Title: '
                             || COURSE_RECORDS.TITLE);
        DBMS_OUTPUT.PUT_LINE('Student Eligible: '
                             || COURSE_RECORDS.NAME);
        DBMS_OUTPUT.PUT_LINE('-----------------------------');
    END LOOP;
END ELIGIBLE_STUDENTS;
/

BEGIN
    ELIGIBLE_STUDENTS;
END;
/

-- Task C --
CREATE OR REPLACE PROCEDURE PRINT_ROUTINE(
    STUDENT_NAME IN VARCHAR2
) IS
BEGIN
    FOR STUDENT_ROUTINE IN (
        SELECT
            DISTINCT TS.DAY,
            TS.START_HR,
            TS.START_MIN,
            TS.END_HR,
            TS.END_MIN,
            S.COURSE_ID,
            C.TITLE,
            S.BUILDING,
            S.ROOM_NUMBER
        FROM
            STUDENT   ST
            JOIN TAKES T
            ON ST.ID = T.ID
            JOIN SECTION S
            ON T.COURSE_ID = S.COURSE_ID
            AND T.SEC_ID = S.SEC_ID
            AND T.SEMESTER = S.SEMESTER
            AND T.YEAR = S.YEAR
            JOIN TIME_SLOT TS
            ON S.TIME_SLOT_ID = TS.TIME_SLOT_ID
            JOIN COURSE C
            ON S.COURSE_ID = C.COURSE_ID
        WHERE
            ST.NAME = STUDENT_NAME
    ) LOOP
        DBMS_OUTPUT.PUT_LINE(STUDENT_ROUTINE.DAY);
        DBMS_OUTPUT.PUT_LINE(STUDENT_ROUTINE.START_HR
                             || ':'
                             || STUDENT_ROUTINE.START_MIN
                             || ' - '
                             || STUDENT_ROUTINE.END_HR
                             || ':'
                             || STUDENT_ROUTINE.END_MIN);
        DBMS_OUTPUT.PUT_LINE(STUDENT_ROUTINE.COURSE_ID
                             || ' - '
                             || STUDENT_ROUTINE.TITLE);
        DBMS_OUTPUT.PUT_LINE(STUDENT_ROUTINE.BUILDING
                             || ' - '
                             || STUDENT_ROUTINE.ROOM_NUMBER);
        DBMS_OUTPUT.PUT_LINE('-----------------------------');
    END LOOP;
END PRINT_ROUTINE;
/

BEGIN
    PRINT_ROUTINE('&student_name');
END;
/

-- Task D --
CREATE OR REPLACE PROCEDURE ASSIGN_STUDENTS AS
BEGIN
    FOR INSTRUCTOR_RECORD IN (
        SELECT
            I.ID        AS INSTRUCTOR_ID,
            I.NAME      AS INSTRUCTOR_NAME,
            I.DEPT_NAME
        FROM
            INSTRUCTOR I
        WHERE
            I.ID NOT IN (
                SELECT
                    I_ID
                FROM
                    ADVISOR
            )
    ) LOOP
        FOR STUDENT_REC IN (
            SELECT
                S.ID        AS STUDENT_ID,
                S.NAME      AS STUDENT_NAME,
                S.DEPT_NAME,
                S.TOT_CRED
            FROM
                STUDENT S
            WHERE
                S.DEPT_NAME = INSTRUCTOR_RECORD.DEPT_NAME
                AND S.ID NOT IN (
                    SELECT
                        S_ID
                    FROM
                        ADVISOR
                )
            ORDER BY
                S.TOT_CRED ASC
        ) LOOP
            INSERT INTO ADVISOR(
                S_ID,
                I_ID
            ) VALUES (
                STUDENT_REC.STUDENT_ID,
                INSTRUCTOR_RECORD.INSTRUCTOR_ID
            );
            EXIT;
        END LOOP;
    END LOOP;

    FOR INSTRUCTOR_RECORD IN (
        SELECT
            NAME
        FROM
            INSTRUCTOR
        WHERE
            ID NOT IN (
                SELECT
                    I_ID
                FROM
                    ADVISOR
            )
    ) LOOP
        DBMS_OUTPUT.PUT_LINE('Without students: '
                             || INSTRUCTOR_RECORD.NAME);
    END LOOP;
END ASSIGN_STUDENTS;
/

BEGIN
    ASSIGN_STUDENTS;
END;
/

-- Task E --
CREATE OR REPLACE PROCEDURE INSERT_INSTRUCTOR AS
    N_INSTRUCTOR_ID         VARCHAR2(5);
    N_INSTRUCTOR_NAME       VARCHAR2(20) := 'New Instructor';
    N_INSTRUCTOR_DEPARTMENT VARCHAR2(20);
    N_INSTRUCTOR_SALARY     NUMBER;
    CURSOR MOST_STUDENT_DEPT IS
    SELECT
        DEPT_NAME
    FROM
        (
            SELECT
                DEPT_NAME,
                COUNT(*)  AS STUDENT_COUNT
            FROM
                STUDENT
            GROUP BY
                DEPT_NAME
            ORDER BY
                STUDENT_COUNT ASC
        )
    WHERE
        ROWNUM = 1;
BEGIN
    OPEN MOST_STUDENT_DEPT;
    FETCH MOST_STUDENT_DEPT INTO N_INSTRUCTOR_DEPARTMENT;
    CLOSE MOST_STUDENT_DEPT;
    SELECT
        MIN(ID) INTO N_INSTRUCTOR_ID
    FROM
        INSTRUCTOR;
    SELECT
        AVG(SALARY) INTO N_INSTRUCTOR_SALARY
    FROM
        INSTRUCTOR
    WHERE
        DEPT_NAME = N_INSTRUCTOR_DEPARTMENT;
    INSERT INTO INSTRUCTOR (
        ID,
        NAME,
        DEPT_NAME,
        SALARY
    ) VALUES (
        TO_CHAR(TO_NUMBER(N_INSTRUCTOR_ID) - 1),
        N_INSTRUCTOR_NAME,
        N_INSTRUCTOR_DEPARTMENT,
        N_INSTRUCTOR_SALARY
    );
    DBMS_OUTPUT.PUT_LINE('New Instructor Information:');
    DBMS_OUTPUT.PUT_LINE('ID: '
                         || TO_CHAR(TO_NUMBER(N_INSTRUCTOR_ID) - 1));
    DBMS_OUTPUT.PUT_LINE('Name: '
                         || N_INSTRUCTOR_NAME);
    DBMS_OUTPUT.PUT_LINE('Department: '
                         || N_INSTRUCTOR_DEPARTMENT);
    DBMS_OUTPUT.PUT_LINE('Salary: '
                         || TO_CHAR(N_INSTRUCTOR_SALARY));
    COMMIT;
END INSERT_INSTRUCTOR;
/

BEGIN
    INSERT_INSTRUCTOR;
END;
/