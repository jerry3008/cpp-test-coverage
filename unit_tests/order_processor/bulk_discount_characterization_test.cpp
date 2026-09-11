#include <gtest/gtest.h>
#include "OrderProcessor.hpp"

class OrderProcessorTests : public ::testing::Test {
protected:
    OrderProcessor processor;
};

TEST_F(OrderProcessorTests, WhenOrderExceedsItemLimit_OrderIsRejected) {
    // Arrange
    Order order;
    for (int i = 0; i < 51; ++i) {
        order.items.push_back(OrderItem{10.0, 1});
    }

    // Act
    bool result = processor.process_order(order);

    // Assert
    EXPECT_FALSE(result);
    EXPECT_EQ(OrderStatus::Pending, order.status);
}

TEST_F(OrderProcessorTests, WhenOrderExceedsBulkThreshold_DiscountIsApplied) 
{
    Order order;
    order.items = { OrderItem{1000.0, 1} };
    bool result = processor.process_order(order);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_TRUE(order.has_bulk_discount);
    EXPECT_DOUBLE_EQ(900.0, order.order_total);
    // TODO: Arrange - Create an order with a single item priced at 1000.0 and quantity of 1
    // TODO: Act - Process the order and store the result
    // TODO: Assert - Assert that:
    //       - the result is true
    //       - the order has bulk discount applied
    //       - the order total is 900.0 (10% discount applied to 1000.0)
}