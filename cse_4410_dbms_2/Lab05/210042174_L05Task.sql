SET SERVEROUTPUT ON;

-- Task 1 --
CREATE OR REPLACE PROCEDURE DECREASE_BUDGET AS
    CURSOR DEPT_CURSOR IS
    SELECT
        DEPT_NAME,
        BUDGET
    FROM
        DEPARTMENT
    WHERE
        BUDGET > 99999;
    AFFECTED_DEPARTMENTS NUMBER := 0;
BEGIN
    FOR DEPT_RECORD IN DEPT_CURSOR LOOP
        UPDATE DEPARTMENT
        SET
            BUDGET = BUDGET * 0.90
        WHERE
            DEPT_NAME = DEPT_RECORD.DEPT_NAME;
        AFFECTED_DEPARTMENTS := AFFECTED_DEPARTMENTS + SQL%ROWCOUNT;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('Number of departments affected => '
                         || AFFECTED_DEPARTMENTS);
    DBMS_OUTPUT.PUT_LINE('Number of departments not affected => '
                         || (DEPT_CURSOR%ROWCOUNT - AFFECTED_DEPARTMENTS));
    COMMIT;
END DECREASE_BUDGET;
/

BEGIN
    DECREASE_BUDGET;
END;
/

------------------------------------------------------------------------------------------------------------------------------

-- Task 2 --
CREATE OR REPLACE PROCEDURE VIEW_INSTRUCTORS(
    INPUT_DAY VARCHAR2,
    INPUT_START_HOUR NUMBER,
    INPUT_END_HOUR NUMBER
) AS
    CURSOR INSTRUCTOR_CURSOR IS
    SELECT
        DISTINCT INSTRUCTOR.NAME
    FROM
        INSTRUCTOR
        JOIN TEACHES
        ON INSTRUCTOR.ID = TEACHES.ID
        JOIN SECTION
        ON TEACHES.COURSE_ID = SECTION.COURSE_ID
        AND TEACHES.SEC_ID = SECTION.SEC_ID
        JOIN TIME_SLOT
        ON SECTION.TIME_SLOT_ID = TIME_SLOT.TIME_SLOT_ID
    WHERE
        TIME_SLOT.DAY = INPUT_DAY
        AND (TIME_SLOT.START_HR < INPUT_END_HOUR
        OR (TIME_SLOT.START_HR = INPUT_END_HOUR
        AND TIME_SLOT.START_MIN = 0))
        AND (TIME_SLOT.END_HR > INPUT_START_HOUR
        OR (TIME_SLOT.END_HR = INPUT_START_HOUR
        AND TIME_SLOT.END_MIN = 0));
    IS_INSTRUCTOR_FOUND BOOLEAN := FALSE;
BEGIN
    FOR INSTRUCTOR_RECORD IN INSTRUCTOR_CURSOR LOOP
        DBMS_OUTPUT.PUT_LINE('Instructors =>  '
                             || INSTRUCTOR_RECORD.NAME);
        IS_INSTRUCTOR_FOUND := TRUE;
    END LOOP;

    IF NOT IS_INSTRUCTOR_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No instructors found.');
    END IF;
END;
/

DECLARE
    INPUT_DAY_VALUE      VARCHAR2(5);
    INPUT_START_HR_VALUE NUMBER;
    INPUT_END_HR_VALUE   NUMBER;
BEGIN
    INPUT_DAY_VALUE := '&day';
    INPUT_START_HR_VALUE := &START_HOUR;
    INPUT_END_HR_VALUE := &END_HOUR;
    VIEW_INSTRUCTORS(INPUT_DAY_VALUE, INPUT_START_HR_VALUE, INPUT_END_HR_VALUE);
END;
/

------------------------------------------------------------------------------------------------------------------------------

-- Task 3 --
CREATE OR REPLACE PROCEDURE GET_TOP_STUDENTS(
    N IN NUMBER
) AS
    CURSOR S_COURSES_CURSOR IS
    SELECT
        S.ID,
        S.NAME,
        S.DEPT_NAME,
        COUNT(T.COURSE_ID) AS TOTAL_COURSES
    FROM
        STUDENT S
        LEFT JOIN TAKES T
        ON S.ID = T.ID
    GROUP BY
        S.ID,
        S.NAME,
        S.DEPT_NAME
    ORDER BY
        TOTAL_COURSES DESC;
    LOOP_COUNT NUMBER := 0;
BEGIN
    FOR STUDENT_RECORD IN S_COURSES_CURSOR LOOP
        LOOP_COUNT := LOOP_COUNT + 1;
        EXIT WHEN LOOP_COUNT > N OR STUDENT_RECORD.ID IS NULL;
        DBMS_OUTPUT.PUT_LINE('Student ID => '
                             || STUDENT_RECORD.ID
                             || ', Name => '
                             || STUDENT_RECORD.NAME
                             || ', Department => '
                             || STUDENT_RECORD.DEPT_NAME
                             || ', Num Courses => '
                             || STUDENT_RECORD.TOTAL_COURSES);
    END LOOP;
