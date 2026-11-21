
# Shopping Cart — Percentage Discount

## Requirement #7: Applying Percentage Discount

Implement percentage-based discounts in the ShoppingCart class
using Test-Driven Development.

## Objective

Allow the shopping cart to apply a percentage discount
to its total price.

## Expected Behavior

- ApplyDiscount(percentage) sets the discount percentage.
- GetTotal() returns the discounted cart total.
- A 10% discount on a $100 cart produces a total of $90.

## Formula

Discounted Total = Subtotal × (1 - Percentage / 100)

## TDD Workflow

### Red
Write a failing test for applying a 10% discount.

### Green
Implement the minimum functionality required to pass the test.

### Refactor
Improve the implementation while preserving existing behavior.

## Concepts Practiced

- Test-Driven Development
- Google Test
- Percentage calculations
- State management
- Regression testing
- C++ class methods
