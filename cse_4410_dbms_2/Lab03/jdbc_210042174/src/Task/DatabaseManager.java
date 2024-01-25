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
    public void getInstructorsBySchedule() {}


    public void getTopNStudents() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the value of N:");
        int n = scanner.nextInt();

        String topNQuery = "SELECT student.ID, student.name, student.dept_name, COUNT(takes.course_id) AS course_count " +
                "FROM student " +
                "LEFT JOIN takes ON student.ID = takes.ID " +
                "GROUP BY student.ID " +
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
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    
    
}
