#include "OrderProcessor.hpp"
#include <iostream>


OrderProcessor::OrderProcessor(IEmailService* iemail_service)
    : iemail_service_(iemail_service ? iemail_service : new EmailService()) {}

OrderProcessor::~OrderProcessor() {
    if (iemail_service_) {
        delete iemail_service_;
    }
}

bool OrderProcessor::ProcessOrder(Order& order) {
    try {
        order.order_total = 0;
        for (const auto &item : order.items) {
            order.order_total += item.price * item.quantity;
        }
        order.processed_at = std::time(nullptr);
        if (iemail_service_) {
            iemail_service_->SendOrderConfirmation(order);
        }
        return true;
    } catch (const std::exception&) {
        return false;
    }
}


void EmailService::SendOrderConfirmation(const Order& order) {
    std::cout << "[Sending Email] This should not happen in tests!" << std::endl;
}