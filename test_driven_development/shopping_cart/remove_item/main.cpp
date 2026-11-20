#include "../src/main.hpp"
#include <algorithm>

int ShoppingCart::getItemCount() const {
    int itemCount = 0;
    for (const auto& item : items) {
        itemCount += item.quantity;
    }
    return itemCount;
}

double ShoppingCart::getTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.product.price * item.quantity;
    }
    return total;
}

void ShoppingCart::addItem(const Product& product, int quantity) {
    items.push_back(CartItem(product, quantity));
}

// TODO: Implement the removeItem method
// - Find the item with the matching id in the items vector
// - If the item's quantity is greater than 1, decrement the quantity
// - If the item's quantity is 1, remove the item from the vector entirely
// - If the item isn't found, do nothing
// - Use iterators to safely navigate and modify the vector during traversal
void ShoppingCart::removeItem(const std::string& id)
{
    for (auto it = items.begin(); it != items.end(); ++it) 
    {
        if (it->product.id == id) 
        {
            if (it->quantity > 1) 
            {
                it->quantity -= 1;
            } else 
            {
                items.erase(it);
            }
            // adjust quantity or erase
            break;
        }
    }
}