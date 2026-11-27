
# Email Service — Dummy Test Dependencies

## Overview

Complete the EmailService test setup by implementing
dummy objects that satisfy its dependencies without
introducing real functionality.

## Objective

Isolate EmailService during unit testing by replacing
external dependencies with minimal implementations.

## Components

### DummyLogger

Implements the ILogger interface without performing
actual logging operations.

Accepts the message and LogSeverity parameters while
intentionally ignoring their values.

### DummyEmailSender

Implements the email sender interface without sending
actual emails or connecting to external services.

### EmailService

Receives dummy dependencies through dependency
injection, allowing its business logic to be tested
independently.

## Testing Approach

- Implement the required dummy classes.
- Match the existing interface signatures.
- Inject dummy dependencies into EmailService.
- Complete the unit test setup.
- Execute the existing tests.
- Preserve the original application behavior.

## Concepts Practiced

- Test-Driven Development
- Google Test
- Test doubles
- Dummy objects
- Dependency injection
- Dependency isolation
- Abstract classes
- Pure virtual functions
- Interface implementation
- Method overriding
- Runtime polymorphism
- Test fixtures
- Separation of concerns

## Benefits

- Eliminates unnecessary external dependencies.
- Prevents unintended email delivery.
- Avoids real logging operations.
- Improves test isolation.
- Supports reliable and repeatable unit testing.
