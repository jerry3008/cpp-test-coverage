#ifndef ORDER_PROCESSOR_HPP_
#define ORDER_PROCESSOR_HPP_

#include <vector>
#include <chrono>

class OrderItem {
public:
    double price;
    int quantity;

    OrderItem(double p = 0.0, int q = 0) : price(p), quantity(q) {}
};

class Order {
public:
    std::vector<OrderItem> items;
    double order_total;
    std::chrono::system_clock::time_point processed_at;

    Order() : order_total(0.0) {}
};

class OrderProcessor {
public:
    bool process_order(Order& order);

private:
    double default_total_calculation(const std::vector<OrderItem>& items);
   
};
#endif  // ORDER_PROCESSOR_HPP_