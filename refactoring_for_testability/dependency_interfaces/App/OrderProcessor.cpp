#include "OrderProcessor.hpp"
#include "Dependencies.hpp"
#include <iostream>
#include <ctime>

OrderProcessor::OrderProcessor() 
    : db_connection(new DatabaseConnection()), 
      payment_gateway(new PaymentGateway()) {
}

OrderProcessor::~OrderProcessor() {
    delete db_connection;
    delete payment_gateway;
}

bool OrderProcessor::process_order(Order& order) {
    try {
        Customer customer = db_connection->get_customer_by_id(order.customer_id);
        if (customer.id == -1) return false;

        double total_amount = 0;
        for (const auto& item : order.items) {
            Product product = db_connection->get_product_by_id(item.product_id);
            if (product.id == -1) continue;

            double item_price = product.price * item.quantity;
            total_amount += item_price;
        }

        PaymentResult payment_result = payment_gateway->process_payment(total_amount);
        if (!payment_result.success) return false;

        db_connection->update_order_status(order.id, "Paid");
        order.processed_at = std::time(nullptr);
        order.order_total = total_amount;

        return true;
    } catch (const std::exception& ex) {
        std::cout << "Error processing order: " << ex.what() << std::endl;
        return false;
    }
}