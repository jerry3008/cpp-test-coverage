#include "OrderProcessor.hpp"
#include <chrono>
#include <vector>

// TODO: Add a std::function<double(const std::vector<OrderItem>&)> parameter named calculate_total with default value nullptr
bool OrderProcessor::process_order(Order& order, std::function<double(const std::vector<OrderItem>&)> calculate_total) 
{
    auto total_amount_calculation = calculate_total ? calculate_total : [this](const std::vector<OrderItem>&items)
    {
        return this ->default_total_calculation(items);
    };

    order.processed_at = std::chrono::system_clock::now();
    order.order_total = total_amount_calculation(order.items);
    return true;
}

double OrderProcessor::default_total_calculation(const std::vector<OrderItem>& items) {
    double total_amount = 0.0;
    for (const auto& item : items) {
        double item_price = item.price * item.quantity;
        total_amount += item_price;
    }
    return total_amount;
}