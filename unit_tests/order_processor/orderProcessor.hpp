#ifndef SOLUTION_HPP_
#define SOLUTION_HPP_

#include <vector>

enum class OrderStatus {
    Pending,
    Approved,
    Rejected
};

enum class ShippingMethod {
    Standard,
    Express,
    Freight
};

struct OrderItem {
    double price;
    int quantity;
    bool is_large_item = false;
};

struct Order {
    std::vector<OrderItem> items;
    double order_total = 0;
    bool has_bulk_discount = false;
    ShippingMethod shipping_method = ShippingMethod::Standard;
    OrderStatus status = OrderStatus::Pending;
};

class OrderProcessor {
public:
    static constexpr double BULK_ORDER_THRESHOLD = 1000.0;
    static constexpr double BULK_ORDER_DISCOUNT = 0.1; // 10% discount
    static constexpr int MAX_ITEMS_PER_ORDER = 50;

    bool process_order(Order& order);

private:
    ShippingMethod determine_shipping_method(const std::vector<OrderItem>& items);
};

#endif  // SOLUTION_HPP_