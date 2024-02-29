-- @"/media/hasin023/Trixx/DOCS/IUT/4th_Sem/cse_4410_dbms_2/Lab07/movie.sql";
-- @"/media/hasin023/Trixx/DOCS/IUT/4th_Sem/cse_4410_dbms_2/Lab07/210042174_L7.sql";
SET SERVEROUTPUT ON;

-- -- Task 01
DECLARE
    QUES_SET VARCHAR2(100) := 'Alpha';
BEGIN
    DBMS_OUTPUT.PUT_LINE('Set: '
                         || QUES_SET);
END;
/

-- -- Task 02
SELECT
    DISTINCT A.ACT_FIRSTNAME,
    A.ACT_LASTNAME
FROM
    ACTOR A
    JOIN CASTS C
    ON A.ACT_ID = C.ACT_ID
    JOIN MOVIE M
    ON C.MOV_ID = M.MOV_ID
WHERE
    UPPER(C.ROLE) = UPPER(M.MOV_TITLE);

-- Task 03
CREATE OR REPLACE PROCEDURE GET_MALE_GENRE AS
    MOVIE_GENRE VARCHAR2(100);
BEGIN
    SELECT
        G.GEN_TITLE INTO MOVIE_GENRE
    FROM
        GENRES G
        JOIN MTYPE MT
        ON G.GEN_ID = MT.GEN_ID
        JOIN MOVIE M
        ON MT.MOV_ID = M.MOV_ID
        JOIN CASTS C
        ON M.MOV_ID = C.MOV_ID
        JOIN ACTOR A
        ON C.ACT_ID = A.ACT_ID
    WHERE
        A.ACT_GENDER = 'M'
    GROUP BY
        G.GEN_TITLE
    ORDER BY
        COUNT(DISTINCT A.ACT_ID) DESC FETCH FIRST ROW ONLY;
    DBMS_OUTPUT.PUT_LINE('Movie Genre: '
                         || MOVIE_GENRE);
END;
/

BEGIN
    GET_MALE_GENRE;
END;
/

-- Task 04
CREATE OR REPLACE PROCEDURE TIME_TO_PLAY (
    MOVIE_TITLE VARCHAR2
) IS
    TOTAL_MINTS     NUMBER;
    REMAINING_MINTS NUMBER;
    HOURS           NUMBER;
    MINUTES         NUMBER;
BEGIN
    SELECT
        MOV_TIME INTO TOTAL_MINTS
    FROM
        MOVIE
    WHERE
        MOV_TITLE = MOVIE_TITLE;
 -- Intermission of 15 mints after every 70 mints only if the remainting is > 30 mint -> 210 -> 70 -> 140 + 15 ->
    IF (TOTAL_MINTS > 70) THEN
        REMAINING_MINTS := TOTAL_MINTS;
        WHILE (REMAINING_MINTS > 70) LOOP
            REMAINING_MINTS := REMAINING_MINTS - 70;
            IF (REMAINING_MINTS > 30) THEN
                TOTAL_MINTS := TOTAL_MINTS + 15;
            END IF;
        END LOOP;
    END IF;

    HOURS := TRUNC(TOTAL_MINTS / 60);
    MINUTES := TOTAL_MINTS - (HOURS * 60);
    DBMS_OUTPUT.PUT_LINE('Required time to play '
                         || MOVIE_TITLE
                         || '-> '
                         || HOURS
                         || ' hours '
                         || MINUTES
                         || ' minutes');
END;
/

DECLARE
    USER_TITLE VARCHAR2(100) := '&title';
BEGIN
    TIME_TO_PLAY(USER_TITLE);
END;
/

-- Task 05
CREATE OR REPLACE TRIGGER REVIEW_TRIGGER BEFORE
    INSERT ON RATING FOR EACH ROW
DECLARE
    REVEIW_COUNT  NUMBER;
    CUURENT_GENRE VARCHAR2(100);
BEGIN
    SELECT
        COUNT(DISTINCT MT.GEN_ID) INTO REVEIW_COUNT,
        MT.GEN_ID INTO CUURENT_GENRE
    FROM
        REVIEWER RV
        JOIN RATING R
        ON RV.REV_ID = R.REV_ID
        JOIN MOVIE M
        ON R.MOV_ID = M.MOV_ID
        JOIN MTYPE MT
        ON M.MOV_ID = MT.MOV_ID
    WHERE
        RV.REV_ID = :NEW.REV_ID;
    IF REVEIW_COUNT > 0 THEN
        DBMS_OUTPUT.PUT_LINE('Reviewer has rated other genres');
        IF CURRENT_GENRE <> :NEW.GEN_ID THEN
            DBMS_OUTPUT.PUT_LINE('Rating from all Reviewer');
        ELSE
            DBMS_OUTPUT.PUT_LINE('Rating from only this Reviewer');
        END IF;
    ELSE
        DBMS_OUTPUT.PUT_LINE('Reviewer has NOT rated other genres');
    END IF;
END;
/