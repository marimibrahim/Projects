import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class ShoppingListDAO extends AbstractDAO {
    
    public boolean addIngredientToList(int userId, int ingredientId) {
        String sql = "INSERT INTO shopping_list (user_id, ingredient_id, is_checked) VALUES (?, ?, FALSE)";
        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, userId);
            stmt.setInt(2, ingredientId);
            return stmt.executeUpdate() > 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean clearList(int userId) {
        String sql = "DELETE FROM shopping_list WHERE user_id = ?";
        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, userId);
            return stmt.executeUpdate() >= 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public List<ShoppingListRecord> getShoppingList(int userId) {
        List<ShoppingListRecord> list = new ArrayList<>();
        String sql = "SELECT sl.item_id, sl.is_checked, i.name, i.unit FROM shopping_list sl JOIN ingredients i ON sl.ingredient_id = i.ingredient_id WHERE sl.user_id = ?";
        try (Connection conn = getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, userId);
            try (ResultSet rs = stmt.executeQuery()) {
                while (rs.next()) {
                    ShoppingListRecord record = new ShoppingListRecord();
                    record.setItemId(rs.getInt("item_id"));
                    record.setName(rs.getString("name"));
                    record.setUnit(rs.getString("unit"));
                    record.setChecked(rs.getBoolean("is_checked"));
                    list.add(record);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return list;
    }
}