#include "OrderProcessor.hpp"
#include <iostream>

// EmailService implementation
EmailService::EmailService(ILogger* logger, IStorage* storage)
    : logger_(logger), storage_(storage) {}

void EmailService::send_message(const std::string& message) {
    std::cout << "Sending email: " << message << std::endl;
}

bool EmailService::validate_message(const std::string& message) {
    return !message.empty() && message.length() <= 1000;
}

void EmailService::log_notification(const std::string& message) {
    logger_->log("Email notification: " + message);
}

void EmailService::store_notification(const std::string& message) {
    storage_->store("Email: " + message);
}

// SMSService implementation
void SMSService::send_message(const std::string& message) {
    std::cout << "Sending SMS: " << message << std::endl;
}

bool SMSService::validate_message(const std::string& message) {
    return !message.empty() && message.length() <= 160;
}

void SMSService::log_notification(const std::string& message) {
    // does not make sense in the SMSService
}

void SMSService::store_notification(const std::string& message) {
    // does not make sense in the SMSService
}

// AuditService implementation
AuditService::AuditService(ILogger* logger, IStorage* storage)
    : logger_(logger), storage_(storage) {}

void AuditService::send_message(const std::string& message) {
    // does not make sense in the AuditService
}

bool AuditService::validate_message(const std::string& message) {
    // does not make sense in the AuditService
    return false;
}

void AuditService::log_notification(const std::string& message) {
    logger_->log("Audit: " + message);
}

void AuditService::store_notification(const std::string& message) {
    storage_->store("Audit: " + message);
}