
# Shopping Cart — Remove Item

## Course Topic
Test-Driven Development in C++

## Requirement #5: Removing an Item

Implement functionality that allows a user to remove one
unit of an item from the shopping cart.

## Expected Behavior

When an item is removed:

- The item count decreases by one.
- The total price decreases by the item's unit price.
- The remaining quantity is preserved.
- An item with no remaining quantity is removed.

## Example

Item: Book
Unit Price: $10
Initial Quantity: 2

Before Removal:
- Item Count: 2
- Total Price: $20

After Removal:
- Item Count: 1
- Total Price: $10

## TDD Workflow

### Red
Write a failing test that verifies item removal.

### Green
Implement the minimum code required to pass the test.

### Refactor
Improve the implementation without changing behavior.

## Concepts Practiced

- Test-Driven Development
- Google Test
- Collection management
- Item quantity updates
- State consistency
- Regression testing
- C++ class methods
