# OrderProcessor Mock Database Test Setup

This exercise establishes a Google Test environment for testing
`OrderProcessor` without accessing a real database.

## Objective

`OrderProcessor` performs database operations through the `IOrderDatabase`
interface.

Because the processor now supports dependency injection, tests can provide
a mock implementation of the database instead of using the real
`OrderDatabase`.

## Test Fixture

The Google Test fixture stores:

- A mock database implementation
- An `OrderProcessor` instance

The processor is initialized with the mock database dependency.

```text
OrderProcessorTests
      |
      +---- MockOrderDatabase
      |
      +---- OrderProcessor
                 |
                 v
          IOrderDatabase
                 ^
                 |
          MockOrderDatabase
Why This Matters

Unit tests should focus on the behavior of the class being tested.

Using a mock database prevents tests from:

Connecting to a real database
Modifying real data
Depending on external infrastructure
Becoming slow or unreliable

It also allows future tests to verify whether OrderProcessor performs the
expected database operations.

Concepts Practiced
Google Test
Test fixtures
Mock objects
Dependency injection
Constructor initialization
Dependency isolation
Unit testing
Testing without external side effects