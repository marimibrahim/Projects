import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/ProfileController")
public class ProfileController extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("username") == null) {
            response.setStatus(401);
            return;
        }

        String username = (String) session.getAttribute("username");
        UserDAO userDAO = new UserDAO();
        String[] details = userDAO.getUserDetails(username);

        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        
        if (details != null) {
            out.print("{\"firstName\": \"" + details[0] + 
                      "\", \"lastName\": \"" + details[1] + 
                      "\", \"email\": \"" + details[2] + 
                      "\", \"username\": \"" + username + "\"}");
        } else {
            response.setStatus(500);
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("username") == null) {
            response.setStatus(401);
            return;
        }

        String username = (String) session.getAttribute("username");

        // Read the JSON request body
        StringBuilder sb = new StringBuilder();
        String line;
        try (BufferedReader reader = request.getReader()) {
            while ((line = reader.readLine()) != null) {
                sb.append(line);
            }
        }
        
        String json = sb.toString();
        String fName = extractFromJson(json, "firstName");
        String lName = extractFromJson(json, "lastName");
        String email = extractFromJson(json, "email");

        UserDAO userDAO = new UserDAO();
        boolean success = userDAO.updateUser(username, fName, lName, email);

        response.setContentType("application/json");
        PrintWriter out = response.getWriter();
        
        if (success) {
            out.print("{\"status\": \"success\"}");
        } else {
            response.setStatus(500);
            out.print("{\"status\": \"error\"}");
        }
    }

    private String extractFromJson(String json, String key) {
        String search = "\"" + key + "\":\"";
        int start = json.indexOf(search);
        if (start == -1) return "";
        start += search.length();
        int end = json.indexOf("\"", start);
        if (end == -1) return json.substring(start);
        return json.substring(start, end);
    }
}