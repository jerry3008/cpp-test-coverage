#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <string>

// TODO: Define an ILogger interface with the following method:
//       - Log which takes a string
class ILogger
{
    public:
    virtual void Log(const std::string& mess ) = 0;
    virtual ~ILogger() = default;
};
class INewsletterSender
{
    public:
    virtual void Send(const std::string& to, const std::string& subject, const std::string& body ) = 0;
    virtual ~INewsletterSender() = default;
};
// TODO: Define an INewsletterSender interface with the following method:
//       - Send which takes the to, subject, and body

class NewsletterService 
{
    ILogger* logger_;
    INewsletterSender* INewsletterSender_;
    // TODO: Receive a private logger: ILogger
    // TODO: Receive a private newsletterSender: INewsletterSender

public:
    // TODO: Update constructor to receive and initialize logger and newsletterSender
    NewsletterService(ILogger* logger_, INewsletterSender* INewsletterSender_);
    bool SendNewsletter(const std::string& to, const std::string& subject, const std::string& body);
};

#endif  // MAIN_HPP_