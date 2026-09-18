# Preparing EmailService for Mocking

This exercise prepares the `EmailService` dependency used by `OrderProcessor`
for future mocking and isolated unit testing.

## Objective

The existing `OrderProcessor` depends directly on the concrete
`EmailService` implementation.

This makes testing email-related behavior difficult because a test should not
need to send a real email.

The exercise introduces an interface that defines the email-service contract.

## Design

The dependency changes from:

```text
OrderProcessor
      |
      v
EmailService

to:

OrderProcessor
      |
      v
IEmailService
      ^
      |
EmailService

IEmailService defines the contract, while EmailService provides the real
implementation.

Tasks
Create an interface for the email service.
Define the order-confirmation operation in the interface.
Update EmailService to implement the interface.
Update the OrderProcessor implementation and tests.
Preserve the existing order-processing behavior.
Why This Matters

Depending directly on a concrete email implementation tightly couples
OrderProcessor to that implementation.

Depending on an interface makes it possible to later substitute a mock:

              IEmailService
               /        \
              /          \
     EmailService    MockEmailService
         REAL             TEST

The production application can use EmailService, while unit tests can use a
mock implementation without sending real emails.

Concepts Practiced
Interfaces
Abstract classes
Dependency inversion
Dependency isolation
Testability
Mocking preparation
Unit testing
Refactoring existing code

### What you're learning here

This is an important transition. Previously, if `OrderProcessor` essentially does:

```cpp
EmailService emailService;
emailService.sendOrderConfirmation(...);

your test is tied to the real EmailService.

Introducing something like:

class IEmailService {
public:
    virtual void sendOrderConfirmation(const Order& order) = 0;
    virtual ~IEmailService() = default;
};

creates a contract. Eventually OrderProcessor can depend on IEmailService rather than caring whether it receives the real implementation or a mock.