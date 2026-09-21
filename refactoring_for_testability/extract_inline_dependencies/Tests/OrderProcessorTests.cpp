#include "OrderProcessor.hpp"
#include <gtest/gtest.h>

class OrderProcessorTests : public ::testing::Test {
protected:
    OrderProcessor processor;
};

TEST_F(OrderProcessorTests, ProcessOrder_WithSingleItem_CalculatesTotalCorrectly) {
    Order order;
    order.id = 1;
    order.customer_id = 1;
    order.items.push_back(OrderItem{1, 2});

    bool result = processor.process_order(order);

    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(20.00, order.order_total); // 2 items * $10 each
    EXPECT_NE(0, order.processed_at);
}

TEST_F(OrderProcessorTests, ProcessOrder_WithMultipleItems_CalculatesTotalCorrectly) {
    Order order;
    order.id = 1;
    order.customer_id = 1;
    order.items.push_back(OrderItem{1, 2});
    order.items.push_back(OrderItem{2, 3});

    bool result = processor.process_order(order);

    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(50.00, order.order_total); // (2 * $10) + (3 * $10)
    EXPECT_NE(0, order.processed_at);
}

TEST_F(OrderProcessorTests, ProcessOrder_WithNoItems_SetsZeroTotal) {
    Order order;
    order.id = 1;
    order.customer_id = 1;

    bool result = processor.process_order(order);

    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(0.00, order.order_total);
    EXPECT_NE(0, order.processed_at);
}

TEST_F(OrderProcessorTests, ProcessOrder_WithZeroQuantityItems_CalculatesTotalCorrectly) {
    Order order;
    order.id = 1;
    order.customer_id = 1;
    order.items.push_back(OrderItem{1, 0});
    order.items.push_back(OrderItem{2, 2});

    bool result = processor.process_order(order);

    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(20.00, order.order_total); // 0 + (2 * $10)
    EXPECT_NE(0, order.processed_at);
}