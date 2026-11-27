
# Newsletter Service — Dummy Test Dependencies

## Overview

Implement and test a NewsletterService using interface-based
dependencies and dummy test doubles in C++.

## Objective

Decouple NewsletterService from concrete logging and
newsletter delivery implementations through dependency
injection.

## Components

### ILogger

Defines the contract for logging operations using
a pure virtual log() method.

### INewsletterSender

Defines the contract for newsletter delivery operations.

### NewsletterService

Receives ILogger and INewsletterSender dependencies
through its constructor.

Uses the injected dependencies when executing
the SendNewsletter() method.

### DummyLogger

Implements ILogger without performing actual logging.

### DummyNewsletterSender

Implements INewsletterSender without sending
actual newsletters.

## Testing Approach

- Define abstract dependency interfaces.
- Implement minimal dummy dependencies.
- Inject dummy objects through the constructor.
- Execute the existing NewsletterService tests.
- Verify that existing behavior remains unchanged.
- Avoid real external operations during unit testing.

## Design Principles

- Dependency Inversion Principle
- Dependency Injection
- Separation of Concerns
- Loose Coupling
- Interface-Based Programming

## Concepts Practiced

- Test-Driven Development
- Google Test
- Test doubles
- Dummy objects
- Abstract classes
- Pure virtual functions
- Virtual destructors
- Constructor dependency injection
- Constructor initializer lists
- Method overriding
- Runtime polymorphism
- Reference-based dependencies
- Regression testing

## Benefits

- Improved testability.
- Reduced coupling between components.
- Replaceable dependency implementations.
- Isolated and repeatable unit tests.
- Improved maintainability and extensibility.
