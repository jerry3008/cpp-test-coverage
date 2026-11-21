
# Shopping Cart — Clearing All Items

## Requirement #9: Clearing All Items

Implement functionality to remove all items from the
shopping cart using Test-Driven Development.

## Objective

Provide a Clear() method that resets the shopping cart
to an empty state.

## Expected Behavior

After calling Clear():

- All items are removed.
- GetItemCount() returns 0.
- GetTotal() returns 0.

## Example

Before Clear():
- Book: $10 × 2
- Pen: $5 × 3
- Item Count: 5
- Total: $35

After Clear():
- Item Count: 0
- Total: $0

## TDD Workflow

### Red
Write a failing test for clearing a cart containing
multiple items.

### Green
Implement the minimum code required to make the test pass.

### Refactor
Improve the implementation while preserving existing behavior.

## Concepts Practiced

- Test-Driven Development
- Google Test
- Container management
- State reset
- Regression testing
- C++ class methods
