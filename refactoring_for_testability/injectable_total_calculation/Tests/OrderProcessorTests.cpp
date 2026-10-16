#include <gtest/gtest.h>
#include <vector>
#include <chrono>
#include "OrderProcessor.hpp"

class OrderProcessorTests : public ::testing::Test {
protected:
    OrderProcessor processor;
    Order order;

    void SetUp() override {
        order.items = {
            {10.5, 2},
            {25.99, 1}
        };
    }
};

TEST_F(OrderProcessorTests, ProcessOrder_CalculatesTotalCorrectly) {
    // Act
    bool result = processor.process_order(order);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(order.order_total, 46.99); // 10.5 * 2 + 25.99 = 46.99
    EXPECT_LT(std::chrono::system_clock::now() - order.processed_at, std::chrono::seconds(1)); // ProcessedAt should be very recent
}