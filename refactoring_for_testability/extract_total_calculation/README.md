README

Put this in README.md:

# Extract Default Order Total Calculation

This exercise refactors the order-total calculation logic inside
`OrderProcessor`.

## Objective

The existing `process_order` method contains the logic responsible for
calculating the total value of an order.

The calculation is extracted into a dedicated private method:

`default_total_calculation`

## Refactoring

Before:

```text
process_order
    |
    +-- calculate order total
    +-- process remaining order logic

After:

process_order
    |
    +-- default_total_calculation
    |       |
    |       +-- calculate order total
    |
    +-- process remaining order logic
Behavior Preservation

This is a refactoring exercise.

The observable behavior of OrderProcessor should not change, and the
existing test suite should continue to pass without modification.

Why This Matters

Extracting the calculation into a dedicated method:

Separates responsibilities
Makes process_order easier to understand
Creates a seam in the existing implementation
Makes future changes to calculation behavior easier
Reduces the risk of modifying unrelated order-processing logic
Concepts Practiced
Refactoring
Extract Method
Creating seams
Separation of concerns
Behavior preservation
Regression testing
Improving legacy code