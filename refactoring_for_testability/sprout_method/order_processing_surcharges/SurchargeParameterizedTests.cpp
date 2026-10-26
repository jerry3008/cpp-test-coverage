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

TEST_F(OrderProcessorTests, ProcessOrderWithSurcharge_ValidOrder_CalculatesTotalWithSurcharge) {
    // Arrange
    Order order;
    
    OrderItem item1;
    item1.price = 100.0;
    item1.quantity = 2;
    order.items.push_back(item1);
    
    OrderItem item2;
    item2.price = 50.0;
    item2.quantity = 1;
    order.items.push_back(item2);
    
    double surcharge_percentage = 10.0;
    
    // Act
    processor.process_order_with_surcharge(order, surcharge_percentage);
    
    // Assert
    EXPECT_DOUBLE_EQ(275.0, order.order_total); // (200 + 50) * 1.1
    EXPECT_DOUBLE_EQ(25.0, order.surcharge_amount); // (200 + 50) * 0.1
    
    auto now = std::chrono::system_clock::now();
    auto diff = now - order.processed_at;
    EXPECT_LT(std::chrono::duration_cast<std::chrono::seconds>(diff).count(), 1);
}

TEST_F(OrderProcessorTests, ProcessOrderWithSurcharge_EmptyOrder_CalculatesZeroTotal) {
    // Arrange
    Order order;
    double surcharge_percentage = 10.0;

    // Act
    processor.process_order_with_surcharge(order, surcharge_percentage);

    // Assert
    EXPECT_DOUBLE_EQ(0.0, order.order_total);
    EXPECT_DOUBLE_EQ(0.0, order.surcharge_amount);
}

class NegativeSurchargeTests : public ::testing::TestWithParam<double> {
protected:
    OrderProcessor processor;
};

TEST_P(NegativeSurchargeTests, ProcessOrderWithSurcharge_NegativeSurcharge_ThrowsInvalidArgument) {
    // Arrange
    Order order;
    OrderItem item;
    item.price = 100.0;
    item.quantity = 1;
    order.items.push_back(item);
    
    double surcharge_percentage = GetParam();
    
    // Act & Assert
    EXPECT_THROW(processor.process_order_with_surcharge(order, surcharge_percentage), std::invalid_argument);
}

INSTANTIATE_TEST_SUITE_P(
    NegativeSurcharges,
    NegativeSurchargeTests,
    ::testing::Values(-1.0, -10.0, -100.0)
);

// TODO: Create a test fixture class ValidSurchargeTests that inherits from ::testing::TestWithParam<double>
// TODO: Create a TEST_P that verifies process_order_with_surcharge works with valid surcharge percentages
// TODO: Use ::testing::Values to test with values 0.0, 100.0, and 200.0
// TODO: Create an order with a single item priced at 100.0 with quantity 1
// TODO: Call process_order_with_surcharge with the order and surcharge percentage
// TODO: Assert that the result is true
// TODO: Assert that the order_total equals 100.0 * (1 + surcharge_percentage / 100.0)
class ValidSurchargeTests : public ::testing::TestWithParam<double> {
protected:
    OrderProcessor processor;
};

TEST_P(ValidSurchargeTests, ProcessOrderWithSurcharge_ValidSurcharge) {
    // Arrange
    Order order;
    OrderItem item;
    item.price = 100.0;
    item.quantity = 1;
    order.items.push_back(item);
    
    double surcharge_percentage = GetParam();
    
    // Act & Assert
    bool result = processor.process_order_with_surcharge(order, surcharge_percentage);
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(100.0 * (1 + surcharge_percentage / 100.0), order.order_total);
}

INSTANTIATE_TEST_SUITE_P(
    ValidSurchargeTests,
    ValidSurchargeTests,
    ::testing::Values(0.0, 100.0, 200.0)
);