#include <gtest/gtest.h>
#include "OrderProcessor.hpp"
#include <chrono>

TEST(OrderProcessorTests, ProcessOrderCalculatesTotalCorrectly) {
    // Arrange
    OrderProcessor processor;
    Order order;
    order.items = {
        {10.5, 2},
        {25.99, 1}
    };

    // Act
    bool result = processor.process_order(order);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(46.99, order.order_total); // 10.5 * 2 + 25.99 = 46.99
    
    // Check that processed_at is recent (within last second)
    auto now = std::chrono::system_clock::now();
    auto diff = now - order.processed_at;
    EXPECT_LT(std::chrono::duration_cast<std::chrono::seconds>(diff).count(), 1);
}

TEST(OrderProcessorTests, ProcessOrderWithCustomDiscountCalculationAppliesDiscount) {
    // Arrange
    OrderProcessor order_processor;
    Order order;
    order.items = {
        {10.0, 2},
        {5.0, 3}
    };

    // Custom calculation with 10% discount
    auto discount_calculation = [](const std::vector<OrderItem>& items) {
        double total = 0.0;
        for (const auto& item : items) {
            double item_price = item.price * item.quantity;
            total += item_price;
        }
        return total * 0.9; // 10% discount
    };

    // Act
    order_processor.process_order(order, discount_calculation);

    // Assert
    double expected_total = (10.0 * 2 + 5.0 * 3) * 0.9;
    EXPECT_DOUBLE_EQ(expected_total, order.order_total);
}

// TODO: choose a meaningful name for your test function
    // TODO: Create an OrderProcessor instance
    
    // TODO: Create an Order with two items:
    // - First item with Price = 10.0 and Quantity = 2
    // - Second item with Price = 5.0 and Quantity = 3
    
    // TODO: Create a custom calculation function that applies a 15% surcharge
    // The function should:
    // 1. Calculate the total price of all items
    // 2. Multiply the total by 1.15 to add the 15% surcharge
    
    // TODO: Call process_order with the order and surcharge calculation
    
    // TODO: Assert that the order_total equals the expected total with 15% surcharge
    // The expected total should be (10.0 * 2 + 5.0 * 3) * 1.15
    
    TEST(OrderProcessorTests, ProcessOrdernow) {
    // Arrange
    OrderProcessor order_processor;
    Order order;
    order.items = {
        {10.0, 2},
        {5.0, 3}
    };

    // Custom calculation with 10% discount
    auto discount_calculation = [](const std::vector<OrderItem>& items) {
        double total = 0.0;
        for (const auto& item : items) {
            double item_price = item.price * item.quantity;
            total += item_price;
        }
        return total * 1.15; // 15% discount
    };

    // Act
    order_processor.process_order(order, discount_calculation);

    // Assert
    double expected_total = (10.0 * 2 + 5.0 * 3) * 1.15;
    EXPECT_DOUBLE_EQ(expected_total, order.order_total);
}