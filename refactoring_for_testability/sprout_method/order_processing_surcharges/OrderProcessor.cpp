#include "OrderProcessor.hpp"
#include <stdexcept>

bool OrderProcessor::process_order(Order& order) {
    double total_amount = 0.0;
    for (const auto& item : order.items) {
        double item_price = item.price * item.quantity;
        total_amount += item_price;
    }
    
    order.processed_at = std::chrono::system_clock::now();
    order.order_total = total_amount;
    return true;
}


bool OrderProcessor::process_order_with_surcharge(Order& order, double surcharge_percentage) 
{
    if(surcharge_percentage < 0)
    {
        throw std::invalid_argument("Surcharge percentage cannot be negative");
    }
    process_order(order);
    double surcharge_amount = order.order_total * (surcharge_percentage / 100.0);
   
    
    order.processed_at = std::chrono::system_clock::now();
    order.order_total += surcharge_amount;
    order.surcharge_amount = surcharge_amount;
    return true;
}