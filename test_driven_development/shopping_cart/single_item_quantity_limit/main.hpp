#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <string>
#include <unordered_map>
#include <stdexcept>

class ShoppingCart {
public:
    class ItemNotFoundException : public std::runtime_error {
    public:
        explicit ItemNotFoundException(const std::string& message);
    };
    class InvalidOperationException : public std::runtime_error
    {
        public:
        explicit InvalidOperationException(const std::string& message);
    };

    class Product {
    public:
        std::string Id;
        std::string Name;
        int Price;

        // Default constructor
        Product() : Id(""), Name(""), Price(0) {}

        Product(const std::string& id, const std::string& name, int price);
    };

    class CartItem : public Product {
    public:
        int Quantity;

        // Default constructor
        CartItem() : Product(), Quantity(0) {}

        CartItem(const Product& product, int quantity);
    };

    ShoppingCart();

    int GetItemCount() const;
    int GetTotal() const;
    void AddItem(const Product& product, int quantity = 1);
    void RemoveItem(const std::string& id);
    void ApplyDiscount(double percentage);
    void Clear();
    void UpdateQuantity(const std::string& id, int quantity);

private:
    static constexpr double BULK_DISCOUNT_THRESHOLD = 150;
    static constexpr double BULK_DISCOUNT_PERCENTAGE = 0.10;
     static constexpr int MAX_QUANTITY = 10;

    
    std::unordered_map<std::string, CartItem> items;
    double percentageDiscount;
};

#endif  // MAIN_HPP_