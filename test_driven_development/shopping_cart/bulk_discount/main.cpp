#include "../src/main.hpp"
#include <numeric>

int ShoppingCart::GetItemCount() const {
    int itemCount = 0;
    for (const auto& kv : items) {
        itemCount += kv.second.quantity;
    }
    return itemCount;
}

int ShoppingCart::GetTotal() const {
    // TODO: Implement bulk discount functionality:
    // 1. Calculate the subtotal from all items
    // 2. If subtotal > BULK_DISCOUNT_THRESHOLD (150), apply BULK_DISCOUNT_PERCENTAGE (10%)
    // 3. Apply any percentage discount previously set
    // 4. Return the final total after all discounts
    int subtotal = 0;
    
    for (const auto& kv : items) {
        subtotal += kv.second.price * kv.second.quantity;
        
    }
    if(subtotal > BULK_DISCOUNT_THRESHOLD)
    {
        subtotal -= static_cast<int>(subtotal * BULK_DISCOUNT_PERCENTAGE);
    }
    return static_cast<int>(subtotal * (1 - percentageDiscount / 100.0));
}

void ShoppingCart::AddItem(const Product& product, int quantity) {
    items[product.id] = CartItem(product, quantity);
}

void ShoppingCart::RemoveItem(const std::string& id) {
    if (items.find(id) == items.end()) {
        throw ItemNotFoundException("Item not found");
    }

    CartItem& item = items[id];
    if (item.quantity > 1) {
        item.quantity -= 1;
    } else {
        items.erase(id);
    }
}

void ShoppingCart::ApplyDiscount(double percentage) {
    percentageDiscount = percentage;
}