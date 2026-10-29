
# Extract Payment Logic into a Private Method

## Objective

Improve the OrderProcessor class by extracting payment-processing
logic into a dedicated private method.

## Refactoring Approach

The original process_order method contains payment logic alongside
other order-processing responsibilities.

This exercise moves the payment logic into a private helper method
while preserving the existing behavior.

## Benefits

- Improves readability
- Reduces method complexity
- Separates responsibilities
- Makes future changes easier
- Supports regression testing
- Prepares payment logic for further refactoring

## Concepts Practiced

- C++ private methods
- Extract Method refactoring
- Encapsulation
- Separation of concerns
- Legacy code maintenance
- Behavior-preserving refactoring

## Testing

Existing tests should continue to pass without modification.

The extraction should not change payment outcomes or other
order-processing behavior.
