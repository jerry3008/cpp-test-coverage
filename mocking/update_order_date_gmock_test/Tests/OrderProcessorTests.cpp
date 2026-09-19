#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "OrderDatabase.hpp"
#include "OrderProcessor.cpp"

class MockOrderDatabase : public IOrderDatabase {
public:
    MOCK_METHOD(Order, GetOrderById, (int order_id), (override));
    MOCK_METHOD(void, UpdateOrder, (const Order& order), (override));
};

class OrderProcessorTests : public ::testing::Test {
protected:
    std::unique_ptr<MockOrderDatabase> mock_order_database_;
    std::unique_ptr<OrderProcessor> order_processor_;

    OrderProcessorTests() {
        mock_order_database_ = std::make_unique<MockOrderDatabase>();
        order_processor_ = std::make_unique<OrderProcessor>(mock_order_database_.get());
    }
};

TEST_F(OrderProcessorTests, UpdateOrderDate_OrderExists_ReturnsTrue) 
{
    
    
    int order_id = 1;
    Order order1;
    order1.id = order_id;
    order1.name = "Test Order";
    order1.email = "test@example.com";
    EXPECT_CALL(*mock_order_database_,  GetOrderById(order_id)).WillOnce(::testing::Return(order1));
    EXPECT_CALL(*mock_order_database_, UpdateOrder(::testing::_)).Times(1);
    auto result = order_processor_->UpdateOrderDate(order_id);
    ASSERT_TRUE(result);

}