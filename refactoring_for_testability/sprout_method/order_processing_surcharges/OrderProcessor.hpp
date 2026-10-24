#ifndef SOLUTION_HPP_
#define SOLUTION_HPP_

#include <vector>
#include <chrono>

struct OrderItem {
    double price;
    int quantity;
};

struct Order {
    std::vector<OrderItem> items;
    std::chrono::system_clock::time_point processed_at;
    double order_total = 0.0;
    double surcharge_amount = 0.0;
};

class OrderProcessor {
public:
    bool process_order(Order& order);
    bool process_order_with_surcharge(Order& order, double surcharge_percentage);
    
};

#endif  // SOLUTION_HPP_