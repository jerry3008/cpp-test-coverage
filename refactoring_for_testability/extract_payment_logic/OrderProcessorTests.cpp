#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "OrderProcessor.hpp"

// Mock classes for the dependencies
class MockDatabaseConnection : public IDatabaseConnection {
public:
    MOCK_METHOD(std::unique_ptr<Customer>, get_customer_by_id, (int customer_id), (override));
    MOCK_METHOD(std::unique_ptr<Product>, get_product_by_id, (int product_id), (override));
    MOCK_METHOD(void, update_order_status, (int order_id, const std::string& status), (override));
};

class MockEmailService : public IEmailService {
public:
    MOCK_METHOD(void, send_order_confirmation, (const std::string& email, int order_id, double total_amount), (override));
};

class MockPaymentGateway : public IPaymentGateway {
public:
    MOCK_METHOD(PaymentResult, process_payment, (double amount), (override));
};

class OrderProcessorTests : public ::testing::Test {
protected:
    void SetUp() override {
        db_connection_ = std::make_shared<MockDatabaseConnection>();
        email_service_ = std::make_shared<MockEmailService>();
        payment_gateway_ = std::make_shared<MockPaymentGateway>();
        
        order_processor_ = std::make_unique<OrderProcessor>(
            db_connection_,
            email_service_,
            payment_gateway_
        );
    }

    void TearDown() override {
        order_processor_.reset();
    }

    std::shared_ptr<MockDatabaseConnection> db_connection_;
    std::shared_ptr<MockEmailService> email_service_;
    std::shared_ptr<MockPaymentGateway> payment_gateway_;
    std::unique_ptr<OrderProcessor> order_processor_;
};

TEST_F(OrderProcessorTests, CustomerNotFoundReturnsFalse) {
    // Arrange
    Order order;
    order.customer_id = 1;
    
    EXPECT_CALL(*db_connection_, get_customer_by_id(1))
        .WillOnce(::testing::Return(nullptr));
    
    EXPECT_CALL(*payment_gateway_, process_payment(::testing::_))
        .Times(0);
    
    EXPECT_CALL(*email_service_, send_order_confirmation(::testing::_, ::testing::_, ::testing::_))
        .Times(0);

    // Act
    bool result = order_processor_->process_order(order);

    // Assert
    ASSERT_FALSE(result);
}

TEST_F(OrderProcessorTests, WithValidCustomerAndProductsCalculatesCorrectTotal) {
    // Arrange
    auto customer = std::make_unique<Customer>();
    customer->email = "test@test.com";
    customer->is_premium = false;
    
    Order order;
    order.id = 1;
    order.customer_id = 1;
    
    OrderItem item1;
    item1.product_id = 1;
    item1.quantity = 2;
    
    OrderItem item2;
    item2.product_id = 2;
    item2.quantity = 1;
    
    order.items = {item1, item2};

    auto product1 = std::make_unique<Product>();
    product1->id = 1;
    product1->price = 10.0;
    
    auto product2 = std::make_unique<Product>();
    product2->id = 2;
    product2->price = 20.0;

    EXPECT_CALL(*db_connection_, get_customer_by_id(1))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(customer))));
    
    EXPECT_CALL(*db_connection_, get_product_by_id(1))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(product1))));
    
    EXPECT_CALL(*db_connection_, get_product_by_id(2))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(product2))));
    
    PaymentResult payment_result;
    payment_result.success = true;
    
    EXPECT_CALL(*payment_gateway_, process_payment(40.0))
        .WillOnce(::testing::Return(payment_result));
    
    EXPECT_CALL(*db_connection_, update_order_status(order.id, "Paid"))
        .Times(1);
    
    EXPECT_CALL(*email_service_, send_order_confirmation("test@test.com", order.id, 40.0))
        .Times(1);

    // Act
    bool result = order_processor_->process_order(order);

    // Assert
    ASSERT_TRUE(result);
}

