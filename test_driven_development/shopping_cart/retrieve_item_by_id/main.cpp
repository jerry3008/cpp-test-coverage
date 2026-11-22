#include "../src/main.hpp"

void ShoppingCart::AddItem(const Product& product, int quantity) {
    if (quantity > MAX_QUANTITY) {
        throw InvalidOperationException("Maximum quantity exceeded");
    }
    items[product.Id] = CartItem(product, quantity);
}

int ShoppingCart::GetItemCount() {
    int count = 0;
    for (const auto& pair : items) {
        count += pair.second.Quantity;
    }
    return count;
}

int ShoppingCart::GetTotal() {
    int subtotal = 0;
    for (const auto& pair : items) {
        subtotal += pair.second.Price * pair.second.Quantity;
    }
    if (subtotal > BULK_DISCOUNT_THRESHOLD) {
        subtotal -= static_cast<int>(subtotal * BULK_DISCOUNT_PERCENTAGE);
    }
    return static_cast<int>(subtotal * (1 - percentageDiscount / 100.0));
}

void ShoppingCart::RemoveItem(const std::string& id) {
    auto it = items.find(id);
    if (it == items.end()) {
        throw ItemNotFoundException("Item not found");
    }
    if (it->second.Quantity > 1) {
        it->second.Quantity -= 1;
    } else {
        items.erase(it);
    }
}

void ShoppingCart::ApplyDiscount(double percentage) {
    percentageDiscount = percentage;
}

void ShoppingCart::Clear() {
    items.clear();
}

void ShoppingCart::UpdateQuantity(const std::string& id, int quantity) {
    auto it = items.find(id);
    if (it != items.end()) {
        it->second.Quantity = quantity;
    }
}


ShoppingCart::CartItem ShoppingCart::GetItem(const std::string& id)
{
    if(items.find(id) != items.end())
    {
        return items[id];
    }else {
      throw ItemNotFoundException("Item Not Found");
    }
}

// TODO: Implement the GetItem method
// The implementation should:
// 1. Find the item in the items map using the provided ID
// 2. If the item exists, return it
// 3. If the item doesn't exist, throw an ItemNotFoundException with an appropriate message
// Remember: Return value should be a CartItem containing product details and quantity