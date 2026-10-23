#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include <iostream>
#include "OrderProcessor.hpp"

// Mock classes
class MockLogger : public ILogger {
public:
    MOCK_METHOD(void, log, (const std::string&), (override));
};

class MockStorage : public IStorage {
public:
    MOCK_METHOD(void, store, (const std::string&), (override));
};

// Test fixture for EmailService
class EmailServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        mock_logger_ = new MockLogger();
        mock_storage_ = new MockStorage();
        email_service_ = new EmailService(mock_logger_, mock_storage_);
    }

    void TearDown() override {
        delete email_service_;
        delete mock_storage_;
        delete mock_logger_;
    }

    MockLogger* mock_logger_;
    MockStorage* mock_storage_;
    EmailService* email_service_;
};

// Test fixture for SMSService
class SMSServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        sms_service_ = new SMSService();
    }

    void TearDown() override {
        delete sms_service_;
    }

    SMSService* sms_service_;
};

// Test fixture for AuditService
class AuditServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        mock_logger_ = new MockLogger();
        mock_storage_ = new MockStorage();
        audit_service_ = new AuditService(mock_logger_, mock_storage_);
    }

    void TearDown() override {
        delete audit_service_;
        delete mock_storage_;
        delete mock_logger_;
    }

    MockLogger* mock_logger_;
    MockStorage* mock_storage_;
    AuditService* audit_service_;
};

// EmailService Tests
TEST_F(EmailServiceTest, SendMessageWritesToConsole) {
    // Redirect std::cout
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    std::string message = "Test email message";
    email_service_->send_message(message);
    
    // Restore std::cout
    std::cout.rdbuf(old);
    
    EXPECT_TRUE(buffer.str().find("Sending email: " + message) != std::string::npos);
}

TEST_F(EmailServiceTest, ValidateMessageReturnsExpectedResult) {
    EXPECT_FALSE(email_service_->validate_message(""));
    EXPECT_TRUE(email_service_->validate_message("Valid message"));
}

TEST_F(EmailServiceTest, MessageLengthEdgeCaseReturnsExpectedResult) {
    std::string message_1000(1000, 'A');
    std::string message_1001(1001, 'A');
    
    EXPECT_TRUE(email_service_->validate_message(message_1000));
    EXPECT_FALSE(email_service_->validate_message(message_1001));
}

TEST_F(EmailServiceTest, LogNotificationCallsLogger) {
    std::string message = "Test email message";
    EXPECT_CALL(*mock_logger_, log("Email notification: " + message)).Times(1);
    
    email_service_->log_notification(message);
}

TEST_F(EmailServiceTest, StoreNotificationCallsStorage) {
    std::string message = "Test email message";
    EXPECT_CALL(*mock_storage_, store("Email: " + message)).Times(1);
    
    email_service_->store_notification(message);
}

// SMSService Tests
TEST_F(SMSServiceTest, SendMessageWritesToConsole) {
    // Redirect std::cout
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    std::string message = "Test SMS message";
    sms_service_->send_message(message);
    
    // Restore std::cout
    std::cout.rdbuf(old);
    
    EXPECT_TRUE(buffer.str().find("Sending SMS: " + message) != std::string::npos);
}

TEST_F(SMSServiceTest, ValidateMessageReturnsExpectedResult) {
    EXPECT_FALSE(sms_service_->validate_message(""));
    EXPECT_TRUE(sms_service_->validate_message("Valid message"));
}

TEST_F(SMSServiceTest, MessageLengthEdgeCaseReturnsExpectedResult) {
    std::string message_160(160, 'a');
    std::string message_161(161, 'a');
    
    EXPECT_TRUE(sms_service_->validate_message(message_160));
    EXPECT_FALSE(sms_service_->validate_message(message_161));
}

// AuditService Tests
TEST_F(AuditServiceTest, LogNotificationCallsLogger) {
    std::string message = "Test audit message";
    EXPECT_CALL(*mock_logger_, log("Audit: " + message)).Times(1);
    
    audit_service_->log_notification(message);
}

TEST_F(AuditServiceTest, StoreNotificationCallsStorage) {
    std::string message = "Test audit message";
    EXPECT_CALL(*mock_storage_, store("Audit: " + message)).Times(1);
    
    audit_service_->store_notification(message);
}