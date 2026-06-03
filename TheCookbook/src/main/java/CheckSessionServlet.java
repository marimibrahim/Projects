import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet("/check-session")
public class CheckSessionServlet extends HttpServlet {
    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        
        HttpSession session = request.getSession(false); 
        
        // Check if user is logged in
        if (session != null && session.getAttribute("userId") != null) {
            
            // Retrieve firstname (matching the database table schema)
            String firstName = (String) session.getAttribute("firstname");
            
            if (firstName == null || firstName.isBlank()) {
                firstName = "User";
            }
            
            response.setStatus(HttpServletResponse.SC_OK);
            response.getWriter().write("{\"firstName\": \"" + firstName + "\"}");
        } else {
            // No user logged in, send Unauthorized
            response.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
            response.getWriter().write("{}");
        }
    }
}