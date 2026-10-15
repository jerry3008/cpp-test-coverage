#include <gtest/gtest.h>
#include "OrderProcessor.hpp"
#include <chrono>

TEST(OrderProcessorTests, ProcessOrder_CalculatesTotalCorrectly) {
    // Arrange
    OrderProcessor processor;
    Order order;
    order.items.push_back(OrderItem(10.5, 2));
    order.items.push_back(OrderItem(25.99, 1));

    // Act
    bool result = processor.process_order(order);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(46.99, order.order_total);  // 10.5 * 2 + 25.99 = 46.99
    
    auto now = std::chrono::system_clock::now();
    auto diff = now - order.processed_at;
    EXPECT_LT(std::chrono::duration_cast<std::chrono::seconds>(diff).count(), 1);  // ProcessedAt should be very recent
}