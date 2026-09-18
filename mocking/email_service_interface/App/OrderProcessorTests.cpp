#include "OrderProcessor.hpp"
#include <gtest/gtest.h>


class MockEmailService : public IEmailService  {
public:
    void SendOrderConfirmation(const Order& order) override 
    {
        // Mock implementation
    }
};

TEST(OrderProcessorTests, ProcessOrder_WithSingleItem_CalculatesTotalCorrectly) {
    OrderProcessor processor;
    Order order;
    order.items.push_back({10.00, 2});

    bool result = processor.ProcessOrder(order);

    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(20.00, order.order_total);
}

TEST(OrderProcessorTests, ProcessOrder_WithMultipleItems_CalculatesTotalCorrectly) {
    OrderProcessor processor;
    Order order;
    order.items.push_back({10.00, 2});
    order.items.push_back({15.00, 3});
    order.items.push_back({5.00, 1});

    bool result = processor.ProcessOrder(order);

    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(70.00, order.order_total);
}