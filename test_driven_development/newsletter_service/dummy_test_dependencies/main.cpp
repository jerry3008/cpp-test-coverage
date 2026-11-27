#include "main.hpp"

 NewsletterService::NewsletterService(ILogger* logger_, INewsletterSender* INewsletterSender_):logger_(logger_), INewsletterSender_(INewsletterSender_){}


bool NewsletterService::SendNewsletter(const std::string& to, const std::string& subject, const std::string& body) {
    if (to.empty() || to.find('@') == std::string::npos) {
        return false;
    }

    if (subject.empty()) {
        return false;
    }

    if (body.empty() || body.length() > 1000) {
        return false;
    }
    
 logger_->Log("Sending message to: " + to);
 INewsletterSender_ -> Send(to, subject, body);  
    // TODO: Log the sending of the newsletter
    // TODO: Call the newsletterSender to send the message
    return true;
}