END;
/

DECLARE
    STUDENT_INPUT NUMBER;
BEGIN
    STUDENT_INPUT:= &STUDENT_INPUT;
    TOP_STUDENTS(STUDENT_INPUT);
END;
/

-- ------------------------------------------------------------------------------------------------------------------------------

-- Task 4 --
CREATE OR REPLACE PROCEDURE INSERT_NEW_STUDENT AS
    FOUND_DEPT_NAME VARCHAR2(50);
    NEW_SID         NUMBER;
BEGIN
    FOR DEPT_RECORD IN (
        SELECT
            DEPT_NAME,
            COUNT(*)  AS STUDENT_COUNT
        FROM
            STUDENT
        GROUP BY
            DEPT_NAME
        ORDER BY
            STUDENT_COUNT ASC
    ) LOOP
        FOUND_DEPT_NAME := DEPT_RECORD.DEPT_NAME;
        EXIT;
    END LOOP;

    SELECT
        NVL(MAX(TO_NUMBER(ID)), 0) + 1 INTO NEW_SID
    FROM
        STUDENT;
 -- Insert
    INSERT INTO STUDENT(
        ID,
        NAME,
        DEPT_NAME,
        TOT_CRED
    ) VALUES (
        NEW_SID,
        'Jane Doe',
        FOUND_DEPT_NAME,
        0
    );
    DBMS_OUTPUT.PUT_LINE('New student inserted successfully.');
END INSERT_NEW_STUDENT;
/

BEGIN
    INSERT_NEW_STUDENT;
END;
/

-- ------------------------------------------------------------------------------------------------------------------------------

-- Task 5 --
CREATE OR REPLACE PROCEDURE ASSIGN_SPECIFIC_ADVISOR AS
    CURSOR STUDENT_CURSOR IS
    SELECT
        STUDENT.ID,
        STUDENT.NAME,
        STUDENT.DEPT_NAME
    FROM
        STUDENT
    WHERE
        STUDENT.ID NOT IN (
            SELECT
                ADVISOR.S_ID
            FROM
                ADVISOR
        );
    NEW_STUDENT_ID       STUDENT.ID%TYPE;
    NEW_STUDENT_NAME     STUDENT.NAME%TYPE;
    NEW_STUDENT_DEPT     STUDENT.DEPT_NAME%TYPE;
    NEW_ADVISOR_ID       INSTRUCTOR.ID%TYPE;
    NEW_ADVISOR_NAME     INSTRUCTOR.NAME%TYPE;
    NUM_STUDENTS_ADVISED NUMBER;
BEGIN
    FOR NEW_STUDENT_RECORD IN STUDENT_CURSOR LOOP
        NEW_STUDENT_ID := NEW_STUDENT_RECORD.ID;
        NEW_STUDENT_NAME := NEW_STUDENT_RECORD.NAME;
        NEW_STUDENT_DEPT := NEW_STUDENT_RECORD.DEPT_NAME;
        FOR NEW_ADVISOR_REC IN (
            SELECT
                INSTRUCTOR.ID,
                INSTRUCTOR.NAME,
                COUNT(ADVISOR.S_ID) AS ADVISOR_COUNT
            FROM
                INSTRUCTOR
                LEFT JOIN ADVISOR
                ON INSTRUCTOR.ID = ADVISOR.I_ID
            WHERE
                INSTRUCTOR.DEPT_NAME = NEW_STUDENT_DEPT
            GROUP BY
                INSTRUCTOR.ID,
                INSTRUCTOR.NAME
            ORDER BY
                COUNT(ADVISOR.S_ID) ASC
        ) LOOP
            NEW_ADVISOR_ID := NEW_ADVISOR_REC.ID;
            NEW_ADVISOR_NAME := NEW_ADVISOR_REC.NAME;
            NUM_STUDENTS_ADVISED := NEW_ADVISOR_REC.ADVISOR_COUNT;
            INSERT INTO ADVISOR (
                S_ID,
                I_ID
            ) VALUES (
                NEW_STUDENT_ID,
                NEW_ADVISOR_ID
            );
            EXIT;
        END LOOP;

        DBMS_OUTPUT.PUT_LINE('Student=> '
                             || NEW_STUDENT_NAME
                             || ', Advisor=> '
                             || NEW_ADVISOR_NAME
                             || ', Students advised by Advisor=> '
                             || NUM_STUDENTS_ADVISED);
    END LOOP;
END;
/

BEGIN
    ASSIGN_SPECIFIC_ADVISOR;
END;
/