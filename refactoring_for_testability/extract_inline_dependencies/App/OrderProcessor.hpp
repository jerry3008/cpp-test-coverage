#ifndef ORDER_PROCESSOR_HPP_
#define ORDER_PROCESSOR_HPP_

#include <vector>
#include <ctime>

// TODO: Add forward declarations for DatabaseConnection and PaymentGateway
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
    // TODO: Add private fields for DatabaseConnection and PaymentGateway
    DatabaseConnection* DBC;
    PaymentGateway* PG;
public:

    OrderProcessor();
    ~OrderProcessor();
    // TODO: Add constructor and destructor
    bool process_order(Order& order);
};

#endif  // ORDER_PROCESSOR_HPP_