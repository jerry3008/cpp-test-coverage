#include "Dependencies.hpp"
#include <iostream>

Customer DatabaseConnection::get_customer_by_id(int id) {
    std::cout << "Getting customer with ID: " << id << std::endl;
    return Customer{id};
}

Product DatabaseConnection::get_product_by_id(int id) {
    std::cout << "Getting product with ID: " << id << std::endl;
    return Product{id, 10.00};
}

void DatabaseConnection::update_order_status(int order_id, const std::string& status) {
    std::cout << "Updating order " << order_id << " status to: " << status << std::endl;
}

PaymentResult PaymentGateway::process_payment(double amount) {
    std::cout << "Processing payment for amount: $" << amount << std::endl;
    return PaymentResult{true};
}