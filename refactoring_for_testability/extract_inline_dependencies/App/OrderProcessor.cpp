#include "OrderProcessor.hpp"
#include "Dependencies.hpp"
#include <iostream>
#include <ctime>

// TODO: Add constructor to initialize the class fields
// TODO: Add destructor to clean up the class fields
OrderProcessor::OrderProcessor() 
        : DBC(new DatabaseConnection()), 
        PG(new PaymentGateway()) {}

    OrderProcessor::~OrderProcessor() {
        delete DBC;
        delete PG;
    }
bool OrderProcessor::process_order(Order& order) {
    // TODO: Remove these local variables and use the class fields instead
    
    try {
        Customer customer = DBC->get_customer_by_id(order.customer_id);
        if (customer.id == -1) return false;

        double total_amount = 0;
        for (const auto& item : order.items) {
            Product product = DBC->get_product_by_id(item.product_id);
            if (product.id == -1) continue;

            double item_price = product.price * item.quantity;
            total_amount += item_price;
        }

        PaymentResult payment_result = PG ->process_payment(total_amount);
        if (!payment_result.success) return false;

        DBC->update_order_status(order.id, "Paid");
        order.processed_at = std::time(nullptr);
        order.order_total = total_amount;

        return true;
    } catch (const std::exception& ex) {
        std::cout << "Error processing order: " << ex.what() << std::endl;
        return false;
    }
}