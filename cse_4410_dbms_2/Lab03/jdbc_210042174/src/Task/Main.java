package Task;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Database database = new Database("c_210042174", "cse4308");
        DatabaseManager databaseManager = new DatabaseManager(database);
        databaseManager.decreaseBudget();
        
        databaseManager.getInstructorsBySchedule();

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int numberOfStudents = scanner.nextInt();
        databaseManager.getTopNStudents(numberOfStudents);
        databaseManager.insertStudent();
        databaseManager.assignAdvisorsToStudents();
    }
}
