#include "OrderProcessor.hpp"
#include <algorithm>
#include <numeric> // Include this header for std::accumulate

bool OrderProcessor::process_order(Order& order) {
    if (order.items.empty())
        return false;

    if (order.items.size() > MAX_ITEMS_PER_ORDER)
        return false;

    double total_amount = 0;
    for (const auto& item : order.items) {
        double item_price = item.price * item.quantity;
        total_amount += item_price;
    }

    // Apply bulk order discount if applicable
    if (total_amount >= BULK_ORDER_THRESHOLD) {
        total_amount *= (1 - BULK_ORDER_DISCOUNT);
        order.has_bulk_discount = true;
    }

    // Determine shipping method based on order characteristics
    order.shipping_method = determine_shipping_method(order.items);

    order.order_total = total_amount;
    order.status = total_amount > 0 ? OrderStatus::Approved : OrderStatus::Rejected;

    return order.status == OrderStatus::Approved;
}

ShippingMethod OrderProcessor::determine_shipping_method(const std::vector<OrderItem>& items) {
    bool has_large_items = std::any_of(items.begin(), items.end(), [](const OrderItem& item) {
        return item.is_large_item;
    });

    if (has_large_items)
        return ShippingMethod::Freight;
    else if (std::accumulate(items.begin(), items.end(), 0, [](int sum, const OrderItem& item) {
        return sum + item.quantity;
    }) > 10)
        return ShippingMethod::Express;
    else
        return ShippingMethod::Standard;
}