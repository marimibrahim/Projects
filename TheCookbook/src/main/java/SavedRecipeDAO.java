import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class SavedRecipeDAO extends AbstractDAO {

    public boolean saveRecipe(int userId, int recipeId) {
        if (isRecipeAlreadySaved(userId, recipeId)) return true;

        String sql = "INSERT INTO saved_recipes (user_id, recipe_id) VALUES (?, ?)";
        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, userId);
            stmt.setInt(2, recipeId);
            return stmt.executeUpdate() > 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    private boolean isRecipeAlreadySaved(int userId, int recipeId) {
        String sql = "SELECT saved_id FROM saved_recipes WHERE user_id = ? AND recipe_id = ?";
        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, userId);
            stmt.setInt(2, recipeId);
            try (ResultSet rs = stmt.executeQuery()) {
                return rs.next();
            }
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public List<Recipe> getSavedRecipes(int userId) {
        List<Recipe> recipes = new ArrayList<>();
        String sql = "SELECT r.*, COALESCE(img.image_path, r.img_src) AS final_image " +
                     "FROM recipes r " +
                     "JOIN saved_recipes sr ON r.recipe_id = sr.recipe_id " +
                     "LEFT JOIN recipe_images img ON r.recipe_id = img.recipe_id " +
                     "WHERE sr.user_id = ? ORDER BY sr.saved_at DESC";

        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            
            stmt.setInt(1, userId);
            try (ResultSet rs = stmt.executeQuery()) {
                while (rs.next()) {
                    Recipe recipe = new Recipe();
                    recipe.setRecipeId(rs.getInt("recipe_id"));
                    recipe.setRecipeName(rs.getString("recipe_name"));
                    recipe.setPrepTime(rs.getString("prep_time"));
                    recipe.setTotalTime(rs.getString("total_time"));
                    recipe.setServings(rs.getString("servings"));

                    // Ratings handling
                    String ratingStr = rs.getString("rating");
                    try {
                        if (ratingStr != null) {
                            recipe.setRating(Double.parseDouble(ratingStr));
                        }
                    } catch (NumberFormatException e) {
                        recipe.setRating(0.0);
                    }

                    String img = rs.getString("final_image");
                    if (img == null || img.isEmpty()) {
                        img = rs.getString("img_src");
                    }
                    recipe.setImgSrc(img);

                    recipes.add(recipe);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return recipes;
    }
}