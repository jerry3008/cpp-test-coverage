#ifndef ORDER_PROCESSOR_HPP_
#define ORDER_PROCESSOR_HPP_

#include <vector>
#include <ctime>

// Enum to represent different calculation modes
enum class OrderCalculationMode
{
    Normal,
    Discount,
    Surcharge
};

class OrderItem
{
public:
    double price;
    int quantity;
};

class Order
{
public:
    std::vector<OrderItem> items;
    double order_total;
    std::time_t processed_at;
    
    Order() : order_total(0), processed_at(0) {}
};

class OrderProcessor
{
public:
    bool process_order(Order& order);

private:
    double calculate_total(double total_amount, OrderCalculationMode calculation_mode);
};

#endif // ORDER_PROCESSOR_HPP_