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
    // TODO: Add an optional parameter 'calculation_mode' with default value OrderCalculationMode::Normal
    bool process_order(Order& order, OrderCalculationMode calculation_mode = OrderCalculationMode::Normal);

private:
    double calculate_total(double total_amount, OrderCalculationMode calculation_mode);
};

#endif // ORDER_PROCESSOR_HPP_