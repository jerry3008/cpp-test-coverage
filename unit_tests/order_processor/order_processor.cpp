#include "OrderProcessor.hpp"

bool OrderProcessor::process_order(Order& order) {
    double total_amount = 0;
    for (const auto& item : order.items) {
        double item_price = item.price * item.quantity;
        total_amount += item_price;
    }

    order.processed_at = std::chrono::system_clock::now();
    order.order_total = total_amount;
    return true;
}