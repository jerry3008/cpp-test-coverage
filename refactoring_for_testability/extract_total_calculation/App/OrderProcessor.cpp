#include "OrderProcessor.hpp"
#include <chrono>

bool OrderProcessor::process_order(Order& order) {
    order.processed_at = std::chrono::system_clock::now();
    order.order_total = default_total_calculation(order.items);
    return true;
}

double OrderProcessor:: default_total_calculation(const std::vector<OrderItem>& items)
{
    // Calculate total amount
    double total_amount = 0.0;
    for (const auto& item : items) {
        double item_price = item.price * item.quantity;
        total_amount += item_price;
    }
    return  total_amount;
    
}
