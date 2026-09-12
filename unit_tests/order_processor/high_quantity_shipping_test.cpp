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

TEST_F(OrderProcessorTests, WhenOrderExceedsBulkThreshold_DiscountIsApplied) {
    // Arrange
    Order order;
    order.items.push_back(OrderItem{1000.0, 1});

    // Act
    bool result = processor.process_order(order);

    // Assert
    EXPECT_TRUE(result);
    EXPECT_TRUE(order.has_bulk_discount);
    EXPECT_DOUBLE_EQ(900.0, order.order_total); // 10% discount applied
}

class ShippingMethodTest : public OrderProcessorTests, public ::testing::WithParamInterface<std::tuple<bool, ShippingMethod>> {};

TEST_P(ShippingMethodTest, ShippingMethod_DeterminedByLargeItemPresence) {
    // Arrange
    bool has_large_item = std::get<0>(GetParam());
    ShippingMethod expected_method = std::get<1>(GetParam());

    Order order;
    order.items.push_back(OrderItem{100.0, 1, has_large_item});

    // Act
    processor.process_order(order);

    // Assert
    EXPECT_EQ(expected_method, order.shipping_method);
}

INSTANTIATE_TEST_SUITE_P(
    ShippingMethodTests,
    ShippingMethodTest,
    ::testing::Values(
        std::make_tuple(true, ShippingMethod::Freight),
        std::make_tuple(false, ShippingMethod::Standard)
    )
);

TEST_F(OrderProcessorTests, WhenOrderQuantityExceedsTen_ExpressShippingIsAssigned) 
{
    Order order;
    order.items.push_back(OrderItem{10.0, 11, false});
    
    
   bool result =  processor.process_order(order);
    EXPECT_TRUE(result);
    EXPECT_EQ(ShippingMethod::Express, order.shipping_method);
    
    // TODO: Arrange - Create an order with a single item with Price = 10.0, Quantity = 11, and IsLargeItem = false
    // TODO: Act - Process the order using the processor
    // TODO: Assert - Assert that the order's ShippingMethod equals ShippingMethod::Express
}