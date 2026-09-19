# OrderDatabase Dependency Injection

This exercise refactors `OrderProcessor` to use dependency injection for
database operations.

## Objective

Previously, `OrderProcessor` depended directly on the concrete
`OrderDatabase` implementation.

The previous exercise introduced `IOrderDatabase`. This exercise updates
`OrderProcessor` to depend on that abstraction.

## Changes

- Replace the concrete `OrderDatabase` field with `IOrderDatabase`.
- Add constructor injection for the database dependency.
- Allow an `IOrderDatabase` implementation to be supplied externally.
- Preserve the existing behavior when no dependency is supplied.
- Use the real `OrderDatabase` as the default implementation.

## Dependency Injection

Production code can continue using the default database:

```cpp
OrderProcessor processor;
This allows database-related behavior to be tested without accessing a real
database.

Design
                 IOrderDatabase
                      ▲
                      │
               OrderProcessor
                  /       \
                 /         \
        OrderDatabase   MockOrderDatabase
            Real             Test
Why This Matters

Dependency injection separates OrderProcessor from the details of database
access.

OrderProcessor only needs to know about the IOrderDatabase contract.

This improves:

Testability
Flexibility
Maintainability
Dependency isolation
Separation of concerns
Concepts Practiced
Dependency injection
Constructor injection
Dependency inversion
C++ interfaces
Abstract classes
Mockable dependencies
Unit-test isolation
Refactoring for testability