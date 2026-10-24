#include "OrderProcessor.hpp"
#include <gtest/gtest.h>
#include <thread>

class OrderProcessorTests : public ::testing::Test {
protected:
    OrderProcessor processor;
};

TEST_F(OrderProcessorTests, ProcessOrder_EmptyOrder_SetsZeroTotal) {
    // Arrange
    Order order;
    
    // Act
    bool result = processor.process_order(order);
    
    // Assert
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(0.0, order.order_total);
    auto now = std::chrono::system_clock::now();
    auto diff = now - order.processed_at;
    EXPECT_LT(std::chrono::duration_cast<std::chrono::seconds>(diff).count(), 1);
}

TEST_F(OrderProcessorTests, ProcessOrder_SingleItem_CalculatesTotalCorrectly) {
    // Arrange
    Order order;
    OrderItem item;
    item.price = 10.50;
    item.quantity = 2;
    order.items.push_back(item);
    
    // Act
    bool result = processor.process_order(order);
    
    // Assert
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(21.00, order.order_total);
    auto now = std::chrono::system_clock::now();
    auto diff = now - order.processed_at;
    EXPECT_LT(std::chrono::duration_cast<std::chrono::seconds>(diff).count(), 1);
}

TEST_F(OrderProcessorTests, ProcessOrder_MultipleItems_CalculatesTotalCorrectly) {
    // Arrange
    Order order;
    
    OrderItem item1;
    item1.price = 10.00;
    item1.quantity = 1;
    order.items.push_back(item1);
    
    OrderItem item2;
    item2.price = 25.50;
    item2.quantity = 2;
    order.items.push_back(item2);
    
    OrderItem item3;
    item3.price = 5.25;
    item3.quantity = 3;
    order.items.push_back(item3);
    
    // Act
    bool result = processor.process_order(order);
    
    // Assert
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(76.75, order.order_total); // 10 + (25.50 * 2) + (5.25 * 3)
    auto now = std::chrono::system_clock::now();
    auto diff = now - order.processed_at;
    EXPECT_LT(std::chrono::duration_cast<std::chrono::seconds>(diff).count(), 1);
}

TEST_F(OrderProcessorTests, ProcessOrder_ZeroQuantityItem_DoesNotAffectTotal) {
    // Arrange
    Order order;
    
    OrderItem item1;
    item1.price = 10.00;
    item1.quantity = 0;
    order.items.push_back(item1);
    
    OrderItem item2;
    item2.price = 25.50;
    item2.quantity = 1;
    order.items.push_back(item2);
    
    // Act
    bool result = processor.process_order(order);
    
    // Assert
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(25.50, order.order_total);
    auto now = std::chrono::system_clock::now();
    auto diff = now - order.processed_at;
    EXPECT_LT(std::chrono::duration_cast<std::chrono::seconds>(diff).count(), 1);
}

TEST_F(OrderProcessorTests, ProcessOrder_SetsProcessedAtToCurrentTime) {
    // Arrange
    Order order;
    
    OrderItem item;
    item.price = 15.00;
    item.quantity = 1;
    order.items.push_back(item);
    
    auto before_process = std::chrono::system_clock::now();
    
    // Act
    processor.process_order(order);
    
    // Assert
    EXPECT_GE(order.processed_at, before_process);
    EXPECT_LE(order.processed_at, std::chrono::system_clock::now());
}