#ifndef SOLUTION_HPP_
#define SOLUTION_HPP_

#include <vector>
#include <ctime>

class OrderItem {
public:
    double price;
    int quantity;
};

class Order {
public:
    std::vector<OrderItem> items;
    double order_total = 0.0;
    std::time_t processed_at = 0;
};



class IEmailService
{
    
    public:
    virtual void SendOrderConfirmation(const Order& order) = 0;
    virtual ~IEmailService() = default;
    
};
class EmailService : public IEmailService{
public:
    virtual ~EmailService() = default;
    virtual void SendOrderConfirmation(const Order& order);
};

class OrderProcessor {
public:

    OrderProcessor(IEmailService* iemail_service = nullptr);

    ~OrderProcessor();

    bool ProcessOrder(Order& order);

private:
    
    IEmailService* iemail_service_;
};

#endif  // SOLUTION_HPP_