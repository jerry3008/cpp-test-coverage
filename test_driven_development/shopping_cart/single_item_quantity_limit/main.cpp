#include "../src/main.hpp"
#include <stdexcept>

ShoppingCart::ShoppingCart() : percentageDiscount(0) {}

ShoppingCart::ItemNotFoundException::ItemNotFoundException(const std::string& message) : std::runtime_error(message) {}
ShoppingCart::InvalidOperationException::InvalidOperationException(const std::string& message) : std::runtime_error(message) {}

// TODO: Implement InvalidOperationException constructor similar to ItemNotFoundException

ShoppingCart::Product::Product(const std::string& id, const std::string& name, int price) : Id(id), Name(name), Price(price) {}

ShoppingCart::CartItem::CartItem(const Product& product, int quantity)
    : Product(product.Id, product.Name, product.Price), Quantity(quantity) {}

int ShoppingCart::GetItemCount() const {
    int totalQuantity = 0;
    for (const auto& item : items) {
        totalQuantity += item.second.Quantity;
    }
    return totalQuantity;
}

int ShoppingCart::GetTotal() const {
    int subtotal = 0;
    for (const auto& item : items) {
        subtotal += item.second.Price * item.second.Quantity;
    }

    // Apply bulk discount if applicable
    if (subtotal > BULK_DISCOUNT_THRESHOLD) {
        subtotal -= static_cast<int>(subtotal * BULK_DISCOUNT_PERCENTAGE);
    }

    return static_cast<int>(subtotal * (1 - percentageDiscount / 100));
}

void ShoppingCart::AddItem(const Product& product, int quantity) {
    
    if(quantity > MAX_QUANTITY)
    {
        throw InvalidOperationException("Maximum quantity exceeded");
    }else {
        items[product.Id] = CartItem(product, quantity);
    }
    
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