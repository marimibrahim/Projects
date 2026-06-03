import com.fasterxml.jackson.databind.ObjectMapper;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

@WebServlet("/ShoppingListController")
public class ShoppingListController extends HttpServlet {

    private final ShoppingListDAO shoppingListDAO = new ShoppingListDAO();
    private final ObjectMapper mapper = new ObjectMapper();

    // Fetch Shopping List
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        Integer userId = getUserId(request);
        if (userId == null) {
            response.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
            return;
        }
        List<ShoppingListRecord> list = shoppingListDAO.getShoppingList(userId);
        mapper.writeValue(response.getWriter(), list);
    }

    // Add to Shopping List
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        Integer userId = getUserId(request);
        if (userId == null) {
            response.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
            return;
        }

        String[] selectedIngredients = request.getParameterValues("shopping_ingredients");
        if (selectedIngredients != null) {
            for (String ingIdStr : selectedIngredients) {
                try {
                    shoppingListDAO.addIngredientToList(userId, Integer.parseInt(ingIdStr));
                } catch (NumberFormatException ignored) {}
            }
        }
        response.getWriter().write("{\"status\": \"success\"}");
    }

    // Clear Shopping List
    @Override
    protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        Integer userId = getUserId(request);
        if (userId == null) {
            response.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
            return;
        }
        shoppingListDAO.clearList(userId);
        response.getWriter().write("{\"status\": \"success\", \"message\": \"List cleared\"}");
    }

    private Integer getUserId(HttpServletRequest request) {
        HttpSession session = request.getSession(false);
        return session != null ? (Integer) session.getAttribute("user_id") : null;
    }
}