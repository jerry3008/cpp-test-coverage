#ifndef ORDER_PROCESSOR_HPP_
#define ORDER_PROCESSOR_HPP_

#include <functional>
#include <vector>
#include <chrono>
// TODO: Include functional header for std::function

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
    bool process_order(Order& order, std::function<double(const std::vector<OrderItem>&)> calculate_total = nullptr);

private:
    double default_total_calculation(const std::vector<OrderItem>& items);
};

#endif  // ORDER_PROCESSOR_HPP_