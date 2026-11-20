#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <vector>
#include <string>

class ShoppingCart {
public:
    struct Product {
        std::string id;
        std::string name;
        double price;

        Product(std::string id, std::string name, double price)
            : id(id), name(name), price(price) {}
    };

    struct CartItem {
        Product product;
        int quantity;

        CartItem(const Product& product, int quantity)
            : product(product), quantity(quantity) {}
    };

    ShoppingCart() = default;
    int getItemCount() const;
    double getTotal() const;
    void addItem(const Product &product, int quantity = 1);
    // TODO: Add a removeItem method that takes an item id as parameter
    // - Method should be declared as: void removeItem(const std::string& id);
    // - This method will be used to remove one quantity of an item from the cart
    // - If the item has multiple quantities, only reduce the quantity by 1
    // - If there's only one of the item, remove it completely from the items vector
    void removeItem(const std::string& id);

private:
    std::vector<CartItem> items;
};

#endif  // MAIN_HPP_