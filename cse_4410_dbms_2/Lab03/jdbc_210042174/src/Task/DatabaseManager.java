package Task;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DatabaseManager {
    private final Database database;
    private final Connection connection;
    
    public DatabaseManager(Database database) {
        this.database = database;
        connection = database.getConnection();
    }
    
    
    
    // Task 1
    public void decreaseBudget() {
        if (connection != null) {
            String budgetQuery = "SELECT * FROM department WHERE budget > 99999";
            try (Statement selectStatement = connection.createStatement();
                 ResultSet resultSet = selectStatement.executeQuery(budgetQuery)) {

                while (resultSet.next()) {
                    String departmentName = resultSet.getString("dept_name");
                    double currentBudget = resultSet.getDouble("budget");

                    double newBudget = currentBudget * 0.9;

                    String updateQuery = "UPDATE department SET budget = ? WHERE dept_name = ?";
                    try (PreparedStatement updateStatement = connection.prepareStatement(updateQuery)) {
                        updateStatement.setDouble(1, newBudget);
                        updateStatement.setString(2, departmentName);
                        updateStatement.executeUpdate();
                    }

                    System.out.println("Department: " + departmentName +
                            ", Original Budget: " + currentBudget +
                            ", New Budget: " + newBudget);
                }

            } catch (SQLException e) {
                throw new RuntimeException(e);
            }

            String unaffectedQuery = "SELECT COUNT(*) FROM department WHERE budget <= 99999";
            try (Statement unaffectedStatement = connection.createStatement();
                 ResultSet unaffectedResultSet = unaffectedStatement.executeQuery(unaffectedQuery)) {

                if (unaffectedResultSet.next()) {
                    int unaffectedCount = unaffectedResultSet.getInt(1);
                    System.out.println("Number of departments not affected: " + unaffectedCount);
                }
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }
    
    // Task 2
    public void getInstructorsBySchedule(String dayOfWeek, int startHour, int endHour) {
        try {
            String scheduleQuery = "SELECT DISTINCT instructor.name " +
                    "FROM instructor " +
                    "JOIN teaches ON instructor.ID = teaches.ID " +
                    "JOIN section ON teaches.course_id = section.course_id " +
                    "   AND teaches.sec_id = section.sec_id " +
                    "   AND teaches.semester = section.semester " +
                    "   AND teaches.year = section.year " +
                    "JOIN time_slot ON section.time_slot_id = time_slot.time_slot_id " +
                    "   AND time_slot.day = ? " +
                    "   AND time_slot.start_hr <= ? " +
                    "   AND time_slot.end_hr >= ?";

            try (PreparedStatement scheduleStatement = connection.prepareStatement(scheduleQuery)) {
                scheduleStatement.setString(1, dayOfWeek);
                scheduleStatement.setInt(2, startHour);
                scheduleStatement.setInt(3, endHour);

                try (ResultSet scheduleResultSet = scheduleStatement.executeQuery()) {
                    System.out.println("Instructors available during " + dayOfWeek +
                            " from " + startHour + " to " + endHour + ":");

                    while (scheduleResultSet.next()) {
                        String instructorName = scheduleResultSet.getString("name");
                        System.out.println(instructorName);
                    }
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException("Error executing SQL query", e);
        }
    }


    // Task 3
    public void getTopNStudents(int n) {
        try {
            String topNQuery = "SELECT student.ID, student.name, student.dept_name, COUNT(takes.course_id) AS course_count " +
                    "FROM student " +
                    "LEFT JOIN takes ON student.ID = takes.ID " +
                    "GROUP BY student.ID, student.name, student.dept_name " +
                    "ORDER BY course_count DESC " +
                    "LIMIT ?";

            try (PreparedStatement topNStatement = connection.prepareStatement(topNQuery)) {
                topNStatement.setInt(1, n);

                try (ResultSet topNResultSet = topNStatement.executeQuery()) {
                    System.out.println("Top " + n + " students based on the number of courses taken:");

                    while (topNResultSet.next()) {
                        String studentId = topNResultSet.getString("ID");
                        String studentName = topNResultSet.getString("name");
                        String departmentName = topNResultSet.getString("dept_name");
                        int courseCount = topNResultSet.getInt("course_count");

                        System.out.println("Student ID: " + studentId +
                                ", Name: " + studentName +
                                ", Department: " + departmentName +
                                ", Courses Taken: " + courseCount);
                    }
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException("Error executing SQL query", e);
        }

    }
    
    
    // Task 4
    public void insertStudent() {
        try {
            String lowestDeptQuery = "SELECT dept_name FROM student GROUP BY dept_name ORDER BY COUNT(*) ASC LIMIT 1";

            String lowestDept = null;

            try (Statement lowestDeptStatement = connection.createStatement();
                 ResultSet lowestDeptResultSet = lowestDeptStatement.executeQuery(lowestDeptQuery)) {
                if (lowestDeptResultSet.next()) {
                    lowestDept = lowestDeptResultSet.getString("dept_name");
                }
            }

            if (lowestDept != null) {
                String maxIdQuery = "SELECT MAX(ID) AS max_id FROM student";

                int maxId = 0;

                try (Statement maxIdStatement = connection.createStatement();
                     ResultSet maxIdResultSet = maxIdStatement.executeQuery(maxIdQuery)) {
                    if (maxIdResultSet.next()) {
                        maxId = maxIdResultSet.getInt("max_id");
                    }
                }

                String insertStudentQuery = "INSERT INTO student (ID, name, dept_name, tot_cred) VALUES (?, ?, ?, 0)";

                try (PreparedStatement insertStudentStatement = connection.prepareStatement(insertStudentQuery)) {
                    insertStudentStatement.setInt(1, maxId + 1);
                    insertStudentStatement.setString(2, "Jane Doe");
                    insertStudentStatement.setString(3, lowestDept);

                    int affectedRows = insertStudentStatement.executeUpdate();

                    if (affectedRows > 0) {
                        System.out.println("Student 'Jane Doe' inserted successfully.");
                    } else {
                        System.out.println("Failed to insert student.");
                    }
                }
            } else {
                System.out.println("No departments found. Cannot insert student.");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    
    // Task 5
    public void assignAdvisorsToStudents() {
        try {
            String selectStudentsWithoutAdvisor = "SELECT student.ID, student.name, student.dept_name " +
                    "FROM student " +
                    "LEFT JOIN advisor ON student.ID = advisor.s_id " +
                    "WHERE advisor.s_id IS NULL";

            String selectLeastAdvisedInstructor = "SELECT instructor.ID, instructor.name, COUNT(advisor.s_id) AS advised_count " +
                    "FROM instructor " +
                    "LEFT JOIN advisor ON instructor.ID = advisor.i_id " +
                    "WHERE instructor.dept_name = ? " +
                    "GROUP BY instructor.ID, instructor.name " +
                    "ORDER BY advised_count ASC " +
                    "LIMIT 1";

            String assignAdvisorQuery = "INSERT INTO advisor (s_id, i_id) VALUES (?, ?)";

            try (Statement stmt = connection.createStatement()) {

                ResultSet studentsWithoutAdvisorResultSet = stmt.executeQuery(selectStudentsWithoutAdvisor);

                while (studentsWithoutAdvisorResultSet.next()) {
                    String studentId = studentsWithoutAdvisorResultSet.getString("ID");
                    String studentName = studentsWithoutAdvisorResultSet.getString("name");
                    String studentDept = studentsWithoutAdvisorResultSet.getString("dept_name");

                    try (PreparedStatement leastAdvisedStatement = connection.prepareStatement(selectLeastAdvisedInstructor)) {
                        leastAdvisedStatement.setString(1, studentDept);

                        ResultSet leastAdvisedResultSet = leastAdvisedStatement.executeQuery();

                        if (leastAdvisedResultSet.next()) {
                            String advisorId = leastAdvisedResultSet.getString("ID");
                            String advisorName = leastAdvisedResultSet.getString("name");

                            try (PreparedStatement assignAdvisorStatement = connection.prepareStatement(assignAdvisorQuery)) {
                                assignAdvisorStatement.setString(1, studentId);
                                assignAdvisorStatement.setString(2, advisorId);

                                int rowsAffected = assignAdvisorStatement.executeUpdate();

                                if (rowsAffected > 0) {
                                    System.out.println("Student ID: " + studentId +
                                            ", Name: " + studentName +
                                            ", Advisor: " + advisorName +
                                            ", Advised Count: " + leastAdvisedResultSet.getInt("advised_count"));
                                } else {
                                    System.out.println("Failed to assign advisor for student ID: " + studentId);
                                }
                            }
                        } else {
                            System.out.println("No advisors found for department: " + studentDept);
                        }
                    }
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    
}
