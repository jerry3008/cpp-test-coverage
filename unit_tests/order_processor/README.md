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




## Processed At Timestamp Test

This test verifies that `OrderProcessor` correctly sets the `processed_at`
timestamp when an order is successfully processed.

The test follows the Arrange, Act, Assert pattern.

### Arrange

Create an order containing a single item and capture the current system time
immediately before processing the order.

### Act

Call `process_order` on the `OrderProcessor` and capture the current system
time again immediately after processing.

### Assert

Verify that:

- `process_order` returns `true`
- `processed_at` is greater than or equal to the time captured before processing
- `processed_at` is less than or equal to the time captured after processing

### Concept Practiced

This test introduces verification of time-dependent behavior.

Instead of comparing `processed_at` to one exact timestamp, the test verifies
that it falls within the valid time interval surrounding the call to
`process_order`.

This avoids relying on an exact system time while still confirming that the
timestamp was assigned during order processing.
The important testing idea here is:

before
   ↓
process_order()
   ↓
processed_at
   ↓
after

Therefore:

before <= processed_at <= after

That's much better than trying to assert:

processed_at == std::chrono::system_clock::now()

because time continues moving between those operations.