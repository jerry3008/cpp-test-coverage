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

// TODO: Create interface IOrderDatabase with two methods:
class IOrderDatabase
{
  
  public:
    virtual Order GetOrderById(int order_id) = 0;
    virtual  void UpdateOrder(const Order& od) = 0;
    virtual ~IOrderDatabase() = default;
};
// - GetOrderById that takes an int order_id parameter and returns Order
// - UpdateOrder that takes a const Order& parameter and returns void

// TODO: Make OrderDatabase implement IOrderDatabase interface
class OrderDatabase : public IOrderDatabase
{
    public:
        Order GetOrderById(int order_id) override {
            std::cout << "[Database Operation] Should not happen in tests!" << std::endl;
            return Order{order_id};
        }

        void UpdateOrder(const Order& order) override{
            std::cout << "[Database Operation] Should not happen in tests!" << std::endl;
        }
};

#endif  // ORDER_DATABASE_HPP_