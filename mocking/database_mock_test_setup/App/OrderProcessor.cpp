#include "OrderDatabase.hpp"

class OrderProcessor {
private:
    IOrderDatabase* order_database_;

public:
    OrderProcessor(IOrderDatabase* order_database = nullptr)
        : order_database_(order_database ? order_database : new OrderDatabase()) {}

    bool UpdateOrderDate(int order_id) {
        try {
            Order order = order_database_->GetOrderById(order_id);
            if (order.id == 0)
                return false;

            order.last_order_date = "2023-10-01"; // Example date
            order_database_->UpdateOrder(order);
            return true;
        } catch (...) {
            return false;
        }
    }
};