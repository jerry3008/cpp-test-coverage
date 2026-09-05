#ifndef SOLUTION_HPP_
#define SOLUTION_HPP_

#include <vector>
#include <ctime>

struct OrderItem {
    double price;
    int quantity;
};

struct Order {
    std::vector<OrderItem> items;
    double order_total;
    std::time_t processed_at;
};

class OrderProcessor {
public:
    bool process_order(Order& order);
};

#endif  // SOLUTION_HPP_