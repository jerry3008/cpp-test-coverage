#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <string>
#include <unordered_map>
#include <stdexcept>

class ShoppingCart {
public:
    class ItemNotFoundException : public std::runtime_error {
    public:
        ItemNotFoundException(const std::string& message) : std::runtime_error(message) {}
    };

    class Product {
    public:
        std::string id;
        std::string name;
        int price;

        // Default constructor
        Product() : id(""), name(""), price(0) {}

        Product(const std::string& id, const std::string& name, int price)
            : id(id), name(name), price(price) {}
    };

    class CartItem : public Product {
    public:
        int quantity;

        // Default constructor
        CartItem() : Product(), quantity(0) {}

        CartItem(const Product& product, int quantity)
            : Product(product), quantity(quantity) {}
    };

    ShoppingCart() = default;

    int GetItemCount() const;
    int GetTotal() const;
    void AddItem(const Product& product, int quantity = 1);
    void RemoveItem(const std::string& id);
    void ApplyDiscount(double percentage);
    void  Clear();
    
private:
    const double BULK_DISCOUNT_THRESHOLD = 150;
    const double BULK_DISCOUNT_PERCENTAGE = 0.10;
    std::unordered_map<std::string, CartItem> items;
    double percentageDiscount = 0.0;
};

#endif  // MAIN_HPP_