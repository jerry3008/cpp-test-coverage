
# Shopping Cart — Updating Item Quantity

## Requirement #10: Updating Item Quantity

Implement functionality that allows the quantity of an
existing shopping cart item to be updated.

## Objective

Provide an UpdateQuantity(id, quantity) method that updates
the quantity of a specific item.

Ensure GetItemCount() and GetTotal() reflect the updated quantity.

## Expected Behavior

- Locate an item using its ID.
- Replace its existing quantity with the new quantity.
- Update the total number of items in the cart.
- Recalculate the total price based on the updated quantity.

## Example

Item: Book
Unit Price: $10

Before Update:
- Quantity: 2
- Item Count: 2
- Total Price: $20

After UpdateQuantity(1, 3):
- Quantity: 3
- Item Count: 3
- Total Price: $30

## TDD Workflow

### Red

Write a failing test verifying that updating an item's
quantity changes both the item count and total price.

### Green

Implement the minimum functionality needed to pass the test.

### Refactor

Improve the implementation while keeping existing tests passing.

## Concepts Practiced

- Test-Driven Development
- Google Test
- Updating container elements
- State management
- Quantity calculations
- Regression testing
- C++ class methods
