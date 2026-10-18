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