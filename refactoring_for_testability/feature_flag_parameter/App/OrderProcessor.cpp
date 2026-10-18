#include "OrderProcessor.hpp"
#include <ctime>

bool OrderProcessor::process_order(Order& order, OrderCalculationMode calculation_mode)
{
    double total_amount = 0;
    for (const auto& item : order.items)
    {
        double item_price = item.price * item.quantity;
        total_amount += item_price;
    }

    order.processed_at = std::time(nullptr);
    // TODO: Update this line to use the calculation_mode parameter instead of OrderCalculationMode::Normal
    order.order_total = calculate_total(total_amount, calculation_mode);
    return true;
}

double OrderProcessor::calculate_total(double total_amount, OrderCalculationMode calculation_mode)
{
    switch (calculation_mode)
    {
        case OrderCalculationMode::Discount:
            return total_amount * 0.9;  // 10% discount
        case OrderCalculationMode::Surcharge:
            return total_amount * 1.15;  // 15% surcharge
        default:
            return total_amount;  // Normal mode and all other cases
    }
}