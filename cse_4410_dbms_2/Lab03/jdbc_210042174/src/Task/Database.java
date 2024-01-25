package Task;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class Database {
    private final String username;
    private final String password;
    
    public Database(String username, String password) {
        this.username = username;
        this.password = password;
    }
    public String getUsername() { return this.username; }
    public String getPassword() { return this.password; }
    
    
    public Connection getConnection() {
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");

            String url = "jdbc:oracle:thin:@localhost:1521:xe";
            Connection connection = DriverManager.getConnection(url, username, password);
            System.out.println("Database connected!");
            return connection;

        } catch (SQLException e) {
            System.out.println("Connection to DB failed. Exception: " + e);
        } catch (ClassNotFoundException e) {
            System.out.println("JDBC driver not found. Exception: " + e);
        }
        
        return null;
    }
    
}

