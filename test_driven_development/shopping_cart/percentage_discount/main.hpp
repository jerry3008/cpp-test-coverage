#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <string>
#include <unordered_map>
#include <stdexcept>

class ShoppingCart {
public:
    class ItemNotFoundException : public std::exception {
    private:
        std::string message;
    public:
        explicit ItemNotFoundException(const std::string& msg) : message(msg) {}
        const char* what() const noexcept override { return message.c_str(); }
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

    struct CartItem {
        Product product;
        int quantity;
        
        // Default constructor
        CartItem() : product(), quantity(1) {}
        
        CartItem(const Product& prod, int qty) : product(prod), quantity(qty) {}
    };

private:
    std::unordered_map<std::string, CartItem> items;
    double  perDiscount = 0.0; 
    // TODO: Add a member variable to store the percentage discount

public:
    int GetItemCount();
    int GetTotal(); // TODO: Update to account for percentage discount
    void AddItem(const Product& product, int quantity = 1);
    void RemoveItem(const std::string& id);
    
    void ApplyDiscount(double perDiscount_);
    // TODO: Implement ApplyDiscount method to apply a percentage discount to the total
};

#endif  // MAIN_HPP_