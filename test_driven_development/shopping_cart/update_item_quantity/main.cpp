#include "../src/main.hpp"

ShoppingCart::ShoppingCart() : percentageDiscount(0) {}

int ShoppingCart::GetItemCount() const {
    int totalQuantity = 0;
    for (const auto& pair : items) {
        totalQuantity += pair.second.Quantity;
    }
    return totalQuantity;
}

double ShoppingCart::GetTotal() const {
    double subtotal = 0;
    for (const auto& pair : items) {
        subtotal += pair.second.Price * pair.second.Quantity;
    }

    if (subtotal > BULK_DISCOUNT_THRESHOLD) {
        subtotal -= subtotal * BULK_DISCOUNT_PERCENTAGE;
    }
    
    return subtotal * (1 - percentageDiscount / 100.0);
}

void ShoppingCart::AddItem(const Product& product, int quantity) {
    items[product.Id] = CartItem(product, quantity);
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

void ShoppingCart::UpdateQuantity(const std::string& id, int quantity) 
{
    if(!items.empty())
    {
        auto idx = items.find(id);
        if(idx != items.end())
        {
            idx->second.Quantity = quantity;
        }
    };
}

