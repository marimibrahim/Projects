import com.fasterxml.jackson.databind.ObjectMapper;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import java.io.IOException;

@WebServlet("/SaveRecipeServlet")
public class SaveRecipeServlet extends HttpServlet {

    private final SavedRecipeDAO savedRecipeDAO = new SavedRecipeDAO();
    private final ObjectMapper mapper = new ObjectMapper();

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("userId") == null) {
            response.setStatus(HttpServletResponse.SC_UNAUTHORIZED); 
            response.getWriter().write("{\"status\":\"error\", \"message\":\"Please log in to save recipes.\"}");
            return;
        }

        int userId = (int) session.getAttribute("userId");

        try {
            SavedRecipeRequest req = mapper.readValue(request.getInputStream(), SavedRecipeRequest.class);
            
            boolean success = savedRecipeDAO.saveRecipe(userId, req.getRecipeId());
            
            if (success) {
                response.getWriter().write("{\"status\":\"success\"}");
            } else {
                response.getWriter().write("{\"status\":\"exists\"}");
            }
        } catch (Exception e) {
            e.printStackTrace();
            response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR); 
            response.getWriter().write("{\"status\":\"error\", \"message\":\"Server error while saving.\"}");
        }
    }
}