TEST_F(OrderProcessorTests, WithPremiumCustomerAppliesDiscount) {
    // Arrange
    auto customer = std::make_unique<Customer>();
    customer->email = "test@test.com";
    customer->is_premium = true;
    
    Order order;
    order.id = 1;
    order.customer_id = 1;
    
    OrderItem item;
    item.product_id = 1;
    item.quantity = 1;
    
    order.items = {item};

    auto product = std::make_unique<Product>();
    product->id = 1;
    product->price = 100.0;

    EXPECT_CALL(*db_connection_, get_customer_by_id(1))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(customer))));
    
    EXPECT_CALL(*db_connection_, get_product_by_id(1))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(product))));
    
    PaymentResult payment_result;
    payment_result.success = true;
    
    EXPECT_CALL(*payment_gateway_, process_payment(90.0))
        .WillOnce(::testing::Return(payment_result));

    // Act
    bool result = order_processor_->process_order(order);

    // Assert
    ASSERT_TRUE(result);
}

TEST_F(OrderProcessorTests, PaymentFailsReturnsFalse) {
    // Arrange
    auto customer = std::make_unique<Customer>();
    
    Order order;
    order.customer_id = 1;
    
    OrderItem item;
    item.product_id = 1;
    item.quantity = 1;
    
    order.items = {item};

    auto product = std::make_unique<Product>();
    product->id = 1;
    product->price = 10.0;

    EXPECT_CALL(*db_connection_, get_customer_by_id(1))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(customer))));
    
    EXPECT_CALL(*db_connection_, get_product_by_id(1))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(product))));
    
    PaymentResult payment_result;
    payment_result.success = false;
    
    EXPECT_CALL(*payment_gateway_, process_payment(::testing::_))
        .WillOnce(::testing::Return(payment_result));
    
    EXPECT_CALL(*db_connection_, update_order_status(::testing::_, ::testing::_))
        .Times(0);
    
    EXPECT_CALL(*email_service_, send_order_confirmation(::testing::_, ::testing::_, ::testing::_))
        .Times(0);

    // Act
    bool result = order_processor_->process_order(order);

    // Assert
    ASSERT_FALSE(result);
}

TEST_F(OrderProcessorTests, ProductNotFoundSkipsProduct) {
    // Arrange
    auto customer = std::make_unique<Customer>();
    customer->email = "test@test.com";
    
    Order order;
    order.id = 1;
    order.customer_id = 1;
    
    OrderItem item1;
    item1.product_id = 1;
    item1.quantity = 1;
    
    OrderItem item2;
    item2.product_id = 2;
    item2.quantity = 1;
    
    order.items = {item1, item2};

    auto product1 = std::make_unique<Product>();
    product1->id = 1;
    product1->price = 10.0;

    EXPECT_CALL(*db_connection_, get_customer_by_id(1))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(customer))));
    
    EXPECT_CALL(*db_connection_, get_product_by_id(1))
        .WillOnce(::testing::Return(::testing::ByMove(std::move(product1))));
    
    EXPECT_CALL(*db_connection_, get_product_by_id(2))
        .WillOnce(::testing::Return(nullptr));
    
    PaymentResult payment_result;
    payment_result.success = true;
    
    EXPECT_CALL(*payment_gateway_, process_payment(10.0))
        .WillOnce(::testing::Return(payment_result));

    // Act
    bool result = order_processor_->process_order(order);

    // Assert
    ASSERT_TRUE(result);
}

TEST_F(OrderProcessorTests, ExceptionThrownReturnsFalse) {
    // Arrange
    Order order;
    order.customer_id = 1;
    
    EXPECT_CALL(*db_connection_, get_customer_by_id(1))
        .WillOnce(::testing::Throw(std::exception()));
    
    EXPECT_CALL(*payment_gateway_, process_payment(::testing::_))
        .Times(0);
    
    EXPECT_CALL(*email_service_, send_order_confirmation(::testing::_, ::testing::_, ::testing::_))
        .Times(0);

    // Act
    bool result = order_processor_->process_order(order);

    // Assert
    ASSERT_FALSE(result);
}