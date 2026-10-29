#include "OrderProcessor.hpp"
#include <iostream>

OrderProcessor::OrderProcessor(
    std::shared_ptr<IDatabaseConnection> db_connection,
    std::shared_ptr<IEmailService> email_service,
    std::shared_ptr<IPaymentGateway> payment_gateway)
    : db_connection_(std::move(db_connection)),
      email_service_(std::move(email_service)),
      payment_gateway_(std::move(payment_gateway)) {
    if (!db_connection_) throw std::invalid_argument("db_connection");
    if (!email_service_) throw std::invalid_argument("email_service");
    if (!payment_gateway_) throw std::invalid_argument("payment_gateway");
}

bool OrderProcessor::process_order(Order& order) {
    try {
        auto customer = get_customer(order.customer_id);
        if (!customer) return false;

        double total_amount = calculate_order_total(order.items, customer->is_premium);

        // TODO: Replace this payment processing logic with a call to the new process_payment method
        auto payment_result = process_payment(total_amount);
        if (!payment_result) return false;

        db_connection_->update_order_status(order.id, "Paid");
        order.processed_at = std::chrono::system_clock::now();
        email_service_->send_order_confirmation(customer->email, order.id, total_amount);

        return true;
    }
    catch (const std::exception& ex) {
        std::cout << "Error processing order: " << ex.what() << std::endl;
        return false;
    }
}

std::unique_ptr<Customer> OrderProcessor::get_customer(int customer_id) {
    return db_connection_->get_customer_by_id(customer_id);
}

double OrderProcessor::calculate_order_total(const std::vector<OrderItem>& items, bool is_premium_customer) {
    double total_amount = 0.0;
    for (const auto& item : items) {
        auto product = db_connection_->get_product_by_id(item.product_id);
        if (!product) continue;

        double item_price = product->price * item.quantity;
        if (is_premium_customer) {
            item_price *= 0.9;
        }
        total_amount += item_price;
    }
    return total_amount;
}

bool  OrderProcessor:: process_payment(double amount)
{
    auto payment_result = payment_gateway_->process_payment(amount);
    return payment_result.success;
};
