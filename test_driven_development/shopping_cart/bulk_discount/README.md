
# Shopping Cart — Bulk Discount

## Requirement #8: Applying a Bulk Discount

Implement an automatic 10% discount when the total price
of items in the shopping cart exceeds $150.

## Objective

Ensure that GetTotal() applies the bulk discount automatically
when the cart meets the required threshold.

## Business Rules

- Subtotals of $150 or less receive no bulk discount.
- Subtotals greater than $150 receive a 10% discount.
- The discount is applied automatically.
- The original item prices remain unchanged.

## Example

Item: Book
Unit Price: $200
Quantity: 1

Original Total: $200
Bulk Discount: $20
Final Total: $180

## TDD Workflow

### Red
Write a failing test verifying that a $200 cart returns $180.

### Green
Implement the minimum logic required to apply the discount.

### Refactor
Improve the implementation while keeping all tests passing.

## Test Cases

| Subtotal | Expected Total |
|----------|----------------|
| $100 | $100 |
| $150 | $150 |
| $151 | $135.90 |
| $200 | $180 |
| $300 | $270 |

## Concepts Practiced

- Test-Driven Development
- Google Test
- Conditional business rules
- Boundary-value testing
- Percentage calculations
- Regression testing
- C++ class methods
