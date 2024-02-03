SET SERVEROUTPUT ON;

-- Task A --


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