#include "main.hpp"

// TODO: Implement the EmailService constructor
// - Initialize the _logger and _emailSender member variables with the provided parameters
EmailService::EmailService(ILogger* logger, IEmailSender* emailSender): _logger(logger), _emailSender(emailSender){}
bool EmailService::SendEmail(const std::string& to, const std::string& subject, const std::string& body)
{
    if(to.empty() || to.find('@')== std::string::npos)
    {
        return false;
    }
    if(subject.empty())
    {
        return false;
    }
    if (body.empty() || body.length() > 1000) 
    {
        return false;
    }
    
    _logger -> Log("Sending email to " +  to, LogSeverity::Info);
    _emailSender->Send(to, subject, body);
    return true;
};

