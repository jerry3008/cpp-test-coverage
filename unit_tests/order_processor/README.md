# OrderProcessor Unit Test

This exercise demonstrates how to add unit test coverage for an `OrderProcessor` in C++.

## Objective

Verify that `OrderProcessor::ProcessOrder` correctly calculates the total amount of an order.

The test follows the Arrange, Act, Assert structure.

## Arrange

Create an `Order` containing one `OrderItem` with:

- Price: `10.00`
- Quantity: `2`

## Act

Call:

`ProcessOrder(order)`

on an `OrderProcessor` instance.

## Assert

Verify that:

- `ProcessOrder` returns `true`
- `OrderTotal` is equal to `20.00`

## Concepts Practiced

- Unit testing
- Arrange, Act, Assert
- Expected return values
- State verification
- Regression protection
- Testing business logic

## Why This Matters

A unit test provides confidence that future changes to `OrderProcessor` do not accidentally break the expected order-total calculation.

This test also documents the intended behavior of `ProcessOrder`.





## Multiple Items Test

This test verifies that `ProcessOrder` correctly calculates the total order amount when an order contains multiple items.

The test follows the Arrange, Act, Assert pattern.

### Arrange

Create an `Order` containing multiple `OrderItem` objects with different prices and quantities.

### Act

Call:

`ProcessOrder(order)`

using an `OrderProcessor` instance.

### Assert

Verify that:

- `ProcessOrder` returns `true`
- `OrderTotal` matches the expected sum of all item prices multiplied by their quantities

### Concept Practiced

This test expands coverage beyond a single-item order and checks that the implementation correctly accumulates totals across multiple order items.