import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet("/RegisterServlet")
public class RegisterServlet extends HttpServlet {
    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String fName = request.getParameter("firstName"); 
        String lName = request.getParameter("lastName");  
        String uName = request.getParameter("username");  
        String email = request.getParameter("email");     
        String pass = request.getParameter("password");    

        UserDAO userDAO = new UserDAO();
        if (userDAO.registerUser(fName, lName, uName, email, pass)) {
            // Create session for the user and set username
            HttpSession session = request.getSession();
            session.setAttribute("username", uName);
            
            // Redirect to the profile page
            response.sendRedirect(request.getContextPath() + "/profile/profile.html");
        } else {
            // Redirect back with error flag if registration fails
            response.sendRedirect(request.getContextPath() + "/profile/createAccount.html?error=true");
        }
    }
}