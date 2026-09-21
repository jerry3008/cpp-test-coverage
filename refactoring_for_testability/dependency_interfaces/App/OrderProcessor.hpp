#ifndef ORDER_PROCESSOR_HPP_
#define ORDER_PROCESSOR_HPP_

#include <vector>
#include <ctime>

class DatabaseConnection;
class PaymentGateway;

struct OrderItem {
    int product_id;
    int quantity;
};

struct Order {
    int id;
    int customer_id;
    std::vector<OrderItem> items;
    std::time_t processed_at;
    double order_total;

    Order() : processed_at(0), order_total(0.0) {}
};

class OrderProcessor {
private:
    DatabaseConnection* db_connection;
    PaymentGateway* payment_gateway;

public:
    OrderProcessor();
    ~OrderProcessor();
    bool process_order(Order& order);
};

#endif  // ORDER_PROCESSOR_HPP_