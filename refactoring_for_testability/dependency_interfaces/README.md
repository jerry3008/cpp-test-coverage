# Database and Payment Gateway Interfaces

This exercise introduces abstractions for the external dependencies used by
`OrderProcessor`.

## Objective

The existing application uses concrete `DatabaseConnection` and
`PaymentGateway` classes.

To improve testability and flexibility, two interfaces are introduced:

- `IDatabaseConnection`
- `IPaymentGateway`

The existing concrete classes are then updated to implement these interfaces.

## Database Interface

`IDatabaseConnection` defines the contract for database operations such as:

- Retrieving customers
- Retrieving products
- Updating order status

`DatabaseConnection` provides the real implementation of this contract.

## Payment Interface

`IPaymentGateway` defines the contract for processing payments.

`PaymentGateway` provides the real implementation.

## Design

```text
IDatabaseConnection             IPaymentGateway
        ▲                              ▲
        │                              │
DatabaseConnection               PaymentGateway
      REAL                           REAL

The application can now reason about what a database or payment service must
do without being tied exclusively to a particular implementation.

Preparing for Testing

These abstractions also make mock implementations possible:

IDatabaseConnection
       ▲
   ┌───┴───────────────┐
   │                   │
DatabaseConnection   MockDatabase
     REAL               TEST


IPaymentGateway
       ▲
   ┌───┴───────────────┐
   │                   │
PaymentGateway      MockPaymentGateway
     REAL               TEST

A future refactoring can inject these abstractions into OrderProcessor,
allowing its behavior to be tested without a real database or payment
service.

Concepts Practiced
C++ interfaces
Abstract classes
Pure virtual functions
Interface implementation
Dependency inversion
Dependency isolation
Polymorphism
Refactoring for testability
Preparing dependencies for mocking