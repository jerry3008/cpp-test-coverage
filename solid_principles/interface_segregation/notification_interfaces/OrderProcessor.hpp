#ifndef ORDER_PROCESSOR_HPP_
#define ORDER_PROCESSOR_HPP_

#include <string>

class INotificationLogger{
public:
    
    virtual void log_notification(const std::string& message) = 0;
    virtual ~INotificationLogger() = default;

};
class INotificationStorage{
public:
    
    virtual void store_notification(const std::string& message) = 0;
    virtual ~INotificationStorage() = default;
};


class INotificationService : public INotificationLogger, public INotificationStorage {
    
public:
    virtual ~INotificationService() = default;
    virtual void send_message(const std::string& message) = 0;
    virtual bool validate_message(const std::string& message) = 0;
};

class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void log(const std::string& message) = 0;
};

class IStorage {
public:
    virtual ~IStorage() = default;
    virtual void store(const std::string& message) = 0;
};

// Email Service
class EmailService : public INotificationService {
public:
    EmailService(ILogger* logger, IStorage* storage);
    
    void send_message(const std::string& message) override;
    bool validate_message(const std::string& message) override;
    void log_notification(const std::string& message) override;
    void store_notification(const std::string& message) override;

private:
    ILogger* logger_;
    IStorage* storage_;
};

// SMS Service
class SMSService : public INotificationService {
public:
    void send_message(const std::string& message) override;
    bool validate_message(const std::string& message) override;
    void log_notification(const std::string& message) override;
    void store_notification(const std::string& message) override;
};

// Audit Service
class AuditService : public INotificationService {
public:
    AuditService(ILogger* logger, IStorage* storage);
    
    void send_message(const std::string& message) override;
    bool validate_message(const std::string& message) override;
    void log_notification(const std::string& message) override;
    void store_notification(const std::string& message) override;

private:
    ILogger* logger_;
    IStorage* storage_;
};

#endif  // ORDER_PROCESSOR_HPP_