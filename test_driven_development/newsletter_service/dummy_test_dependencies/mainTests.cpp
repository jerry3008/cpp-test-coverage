#include <gtest/gtest.h>
#include "../src/main.hpp"

// TODO: Implement DummyLogger class that implements ILogger
class DummyLogger : public ILogger
{
    public:
    void Log(const std::string& message) override {}
    
};

class DummyNewsletterSender : public INewsletterSender
{
    public:
    void Send(const std::string& to, const std::string& subject, const std::string& body ) override {}
};

// TODO: Implement DummyNewsletterSender class that implements INewsletterSender

class StarterNewsletterServiceTests : public ::testing::Test {
protected:
    NewsletterService* newsletterService;

    void SetUp() override {
        // TODO: Pass the dummy dependencies to the service
        
        newsletterService = new NewsletterService(new DummyLogger(), new DummyNewsletterSender());
    }

    void TearDown() override {
        delete newsletterService;
    }
};

TEST_F(StarterNewsletterServiceTests, AcceptValidNewsletterParameters) {
    bool result = newsletterService->SendNewsletter("subscriber@example.com", "Latest Updates", "Check out our latest newsletter!");
    EXPECT_TRUE(result);
}

TEST_F(StarterNewsletterServiceTests, RejectInvalidEmailAddress) {
    bool result = newsletterService->SendNewsletter("invalid-email", "Latest Updates", "Check out our latest newsletter!");
    EXPECT_FALSE(result);
}

TEST_F(StarterNewsletterServiceTests, RejectEmptySubject) {
    bool result = newsletterService->SendNewsletter("subscriber@example.com", "", "Check out our latest newsletter!");
    EXPECT_FALSE(result);
}

TEST_F(StarterNewsletterServiceTests, RejectContentExceeding2000Characters) {
    bool result = newsletterService->SendNewsletter("subscriber@example.com", "Latest Updates", std::string(2001, 'a'));
    EXPECT_FALSE(result);
}