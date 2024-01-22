-- TASK 01 --
SELECT
    NAME
FROM
    INSTRUCTOR
WHERE
    DEPT_NAME = 'Biology';

-- TASK 02 --
SELECT
    COURSE_ID,
    TITLE
FROM
    COURSE
WHERE
    COURSE_ID IN (
        SELECT
            COURSE_ID
        FROM
            TAKES
        WHERE
            ID = '12345'
    );

-- TASK 03 --
SELECT
    NAME,
    DEPT_NAME
FROM
    STUDENT
WHERE
    ID IN (
        SELECT
            ID
        FROM
            TAKES
        WHERE
            COURSE_ID IN (
                SELECT
                    COURSE_ID
                FROM
                    COURSE
                WHERE
                    DEPT_NAME = 'Comp. Sci.'
            )
    );

-- TASK 04 --
SELECT
    NAME
FROM
    STUDENT
WHERE
    ID IN (
        SELECT
            ID
        FROM
            TAKES
        WHERE
            COURSE_ID = 'CS-101'
            AND SEMESTER = 'Spring'
            AND YEAR = '2018'
    );

-- TASK 05 --
SELECT
    STUDENT.NAME
FROM
    STUDENT
WHERE
    STUDENT.ID IN (
        SELECT
            ID
        FROM
            TAKES
        WHERE
            TAKES.COURSE_ID LIKE 'CS%'
        GROUP BY
            TAKES.ID
        HAVING
            COUNT(*) = (
                SELECT
                    MAX(TOTAL_COURS_COUNT)
                FROM
                    (
                        SELECT
                            COUNT(*) AS TOTAL_COURS_COUNT
                        FROM
                            TAKES
                        WHERE
                            TAKES.COURSE_ID LIKE 'CS%'
                        GROUP BY
                            TAKES.ID
                    )
            )
    );

-- TASK 06 --
SELECT
    STUDENT.NAME
FROM
    STUDENT
WHERE
    STUDENT.ID IN (
        SELECT
            TAKES.ID
        FROM
            TAKES
        WHERE
            TAKES.COURSE_ID IN (
                SELECT
                    COURSE_ID
                FROM
                    TEACHES
                GROUP BY
                    COURSE_ID
                HAVING
                    COUNT(DISTINCT ID) >= 3
            )
    );

-- TASK 07 --
SELECT
    COURSE.TITLE,
    SECTION.SEC_ID
FROM
    COURSE,
    SECTION
WHERE
    COURSE.COURSE_ID = SECTION.COURSE_ID
    AND SECTION.COURSE_ID IN (
        SELECT
            TAKES.COURSE_ID
        FROM
            TAKES
        GROUP BY
            TAKES.COURSE_ID
        HAVING
            COUNT(*) = (
                SELECT
                    MIN(TOTAL_ENROLLMENTS)
                FROM
                    (
                        SELECT
                            COUNT(*) AS TOTAL_ENROLLMENTS
                        FROM
                            TAKES
                        GROUP BY
                            TAKES.COURSE_ID
                        HAVING
                            COUNT(*) > 0
                    )
            )
    );

-- TASK 08 --
SELECT
    INSTRUCTOR.NAME,
    INSTRUCTOR.DEPT_NAME,
    COUNT(ADVISOR.S_ID)  AS STUDENT_COUNT
FROM
    INSTRUCTOR
    LEFT JOIN ADVISOR
    ON INSTRUCTOR.ID = ADVISOR.I_ID
GROUP BY
    INSTRUCTOR.ID,
    INSTRUCTOR.NAME,
    INSTRUCTOR.DEPT_NAME;

-- TASK 09 --
SELECT
    S.NAME,
    S.DEPT_NAME
FROM
    STUDENT S
WHERE
    S.ID IN (
        SELECT
            ID
        FROM
            TAKES   T
        GROUP BY
            T.ID
        HAVING
            COUNT(*) > (
                SELECT
                    AVG(COURSE_COUNT)
                FROM
                    (
                        SELECT
                            COUNT(*) AS COURSE_COUNT
                        FROM
                            TAKES TT
                        GROUP BY
                            TT.ID
                    )
            )
    );

-- TASK 10 --
INSERT INTO STUDENT (
    SELECT
        INSTRUCTOR.ID,
        INSTRUCTOR.NAME,
        INSTRUCTOR.DEPT_NAME,
        0
    FROM
        INSTRUCTOR
    WHERE
        INSTRUCTOR.ID<>'12345'
);

-- TASK 11 --
DELETE FROM STUDENT
WHERE
    ID IN (
        SELECT
            ID
        FROM
            INSTRUCTOR
        WHERE
            ID<>'12345'
    );

-- TASK 12 --
UPDATE STUDENT
SET
    TOT_CRED = (
        SELECT
            SUM(CREDITS)
        FROM
            COURSE,
            TAKES
        WHERE
            COURSE.COURSE_ID = TAKES.COURSE_ID
            AND TAKES.ID = STUDENT.ID
        GROUP BY
            TAKES.ID
    )
WHERE
    ID IN (
        SELECT
            ID
        FROM
            TAKES
    );

-- TASK 13 --
UPDATE INSTRUCTOR
SET
    SALARY = CASE WHEN (
        SELECT
            COUNT(*) * 10000
        FROM
            TEACHES
        WHERE
            TEACHES.INSTRUCTOR_ID = INSTRUCTOR.ID
        GROUP BY
            TEACHES.INSTRUCTOR_ID
    ) < 29000 THEN 29000 ELSE (
        SELECT
            COUNT(*) * 10000
        FROM
            TEACHES
        WHERE
            TEACHES.INSTRUCTOR_ID = INSTRUCTOR.ID
        GROUP BY
            TEACHES.INSTRUCTOR_ID
    ) END
WHERE
    ID IN (
        SELECT
            INSTRUCTOR_ID
        FROM
            TEACHES
    );

-- TASK 14 --

CREATE TABLE GRADE_POINT (
    GRADE VARCHAR(2) PRIMARY KEY,
    POINT NUMERIC(2, 0) NOT NULL
);

INSERT INTO GRADE_POINT VALUES (
    'A',
    10
);

INSERT INTO GRADE_POINT VALUES (
    'B',
    8
);

INSERT INTO GRADE_POINT VALUES (
    'C',
    6
);

INSERT INTO GRADE_POINT VALUES (
    'D',
    4
);

INSERT INTO GRADE_POINT VALUES (
    'F',
    0
);

SELECT
    S.ID,
    S.NAME,
    S.DEPT_NAME,
    SUM(G.POINT * C.CREDITS) / SUM(C.CREDITS) AS CPI
FROM
    STUDENT     S,
    TAKES       T,
    COURSE      C,
    GRADE_POINT G
WHERE
    S.ID = T.ID
    AND T.COURSE_ID = C.COURSE_ID
    AND T.GRADE = G.GRADE
GROUP BY
    S.ID,
    S.NAME,
    S.DEPT_NAME;