#ifndef ORDER_DATABASE_HPP_
#define ORDER_DATABASE_HPP_

#include <iostream>

class Order {
public:
    int id;
    std::string name;
    std::string email;
    std::string last_order_date;
};

class IOrderDatabase {
public:
    virtual Order GetOrderById(int order_id) = 0;
    virtual void UpdateOrder(const Order& order) = 0;
    virtual ~IOrderDatabase() = default;
};

class OrderDatabase : public IOrderDatabase {
public:
    Order GetOrderById(int order_id) override {
        std::cout << "[Database Operation] Should not happen in tests!" << std::endl;
        return Order{order_id};
    }

    void UpdateOrder(const Order& order) override {
        std::cout << "[Database Operation] Should not happen in tests!" << std::endl;
    }
};

#endif  // ORDER_DATABASE_HPP_