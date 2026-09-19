#include "OrderDatabase.hpp"

class OrderProcessor {
private:
    // TODO: Change order_database_ field type from OrderDatabase to IOrderDatabase
    IOrderDatabase* order_database_;

public:

    OrderProcessor(IOrderDatabase* iod) : order_database_(iod ? iod : new OrderDatabase()){}
    // TODO: Add a constructor that takes an IOrderDatabase parameter (nullable)
    // TODO: In the constructor, set order_database_ to the parameter if not null, otherwise new OrderDatabase()

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