#include "OrderProcessor.hpp"
#include <gtest/gtest.h>
#include <vector>

class OrderProcessorCharacterizationTests : public ::testing::Test {
protected:
    OrderProcessor processor;
};

TEST_F(OrderProcessorCharacterizationTests, when_order_exceeds_item_limit_order_is_rejected) 
{
    Order order;
    // TODO: Arrange - Create an order with 51 items, each with price = 10.0 and quantity = 1
    std::vector<OrderItem> items(51, {10.0, 1});
    order.items = items;
    // TODO: Act - Process the order and store the result
    bool result = processor.process_order(order);
    // TODO: Assert - Assert that the result is false and the order.status is OrderStatus::Pending
    
    EXPECT_FALSE(result);
    EXPECT_EQ(OrderStatus::Pending, order.status); // 10% discount applied
}