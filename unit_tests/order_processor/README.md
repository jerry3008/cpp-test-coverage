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




## Item Limit Characterization Test

This test documents the existing behavior of `OrderProcessor` when an order exceeds the maximum allowed number of items.

The processor allows a maximum of 50 items per order.

### Scenario

Create an order containing more than 50 items.

For example:

```cpp
std::vector<OrderItem> items(51, {10.0, 1, false});

Expected Behavior

The test verifies that:

ProcessOrder returns false
The order is rejected when the number of items exceeds the configured limit
Why This Is a Characterization Test

The purpose of this test is not to redesign the behavior.

It captures and documents what the existing OrderProcessor currently does.

This provides a safety net before refactoring or modifying the implementation.

If future changes accidentally alter this behavior, the test will fail and highlight the change.



## Bulk Discount Characterization Test

This characterization test documents the existing bulk-order discount behavior
of `OrderProcessor`.

### Scenario

The `OrderProcessor` applies a 10% discount when an order has a total value of
$1,000 or more.

The test creates an order whose value meets or exceeds the bulk discount
threshold.

### Arrange

Create an order with items whose combined value qualifies for the bulk
discount.

For example, an order with a subtotal of:

`$1,000.00`

qualifies for the discount.

### Act

Process the order using `OrderProcessor`.

### Assert

Verify that:

- The order is processed successfully.
- The 10% bulk discount is applied.
- An order with a $1,000 subtotal results in a final total of $900.

### Calculation

```text
Subtotal:          $1,000.00
Discount (10%):      $100.00
                    ---------
Final Total:         $900.00

Why This Is a Characterization Test

This test captures the current behavior of the existing OrderProcessor
before the implementation is refactored.

By documenting the $1,000 threshold and 10% discount in a test, future changes
to the processor can be made with confidence that the existing bulk-order
behavior has not accidentally changed.

Concepts Practiced
Characterization testing
Arrange-Act-Assert
Boundary conditions
Business-rule testing
Percentage calculations
Regression protection


## Shipping Method Parameterized Test

This test documents how `OrderProcessor` determines the shipping method based
on whether an order contains large items.

The test uses Google Test parameterized testing so that multiple input
scenarios can be verified using the same test logic.

### Objective

Verify that different order configurations result in the expected shipping
method.

Instead of writing a separate test function for every scenario, the test
receives input values and expected results as parameters.

### Parameterized Testing

Google Test parameterized tests allow the same test behavior to run against
multiple sets of data.

This is useful when the logic being tested is the same but the inputs and
expected outputs vary.

For this exercise, the parameters represent scenarios such as:

- Order contains a large item
- Order does not contain a large item
- Expected shipping method for each case

### Test Flow

The test follows the Arrange-Act-Assert pattern.

#### Arrange

Create an order based on the current test parameters.

The order may contain either normal-sized or large items.

#### Act

Process the order using `OrderProcessor`.

#### Assert

Verify that the shipping method assigned by the processor matches the
expected shipping method supplied by the test parameter.

## Why Use a Parameterized Test?

Without parameterization, similar scenarios might require separate tests:

```text
Test normal item shipping
Test large item shipping
Test another normal item configuration
Test another large item configuration
With parameterized testing, the test logic is written once and executed with
multiple sets of inputs.

This reduces duplicated test code while increasing coverage.

Concepts Practiced
Google Test
Parameterized tests
Characterization testing
Arrange-Act-Assert
Testing multiple scenarios
Business-rule verification
Reducing duplicated test code
Regression protection