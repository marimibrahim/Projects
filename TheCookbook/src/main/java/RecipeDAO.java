import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class RecipeDAO extends AbstractDAO {

    public List<Recipe> getAllRecipes() {
        List<Recipe> recipes = new ArrayList<>();
        
        String sql = "SELECT r.*, COALESCE(img.image_path, r.img_src) AS final_image, " +
                     "NULL AS recipe_yield, r.total_time AS timing, " +
                     "(SELECT GROUP_CONCAT(TRIM(CONCAT(IFNULL(ri.quantity, ''), ' ', IFNULL(i.unit, ''), ' ', i.name)) SEPARATOR '\\n') " +
                     " FROM recipe_ingredients ri JOIN ingredients i ON ri.ingredient_id = i.ingredient_id " +
                     " WHERE ri.recipe_id = r.recipe_id) AS raw_ingredients, " +
                     "(SELECT GROUP_CONCAT(i.ingredient_id SEPARATOR ',') " +
                     " FROM recipe_ingredients ri JOIN ingredients i ON ri.ingredient_id = i.ingredient_id " +
                     " WHERE ri.recipe_id = r.recipe_id) AS ingredient_ids " +
                     "FROM recipes r " +
                     "LEFT JOIN curated_recipes c ON r.recipe_id = c.recipe_id " +
                     "LEFT JOIN recipe_images img ON r.recipe_id = img.recipe_id " +
                     "ORDER BY CAST(r.rating AS DECIMAL(3,1)) DESC LIMIT 50";

        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {
             
            while (rs.next()) {
                recipes.add(mapRecipe(rs));
            }
        } catch (Exception e) {
            System.err.println("SQL Error in getAllRecipes:");
            e.printStackTrace();
        }
        return recipes;
    }

    public Recipe getRecipeById(int recipeId) {
        String sql = "SELECT r.*, COALESCE(img.image_path, r.img_src) AS final_image, " +
                     "NULL AS recipe_yield, r.total_time AS timing, " +
                     "(SELECT GROUP_CONCAT(TRIM(CONCAT(IFNULL(ri.quantity, ''), ' ', IFNULL(i.unit, ''), ' ', i.name)) SEPARATOR '\\n') " +
                     " FROM recipe_ingredients ri JOIN ingredients i ON ri.ingredient_id = i.ingredient_id " +
                     " WHERE ri.recipe_id = r.recipe_id) AS raw_ingredients, " +
                     "(SELECT GROUP_CONCAT(i.ingredient_id SEPARATOR ',') " +
                     " FROM recipe_ingredients ri JOIN ingredients i ON ri.ingredient_id = i.ingredient_id " +
                     " WHERE ri.recipe_id = r.recipe_id) AS ingredient_ids " +
                     "FROM recipes r " +
                     "LEFT JOIN curated_recipes c ON r.recipe_id = c.recipe_id " +
                     "LEFT JOIN recipe_images img ON r.recipe_id = img.recipe_id " +
                     "WHERE r.recipe_id = ?";
                     
        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
             
            stmt.setInt(1, recipeId);
            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next()) return mapRecipe(rs);
            }
        } catch (Exception e) {
            System.err.println("SQL Error in getRecipeById:");
            e.printStackTrace();
        }
        return null;
    }

    public List<Recipe> searchRecipes(String query, String tag) {
        List<Recipe> recipes = new ArrayList<>();
        
        StringBuilder sql = new StringBuilder(
            "SELECT r.*, COALESCE(img.image_path, r.img_src) AS final_image, " +
            "NULL AS recipe_yield, r.total_time AS timing, " +
            "(SELECT GROUP_CONCAT(TRIM(CONCAT(IFNULL(ri.quantity, ''), ' ', IFNULL(i.unit, ''), ' ', i.name)) SEPARATOR '\\n') " +
            " FROM recipe_ingredients ri JOIN ingredients i ON ri.ingredient_id = i.ingredient_id " +
            " WHERE ri.recipe_id = r.recipe_id) AS raw_ingredients, " +
            "(SELECT GROUP_CONCAT(i.ingredient_id SEPARATOR ',') " +
            " FROM recipe_ingredients ri JOIN ingredients i ON ri.ingredient_id = i.ingredient_id " +
            " WHERE ri.recipe_id = r.recipe_id) AS ingredient_ids " +
            "FROM recipes r " +
            "LEFT JOIN curated_recipes c ON r.recipe_id = c.recipe_id " +
            "LEFT JOIN recipe_images img ON r.recipe_id = img.recipe_id " +
            "WHERE 1=1 "
        );

        List<String> params = new ArrayList<>();

        if (query != null && !query.trim().isEmpty()) {
            sql.append("AND (LOWER(r.recipe_name) LIKE ? OR LOWER(c.ingredients) LIKE ?) ");
            params.add("%" + query.toLowerCase() + "%");
            params.add("%" + query.toLowerCase() + "%");
        }

        if (tag != null && !tag.trim().isEmpty()) {
            sql.append("AND (LOWER(c.course) LIKE ? OR LOWER(r.cuisine_path) LIKE ?) ");
            params.add("%" + tag.toLowerCase() + "%");
            params.add("%" + tag.toLowerCase() + "%");
        }

        sql.append("ORDER BY CAST(r.rating AS DECIMAL(3,1)) DESC LIMIT 50");

        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql.toString())) {
            
            for (int i = 0; i < params.size(); i++) {
                stmt.setString(i + 1, params.get(i));
            }

            try (ResultSet rs = stmt.executeQuery()) {
                while (rs.next()) {
                    recipes.add(mapRecipe(rs));
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return recipes;
    }

    public List<Recipe> getMatchedRecipes(List<String> ingredients, String category, String recipeType) {
        List<Recipe> recipes = new ArrayList<>();
        
        StringBuilder sql = new StringBuilder(
            "SELECT r.*, COALESCE(img.image_path, r.img_src) AS final_image, " +
            "NULL AS recipe_yield, r.total_time AS timing, " +
            "(SELECT GROUP_CONCAT(TRIM(CONCAT(IFNULL(ri.quantity, ''), ' ', IFNULL(i.unit, ''), ' ', i.name)) SEPARATOR '\\n') " +
            " FROM recipe_ingredients ri JOIN ingredients i ON ri.ingredient_id = i.ingredient_id " +
            " WHERE ri.recipe_id = r.recipe_id) AS raw_ingredients, " +
            "(SELECT GROUP_CONCAT(i.ingredient_id SEPARATOR ',') " +
            " FROM recipe_ingredients ri JOIN ingredients i ON ri.ingredient_id = i.ingredient_id " +
            " WHERE ri.recipe_id = r.recipe_id) AS ingredient_ids " +
            "FROM recipes r " +
            "LEFT JOIN curated_recipes c ON r.recipe_id = c.recipe_id " +
            "LEFT JOIN recipe_images img ON r.recipe_id = img.recipe_id " +
            "WHERE 1=1 " 
        );

        List<String> params = new ArrayList<>();

        if (category != null && !category.trim().isEmpty()) {
            sql.append("AND (LOWER(c.course) LIKE ? OR LOWER(r.cuisine_path) LIKE ?) ");
            params.add("%" + category.toLowerCase() + "%");
            params.add("%" + category.toLowerCase() + "%");
        }

        if (recipeType != null && !recipeType.trim().isEmpty()) {
            sql.append("AND (LOWER(c.ingredient_family) LIKE ? OR LOWER(r.recipe_name) LIKE ?) ");
            params.add("%" + recipeType.toLowerCase() + "%");
            params.add("%" + recipeType.toLowerCase() + "%");
        }

        if (ingredients != null && !ingredients.isEmpty()) {
            for (String ing : ingredients) {
                sql.append("AND LOWER(c.ingredients) LIKE ? ");
                params.add("%" + ing.toLowerCase() + "%");
            }
        }

        sql.append("ORDER BY CAST(r.rating AS DECIMAL(3,1)) DESC LIMIT 50");

        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql.toString())) {
             
            for (int i = 0; i < params.size(); i++) {
                stmt.setString(i + 1, params.get(i));
            }

            try (ResultSet rs = stmt.executeQuery()) {
                while (rs.next()) {
                    recipes.add(mapRecipe(rs));
                }
            }
        } catch (Exception e) {
            System.err.println("SQL Error in getMatchedRecipes:");
            e.printStackTrace();
        }
        return recipes;
    }

    private Recipe mapRecipe(ResultSet rs) throws SQLException {
        Recipe recipe = new Recipe();
        recipe.setRecipeId(rs.getInt("recipe_id"));
        recipe.setSourceIndex(rs.getInt("source_index"));
        recipe.setRecipeName(rs.getString("recipe_name"));
        recipe.setPrepTime(rs.getString("prep_time"));
        recipe.setCookTime(rs.getString("cook_time"));
        recipe.setTotalTime(rs.getString("total_time"));
        recipe.setServings(rs.getString("servings"));
        
        recipe.setIngredients(rs.getString("raw_ingredients"));
        recipe.setIngredientIds(rs.getString("ingredient_ids"));
        
        recipe.setDirections(rs.getString("directions"));
        recipe.setRating(rs.getDouble("rating")); 
        recipe.setSourceUrl(rs.getString("source_url"));
        recipe.setCuisinePath(rs.getString("cuisine_path"));
        recipe.setNutrition(rs.getString("nutrition"));
        recipe.setTiming(rs.getString("timing"));
        
        String mappedImage = rs.getString("final_image");
        if (mappedImage != null && !mappedImage.isBlank()) {
            recipe.setImgSrc(mappedImage);
        }
        
        return recipe;
    }
}