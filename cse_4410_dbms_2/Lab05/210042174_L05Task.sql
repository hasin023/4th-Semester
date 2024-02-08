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
    FOR DEPT_REC IN DEPT_CURSOR LOOP
        UPDATE DEPARTMENT
        SET
            BUDGET = BUDGET * 0.90
        WHERE
            DEPT_NAME = DEPT_REC.DEPT_NAME;
        AFFECTED_DEPARTMENTS := AFFECTED_DEPARTMENTS + SQL%ROWCOUNT;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('Number of departments affected: '
                         || AFFECTED_DEPARTMENTS);
    DBMS_OUTPUT.PUT_LINE('Number of departments not affected: '
                         || (DEPT_CURSOR%ROWCOUNT - AFFECTED_DEPARTMENTS));
    COMMIT;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: '
                             || SQLERRM);
        ROLLBACK;
END DECREASE_BUDGET;
/

BEGIN
    DECREASE_BUDGET;
END;
/

------------------------------------------------------------------------------------------------------------------------------

-- Task 2 --
CREATE OR REPLACE PROCEDURE FIND_INSTRUCTOR AS
    INPUT_DAY     VARCHAR2(1);
    STARTING_HOUR NUMBER;
    ENDING_HOUR   NUMBER;
BEGIN
 -- Input
    INPUT_DAY := &INPUT_DAY;
    STARTING_HOUR := &STARTING_HOUR;
    ENDING_HOUR := &ENDING_HOUR;
 -- Instructor Cursor
    CURSOR INSTRUCTOR_CURSOR IS
    SELECT
        DISTINCT I.NAME
    FROM
        INSTRUCTOR I
        INNER JOIN TEACHES T
        ON I.ID = T.ID
        INNER JOIN SECTION S
        ON T.COURSE_ID = S.COURSE_ID
        AND T.SEC_ID = S.SEC_ID
        AND T.SEMESTER = S.SEMESTER
        AND T.YEAR = S.YEAR
        INNER JOIN TIME_SLOT TS
        ON S.TIME_SLOT_ID = TS.TIME_SLOT_ID
    WHERE
        TS.DAY = INPUT_DAY
        AND (TS.START_HR < ENDING_HOUR
        OR (TS.START_HR = ENDING_HOUR
        AND TS.START_MIN = 0))
        AND (TS.END_HR > STARTING_HOUR
        OR (TS.END_HR = STARTING_HOUR
        AND TS.END_MIN = 0));
 -- LOOP
    FOR INSTRUCTOR_REC IN INSTRUCTOR_CURSOR LOOP
        DBMS_OUTPUT.PUT_LINE('Instructor: '
                             || INSTRUCTOR_REC.NAME);
    END LOOP;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: '
                             || SQLERRM);
END FIND_INSTRUCTOR;
/

BEGIN
    FIND_INSTRUCTOR;
END;
/

------------------------------------------------------------------------------------------------------------------------------

-- Task 3 --
CREATE OR REPLACE PROCEDURE TOP_STUDENT AS
    INPUT_NUMBER NUMBER;
BEGIN
 -- INPUT
    INPUT_NUMBER := &INPUT_NUMBER;
 -- Student Cursor
    CURSOR STUDENT_CURSOR IS
    SELECT
        S.ID,
        S.NAME,
        S.DEPT_NAME,
        COUNT(*)    AS COURSES_TAKEN
    FROM
        STUDENT S
        INNER JOIN TAKES T
        ON S.ID = T.ID
    GROUP BY
        S.ID,
        S.NAME,
        S.DEPT_NAME
    ORDER BY
        COURSES_TAKEN DESC;
 -- Keep count of students
    STUDENT_COUNT NUMBER := 0;
 -- LOOP
    FOR STUDENT_REC IN STUDENT_CURSOR LOOP
        EXIT WHEN STUDENT_COUNT >= INPUT_NUMBER;
        STUDENT_COUNT := STUDENT_COUNT + 1;
        DBMS_OUTPUT.PUT_LINE('ID: '
                             || STUDENT_REC.ID
                             || ', Name: '
                             || STUDENT_REC.NAME
                             || ', Department: '
                             || STUDENT_REC.DEPT_NAME
                             || ', Number of Courses: '
                             || STUDENT_REC.COURSES_TAKEN);
    END LOOP;
 -- Check user input
    IF INPUT_NUMBER > STUDENT_COUNT THEN
        DBMS_OUTPUT.PUT_LINE('Input is larger than the total number of students.');
    END IF;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: '
                             || SQLERRM);
END TOP_STUDENT;
/

BEGIN
    TOP_STUDENT;
END;
/

------------------------------------------------------------------------------------------------------------------------------

-- Task 4 --
CREATE OR REPLACE PROCEDURE INSERT_STUDENT AS
    NEW_STUDENT_ID  VARCHAR2(5);
    FOUND_DEPT_NAME VARCHAR2(20);
BEGIN
 -- Get Max
    SELECT
        TO_CHAR(MAX(TO_NUMBER(ID)) + 1) INTO NEW_STUDENT_ID
    FROM
        STUDENT;
    SELECT
        DEPT_NAME INTO FOUND_DEPT_NAME
    FROM
        (
            SELECT
                D.DEPT_NAME,
                COUNT(*)    AS NUM_STUDENTS
            FROM
                DEPARTMENT D
                LEFT JOIN STUDENT S
                ON D.DEPT_NAME = S.DEPT_NAME
            GROUP BY
                D.DEPT_NAME
            ORDER BY
                NUM_STUDENTS
        )
    WHERE
        ROWNUM = 1;
 -- Insert
    INSERT INTO STUDENT (
        ID,
        NAME,
        DEPT_NAME,
        TOT_CRED
    ) VALUES (
        NEW_STUDENT_ID,
        'Jane Doe',
        FOUND_DEPT_NAME,
        0
    );
    COMMIT;
    DBMS_OUTPUT.PUT_LINE('Inserted successfully.');
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('An error occurred: '
                             || SQLERRM);
        ROLLBACK;
END INSERT_STUDENT;
/

BEGIN
    INSERT_STUDENT;
END;
/

------------------------------------------------------------------------------------------------------------------------------

-- Task 5 --