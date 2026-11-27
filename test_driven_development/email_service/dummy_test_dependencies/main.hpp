#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <string>

enum class LogSeverity {
    Info,
    Error
};

class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void Log(const std::string& message, LogSeverity severity) = 0;
};

class IEmailSender {
public:
    virtual ~IEmailSender() = default;
    virtual void Send(const std::string& to, const std::string& subject, const std::string& body) = 0;
};

class EmailService {
public:
    EmailService(ILogger* logger, IEmailSender* emailSender);
    bool SendEmail(const std::string& to, const std::string& subject, const std::string& body);

private:
    ILogger* _logger;
    IEmailSender* _emailSender;
};

#endif  // MAIN_HPP_