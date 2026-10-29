#ifndef SOLUTION_HPP_
#define SOLUTION_HPP_

#include <string>
#include <vector>
#include <chrono>
#include <memory>

class Customer {
public:
    std::string email;
    bool is_premium;
};

class Product {
public:
    int id;
    double price;
};

struct OrderItem {
    int product_id;
    int quantity;
};

struct Order {
    int id;
    int customer_id;
    std::vector<OrderItem> items;
    std::chrono::system_clock::time_point processed_at;
};

struct PaymentResult {
    bool success;
};

class IDatabaseConnection {
public:
    virtual ~IDatabaseConnection() = default;
    virtual std::unique_ptr<Customer> get_customer_by_id(int customer_id) = 0;
    virtual std::unique_ptr<Product> get_product_by_id(int product_id) = 0;
    virtual void update_order_status(int order_id, const std::string& status) = 0;
};

class IEmailService {
public:
    virtual ~IEmailService() = default;
    virtual void send_order_confirmation(const std::string& email, int order_id, double total_amount) = 0;
};

class IPaymentGateway {
public:
    virtual ~IPaymentGateway() = default;
    virtual PaymentResult process_payment(double amount) = 0;
};

class OrderProcessor {
public:
    OrderProcessor(
        std::shared_ptr<IDatabaseConnection> db_connection,
        std::shared_ptr<IEmailService> email_service,
        std::shared_ptr<IPaymentGateway> payment_gateway);
    
    bool process_order(Order& order);

private:
    std::shared_ptr<IDatabaseConnection> db_connection_;
    std::shared_ptr<IEmailService> email_service_;
    std::shared_ptr<IPaymentGateway> payment_gateway_;
    
    std::unique_ptr<Customer> get_customer(int customer_id);
    double calculate_order_total(const std::vector<OrderItem>& items, bool is_premium_customer);
    bool process_payment(double amount);
};

#endif  // SOLUTION_HPP_