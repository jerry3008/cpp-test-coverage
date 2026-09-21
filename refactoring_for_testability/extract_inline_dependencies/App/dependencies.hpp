#ifndef DEPENDENCIES_HPP_
#define DEPENDENCIES_HPP_

#include <string>

struct Customer {
    int id;
};

struct Product {
    int id;
    double price;
};

struct PaymentResult {
    bool success;
};

class DatabaseConnection {
public:
    Customer get_customer_by_id(int id);
    Product get_product_by_id(int id);
    void update_order_status(int order_id, const std::string& status);
};

class PaymentGateway {
public:
    PaymentResult process_payment(double amount);
};

#endif  // DEPENDENCIES_HPP_