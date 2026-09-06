#include <gtest/gtest.h>
#include <vector>
#include <chrono>
#include "OrderProcessor.hpp"

class OrderProcessorTests : public ::testing::Test {
protected:
    OrderProcessor processor;
};

TEST_F(OrderProcessorTests, ProcessOrder_WithSingleItem_CalculatesTotalCorrectly) {
    // Arrange
    Order order;
    order.items.push_back(OrderItem{10.00, 2});

    // Act
    bool result = processor.process_order(order);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_DOUBLE_EQ(20.00, order.order_total);
}

TEST_F(OrderProcessorTests, ProcessOrder_WithMultipleItems_CalculatesTotalCorrectly) {
    // Arrange
    Order order;
    order.items.push_back(OrderItem{10.00, 2});
    order.items.push_back(OrderItem{15.00, 3});
    order.items.push_back(OrderItem{5.00, 1});

    // Act
    bool result = processor.process_order(order);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_DOUBLE_EQ(70.00, order.order_total);  // (10 * 2) + (15 * 3) + (5 * 1) = 70
}

TEST_F(OrderProcessorTests, ProcessOrder_WithEmptyItemsList_ReturnsZeroTotal) {
    // Arrange
    Order order;

    // Act
    bool result = processor.process_order(order);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_DOUBLE_EQ(0.0, order.order_total);
}

TEST_F(OrderProcessorTests, ProcessOrder_SetsProcessedAtToCurrentTime) {
    // TODO: Arrange - Create an order with a single item with a price of 10.00 and a quantity of 1
    // TODO: Capture the current time before processing

    // TODO: Act - Call the process_order method on the order
    // TODO: Capture the current time after processing

    // TODO: Assert - Verify the result is true
    // TODO: Assert - Verify the processed_at time is between the before and after processing times
        // Arrange
    Order order;
    order.items.push_back(OrderItem{10.00, 1});
    auto current_time = std::chrono::system_clock::now();

    // Act
    bool result = processor.process_order(order);
    auto current_time1 = std::chrono::system_clock::now();

    // Assert
    ASSERT_TRUE(result);
    ASSERT_TRUE(order.processed_at >= current_time);
    ASSERT_TRUE(order.processed_at <= current_time1);
    ASSERT_DOUBLE_EQ(10.00, order.order_total);
}