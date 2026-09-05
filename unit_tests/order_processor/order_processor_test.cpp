#include <gtest/gtest.h>
#include "OrderProcessor.hpp"

class OrderProcessorTests : public ::testing::Test {
protected:
    OrderProcessor processor;
};

TEST_F(OrderProcessorTests, ProcessOrder_WithSingleItem_CalculatesTotalCorrectly) 
{
    Order order;
    order.items.push_back(OrderItem{10.00, 2});
    
    bool result = processor.process_order(order);
    
    EXPECT_TRUE(result);
    
    EXPECT_DOUBLE_EQ(20.00, order.order_total);
    // TODO: Arrange - Create an order with a single item with a price of 10.00 and a quantity of 2
    // TODO: Act - Call the process_order method on the order
    // TODO: Assert - Verify the result is true and the order total is 20.00
}