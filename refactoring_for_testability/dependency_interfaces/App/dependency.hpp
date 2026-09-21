#ifndef DEPENDENCIES_HPP_
#define DEPENDENCIES_HPP_

#include <string>

// TODO: Create an IDatabaseConnection abstract class with methods for get_customer_by_id, get_product_by_id, and update_order_status
// TODO: The interface should match the methods in the DatabaseConnection class

// TODO: Create an IPaymentGateway interface with a method for process_payment
// TODO: The interface should match the method in the PaymentGateway class

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
class IDatabaseConnection // TODO: Implement the IDatabaseConnection interface
{
    public:
       virtual  Customer get_customer_by_id(int id) = 0;
       virtual Product get_product_by_id(int id) = 0;
        virtual void update_order_status(int order_id, const std::string& status)= 0;
        virtual ~IDatabaseConnection() = default;
};

class IPaymentGateway // TODO: Implement the IPaymentGateway interface
{
public:
    virtual PaymentResult process_payment(double amount)= 0;
    virtual ~IPaymentGateway() = default;
};

class DatabaseConnection : public IDatabaseConnection // TODO: Implement the IDatabaseConnection interface
{
public:
    virtual Customer get_customer_by_id(int id) override;
    virtual Product get_product_by_id(int id) override;
    virtual void update_order_status(int order_id, const std::string& status) override;
};

class PaymentGateway : public IPaymentGateway // TODO: Implement the IPaymentGateway interface
{
public:
    virtual PaymentResult process_payment(double amount) override;
};



#endif  // DEPENDENCIES_HPP_