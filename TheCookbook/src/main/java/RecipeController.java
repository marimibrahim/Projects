import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.core.type.TypeReference;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

@WebServlet("/RecipeController/*")
public class RecipeController extends HttpServlet {

    private final RecipeDAO recipeDAO = new RecipeDAO();
    private final ObjectMapper objectMapper = new ObjectMapper();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        String pathInfo = request.getPathInfo();
        
        if (pathInfo != null && pathInfo.equals("/detail")) {
            String idParam = request.getParameter("id");
            if (idParam != null && !idParam.isBlank()) {
                Recipe recipe = recipeDAO.getRecipeById(Integer.parseInt(idParam));
                if (recipe != null) {
                    objectMapper.writeValue(response.getWriter(), recipe);
                    return;
                }
            }
            response.setStatus(HttpServletResponse.SC_NOT_FOUND);
            response.getWriter().write("{\"error\":\"Recipe not found\"}");
        } else {
            String query = request.getParameter("q");
            String tag = request.getParameter("tag");

            if ((query != null && !query.isBlank()) || (tag != null && !tag.isBlank())) {
                List<Recipe> matchedRecipes = recipeDAO.searchRecipes(query, tag);
                objectMapper.writeValue(response.getWriter(), matchedRecipes);
            } else {
                objectMapper.writeValue(response.getWriter(), recipeDAO.getAllRecipes());
            }
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");

        try {
            // Read JSON array of ingredients sent from script.js body
            List<String> ingredients = objectMapper.readValue(request.getInputStream(), new TypeReference<List<String>>(){});
            String category = request.getParameter("category");
            String recipeType = request.getParameter("type");

            List<Recipe> matchedRecipes = recipeDAO.getMatchedRecipes(ingredients, category, recipeType);

            objectMapper.writeValue(response.getWriter(), matchedRecipes);

        } catch (Exception e) {
            e.printStackTrace();
            response.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);
            response.getWriter().write("[]"); 
        }
    }
}