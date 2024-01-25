package Task;

public class Main {
    public static void main(String[] args) {
        Database database = new Database("c_210042174", "cse4308");
        DatabaseManager databaseManager = new DatabaseManager(database);
        databaseManager.decreaseBudget();
        //databaseManager.getTopNStudents();
    }
}
