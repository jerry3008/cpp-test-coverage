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
    
    std::unique_ptr<MockOrderDatabase>md;
    std::unique_ptr<OrderProcessor>op;

    OrderProcessorTests() {
    
        md = std::make_unique<MockOrderDatabase>();
        op = std::make_unique<OrderProcessor>(md.get());        
        
    }
};
TEST_F(OrderProcessorTests, DummyTest) {
    // A simple test case to ensure the test framework is working.
    ASSERT_TRUE(true);
}