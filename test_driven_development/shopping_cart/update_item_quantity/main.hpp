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
        std::string Id;
        std::string Name;
        double Price;

        // Default constructor
        Product() : Id(""), Name(""), Price(0) {}
        
        Product(const std::string& id, const std::string& name, double price)
            : Id(id), Name(name), Price(price) {}
    };

    class CartItem : public Product {
    public:
        int Quantity;
        
        // Default constructor
        CartItem() : Product(), Quantity(0) {}

        CartItem(const Product& product, int quantity)
            : Product(product), Quantity(quantity) {}
    };

    ShoppingCart();

    int GetItemCount() const;
    double GetTotal() const;
    void AddItem(const Product& product, int quantity = 1);
    void RemoveItem(const std::string& id);
    void ApplyDiscount(double percentage);
    void Clear();
    void UpdateQuantity(const std::string& id, int quantity);

private:
    const double BULK_DISCOUNT_THRESHOLD = 150.0;
    const double BULK_DISCOUNT_PERCENTAGE = 0.10;

    std::unordered_map<std::string, CartItem> items;
    double percentageDiscount;
};

#endif // MAIN_HPP_