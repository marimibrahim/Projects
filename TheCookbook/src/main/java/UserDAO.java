import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDAO extends AbstractDAO {

    public boolean loginUser(String typedUsername, String typedPassword) {
        String sql = "SELECT password_hash FROM users WHERE username = ?";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, typedUsername);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    String dbPassword = rs.getString("password_hash");
                    return typedPassword != null && typedPassword.trim().equals(dbPassword.trim());
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }
    
    public boolean registerUser(String fName, String lName, String uName, String email, String pass) {
        String sql = "INSERT INTO users (firstname, lastname, username, password_hash, email) VALUES (?, ?, ?, ?, ?)";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, fName);
            pstmt.setString(2, lName);
            pstmt.setString(3, uName);
            pstmt.setString(4, pass); 
            pstmt.setString(5, email);

            return pstmt.executeUpdate() > 0;
        } catch (SQLException e) {
            System.err.println("Database Registration Error:");
            e.printStackTrace();
        }
        return false;
    }

    public boolean updateUser(String username, String fName, String lName, String email) {
        String sql = "UPDATE users SET firstname = ?, lastname = ?, email = ? WHERE username = ?";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            
            pstmt.setString(1, fName);
            pstmt.setString(2, lName);
            pstmt.setString(3, email);
            pstmt.setString(4, username);
            
            return pstmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    public int getUserIdByUsername(String username) {
        String sql = "SELECT user_id FROM users WHERE username = ?";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
             
            pstmt.setString(1, username);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    return rs.getInt("user_id");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return -1;
    }
    
    public String[] getUserDetails(String username) {
        String query = "SELECT firstname, lastname, email FROM users WHERE username = ?";
        String[] userDetails = new String[3]; 

        try (Connection conn = getConnection(); 
             PreparedStatement pstmt = conn.prepareStatement(query)) {
            
            pstmt.setString(1, username);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    userDetails[0] = rs.getString("firstname");
                    userDetails[1] = rs.getString("lastname");
                    userDetails[2] = rs.getString("email");
                    return userDetails;
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
}