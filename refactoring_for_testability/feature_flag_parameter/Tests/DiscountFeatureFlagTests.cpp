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
    order_processor.process_order(order, OrderCalculationMode::Normal);
    
    // Assert
    double expected_total = 10.0 * 2 + 5.0 * 3;
    ASSERT_DOUBLE_EQ(expected_total, order.order_total);
    ASSERT_NE(0, order.processed_at);
}

// TODO: choose a meaningful name for your test function
// TODO: Create an OrderProcessor and an Order with two items: Price=10/Quantity=2 and Price=5/Quantity=3
// TODO: Call process_order with OrderCalculationMode::Discount
// TODO: Calculate the expected total by first calculating the base total (10*2 + 5*3) and then applying a 10% discount (multiply by 0.9)
// TODO: Assert that order.order_total equals the expected discounted total

TEST(OrderProcessorTests, ProcessOrder_DiscountMode_CalculatesCorrectTotal)
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
    order_processor.process_order(order, OrderCalculationMode::Discount);
    
    // Assert
    double base_total = 10.0 * 2 + 5.0 * 3;
    double expected_total = base_total * 0.9;
    ASSERT_DOUBLE_EQ(expected_total, order.order_total);
    ASSERT_NE(0, order.processed_at);
}