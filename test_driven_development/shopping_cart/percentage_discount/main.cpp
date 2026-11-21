#include "../src/main.hpp"
#include <numeric>

int ShoppingCart::GetItemCount() {
    int totalQuantity = 0;
    for (const auto& itemPair : items) {
        totalQuantity += itemPair.second.quantity;
    }
    return totalQuantity;
}

int ShoppingCart::GetTotal() {
    int subtotal = 0;
    for (const auto& itemPair : items) {
        subtotal += itemPair.second.product.Price * itemPair.second.quantity;
    }
        return subtotal* (1 - perDiscount / 100.0);
    // TODO: Apply the percentage discount to the subtotal
}

void ShoppingCart::AddItem(const Product& product, int quantity) {
    items[product.Id] = CartItem{product, quantity};
}

void ShoppingCart::RemoveItem(const std::string& id) {
    auto it = items.find(id);
    if (it == items.end()) {
        throw ItemNotFoundException("Item not found");
    }
    if (it->second.quantity > 1) {
        it->second.quantity--;
    } else {
        items.erase(it);
    }
}


void ShoppingCart::ApplyDiscount(double perDiscount_) {
    perDiscount = perDiscount_;
}
// TODO: Implement ApplyDiscount method to apply a percentage discount to the total