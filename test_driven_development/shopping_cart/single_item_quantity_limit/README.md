
# Shopping Cart — Single Item Quantity Limit

## Requirement #11: Quantity Limit for Single Item

Implement a maximum quantity restriction for individual
items in the shopping cart using Test-Driven Development.

## Objective

Prevent customers from adding more than 10 units
of a single item type.

## Expected Behavior

- Quantities from 1 through 10 are permitted.
- Quantities greater than 10 are rejected.
- An exception is thrown when the limit is exceeded.
- The exception message is "Maximum quantity exceeded".
- Rejected additions should not modify the cart.

## Example

Item: Book
Unit Price: $10
Requested Quantity: 11

Expected Result:
Exception: Maximum quantity exceeded

## TDD Workflow

### Red

Write a failing test verifying that adding 11 units
throws the expected exception.

### Green

Implement the minimum validation logic required
to make the test pass.

### Refactor

Improve the implementation while preserving
the existing shopping cart behavior.

## Additional Test Cases

| Quantity | Expected Result |
|----------|-----------------|
| 1 | Accepted |
| 5 | Accepted |
| 10 | Accepted |
| 11 | Exception |
| 15 | Exception |

## Concepts Practiced

- Test-Driven Development
- Google Test
- Exception handling
- Input validation
- Boundary-value testing
- Business-rule enforcement
- Regression testing
