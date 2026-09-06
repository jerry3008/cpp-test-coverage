#include <gtest/gtest.h>
#include "OrderProcessor.hpp"

class OrderProcessorTests : public ::testing::Test {
protected:
    OrderProcessor processor;
};

TEST_F(OrderProcessorTests, ProcessOrder_WithSingleItem_CalculatesTotalCorrectly) {
    // Arrange
    Order order;
    order.items = {
        {10.00, 2}
    };

    // Act
    bool result = processor.process_order(order);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_DOUBLE_EQ(20.00, order.order_total);
}

TEST_F(OrderProcessorTests, ProcessOrder_WithMultipleItems_CalculatesTotalCorrectly) {
    // TODO: Arrange - Create an order with multiple items:
    // 1. Price 10.00, Quantity 2
    // 2. Price 15.00, Quantity 3
    // 3. Price 5.00, Quantity 1
    Order order;
    order.items = {
        {10.00, 2},
        {15.00, 3},
        {5.00, 1}
    };
    

    // TODO: Act - Call the process_order method on the order

     bool result = processor.process_order(order);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_DOUBLE_EQ(70.00, order.order_total);
}