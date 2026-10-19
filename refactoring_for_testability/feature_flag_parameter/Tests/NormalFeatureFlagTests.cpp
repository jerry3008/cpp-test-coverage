#include "OrderProcessor.hpp"
#include <gtest/gtest.h>

TEST(OrderProcessorTests, ProcessOrder_DefaultMode_UsesNormalCalculation)
{
    // Arrange
    OrderProcessor order_processor;
    Order order;
    
    OrderItem item1;
    item1.price = 10.0;
    item1.quantity = 2;
    
    OrderItem item2;
    item2.price = 5.0;
    item2.quantity = 3;
    
    order.items = {item1, item2};
    
    // Act
    order_processor.process_order(order);
    
    // Assert
    double expected_total = 10.0 * 2 + 5.0 * 3;
    ASSERT_DOUBLE_EQ(expected_total, order.order_total);
}

// TODO: Add a new test method called ProcessOrder_NormalMode_CalculatesCorrectTotal
// TODO: Create an OrderProcessor instance
// TODO: Create an Order with two items: one with price 10.0 and quantity 2, another with price 5.0 and quantity 3
// TODO: Call process_order with the order and explicitly pass OrderCalculationMode::Normal
// TODO: Calculate the expected total (10.0 * 2 + 5.0 * 3)
// TODO: Assert that order.order_total equals the expected total
// TODO: Assert that order.processed_at is not equal to 0 (default time_t value)

TEST(OrderProcessorTests, ProcessOrder_NormalMode_CalculatesCorrectTotal)
{
    // Arrange
    OrderProcessor order_processor;
    Order order;
    
    OrderItem item1;
    item1.price = 10.0;
    item1.quantity = 2;
    
    OrderItem item2;
    item2.price = 5.0;
    item2.quantity = 3;
    
    order.items = {item1, item2};
    
    // Act
    order_processor.process_order(order,  OrderCalculationMode::Normal);
    
    // Assert
    double expected_total = 10.0 * 2 + 5.0 * 3;
    ASSERT_DOUBLE_EQ(expected_total, order.order_total);
    ASSERT_NE(0, order.processed_at);
}