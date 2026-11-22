#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <string>
#include <unordered_map>
#include <stdexcept>

class ShoppingCart {
public:
    class ItemNotFoundException : public std::runtime_error {
    public:
        explicit ItemNotFoundException(const std::string& message)
            : std::runtime_error(message) {}
    };

    class InvalidOperationException : public std::runtime_error {
    public:
        explicit InvalidOperationException(const std::string& message)
            : std::runtime_error(message) {}
    };

    struct Product {
        std::string Id;
        std::string Name;
        int Price;

        // Default constructor
        Product() : Id(""), Name(""), Price(0) {}

        Product(const std::string& id, const std::string& name, int price)
            : Id(id), Name(name), Price(price) {}
    };

    struct CartItem : public Product {
        int Quantity;

        // Default constructor
        CartItem() : Product(), Quantity(0) {}

        CartItem(const Product& product, int quantity)
            : Product(product), Quantity(quantity) {}
    };

    void AddItem(const Product& product, int quantity = 1);
    int GetItemCount();
    int GetTotal();
    void RemoveItem(const std::string& id);
    void ApplyDiscount(double percentage);
    void Clear();
    void UpdateQuantity(const std::string& id, int quantity);
    CartItem GetItem(const std::string& id);
    
    
    // TODO: Add the GetItem method declaration
    // The method should:
    // 1. Accept a string ID parameter
    // 2. Return a CartItem object
    // 3. Throw ItemNotFoundException if the item doesn't exist in the cart

private:
    static constexpr double BULK_DISCOUNT_THRESHOLD = 150.0;
    static constexpr double BULK_DISCOUNT_PERCENTAGE = 0.10;
    static constexpr int MAX_QUANTITY = 10;
    
    std::unordered_map<std::string, CartItem> items;
    double percentageDiscount = 0;
};

#endif  // MAIN_HPP_