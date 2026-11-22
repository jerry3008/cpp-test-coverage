
# Shopping Cart — Retrieving Item Details by ID

## Requirement #12: Retrieving Item Details by ID

Implement functionality that allows individual shopping cart
items to be retrieved using their unique product IDs.

## Objective

Provide a GetItem(id) method that returns the correct
product information and quantity stored in the cart.

## Expected Behavior

- Add an item with a specific product ID.
- Retrieve the item using GetItem(id).
- Return the correct product ID, name, price, and quantity.
- Preserve the existing shopping cart functionality.

## Example

Product ID: 1
Product Name: Book
Unit Price: $10
Quantity: 1

Expected GetItem(1) result:

{ Id: "1", Name: "Book", Price: 10, Quantity: 1 }

## TDD Workflow

### Red

Write a failing test that retrieves an item by ID and
verifies its properties.

### Green

Implement the minimum code required for GetItem(id)
to return the correct item.

### Refactor

Improve the implementation without changing existing behavior.

## Concepts Practiced

- Test-Driven Development
- Google Test
- Object retrieval
- Collection lookups
- Product identifiers
- Data integrity
- C++ class methods
- Regression testing
