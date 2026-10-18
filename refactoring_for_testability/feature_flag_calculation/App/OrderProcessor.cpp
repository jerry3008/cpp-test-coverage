#include "OrderProcessor.hpp"
#include <ctime>

bool OrderProcessor::process_order(Order& order)
{
    double total_amount = 0;
    for (const auto& item : order.items)
    {
        double item_price = item.price * item.quantity;
        total_amount += item_price;
    }

    order.processed_at = std::time(nullptr);
    // TODO: Replace this line to use the calculate_total method with OrderCalculationMode::Normal
    order.order_total = total_amount;
    return true;
}


double OrderProcessor::calculate_total(double total_amount, OrderCalculationMode calculation_mode)
{
    switch (calculation_mode) 
    {
        case OrderCalculationMode::Discount:
        return total_amount * 0.9;
        case OrderCalculationMode::Surcharge:
        return total_amount * 1.15;
        default:
        return total_amount;
    }
}
