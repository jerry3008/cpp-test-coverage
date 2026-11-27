#include "gtest/gtest.h"
#include "../src/main.hpp"

// TODO: Create a DummyLogger class that inherits from ILogger
// - This dummy should implement the Log method with an empty body
// - Remember that dummies are just placeholders with no real functionality
// - The method signature must match: void Log(const std::string& message, LogSeverity severity)
class DummyLogger : public ILogger
{
    public:
    virtual void Log(const std::string& message, LogSeverity severity) override
    {}
    
   
};

class DummyEmailSender : public IEmailSender
{
    public:
    virtual void Send(const std::string& to, const std::string& subject, const std::string& body) override
    {}
    
   
};
// TODO: Create a DummyEmailSender class that inherits from IEmailSender
// - This dummy should implement the Send method with an empty body
// - The method signature must match: void Send(const std::string& to, const std::string& subject, const std::string& body)
// - No need to actually send emails, just satisfy the interface requirements

class EmailServiceTests : public ::testing::Test {
protected:
    EmailService* emailService;

    void SetUp() override {
        // TODO: Initialize the emailService with instances of your dummy classes
        // - Create new DummyLogger and DummyEmailSender objects
        // - Pass these dummy objects to the EmailService constructor
        // - Example: emailService = new EmailService(new DummyLogger(), new DummyEmailSender());
        
        emailService =  new EmailService(new DummyLogger(), new DummyEmailSender());;
    }

    void TearDown() override {
        delete emailService;
    }
};

TEST_F(EmailServiceTests, ShouldAcceptValidEmailParameters) {
    bool result = emailService->SendEmail("test@example.com", "Hello", "This is a test");
    EXPECT_TRUE(result);
}

TEST_F(EmailServiceTests, ShouldRejectInvalidEmailAddress) {
    bool result = emailService->SendEmail("invalid-email", "Hello", "This is a test");
    EXPECT_FALSE(result);
}

TEST_F(EmailServiceTests, ShouldRejectEmptySubject) {
    bool result = emailService->SendEmail("test@example.com", "", "This is a test");
    EXPECT_FALSE(result);
}

TEST_F(EmailServiceTests, ShouldRejectEmptyBody) {
    bool result = emailService->SendEmail("test@example.com", "Hello", "");
    EXPECT_FALSE(result);
}

TEST_F(EmailServiceTests, ShouldRejectBodyExceeding1000Characters) {
    bool result = emailService->SendEmail("test@example.com", "Hello", std::string(1001, 'a'));
    EXPECT_FALSE(result);
}