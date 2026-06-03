import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
    
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //Get the parameters from the login.html form
        String uName = request.getParameter("username");
        String pass = request.getParameter("password");

        UserDAO userDAO = new UserDAO();

        //Check if the credentials match the database
        if (userDAO.loginUser(uName, pass)) {
            
            //Create a session for the user so they stay logged in
            HttpSession session = request.getSession();
            session.setAttribute("username", uName);
            
            //Fetch the user ID and store it in the session
            int userId = userDAO.getUserIdByUsername(uName);
            session.setAttribute("userId", userId);
            
            //Redirect to the profile page
            response.sendRedirect(request.getContextPath() + "/profile/profile.html");
            
        } else {
            //If the login fails, redirect back to the login page with an error
            response.sendRedirect(request.getContextPath() + "/profile/login.html?error=true");
        }
    }
}