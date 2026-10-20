
# Feature Flag Parameter for OrderProcessor

This exercise extends the OrderProcessor class to accept a feature flag
directly through its process_order method.

## Objective

Allow callers to select the order calculation mode while preserving
the existing default behavior.

## Supported Modes

- Normal: Original order total
- Discount: 10% reduction
- Surcharge: 15% increase

## Implementation

The process_order method accepts an optional feature flag parameter.

When no flag is supplied, Normal mode is used.

This maintains backward compatibility with existing callers.

## Example

For an order worth $100:

| Mode | Final Total |
|------|-------------|
| Normal | $100 |
| Discount | $90 |
| Surcharge | $115 |

## Why This Matters

The processor can now support multiple pricing behaviors without
requiring separate processing methods.

The feature flag also creates a testable entry point for verifying
each calculation mode independently.

## Concepts Practiced

- Feature flags
- Optional function parameters
- Default arguments
- Backward compatibility
- Refactoring
- Behavior preservation
- Unit testing preparation



## Normal Feature Flag Test

This test verifies that explicitly selecting the Normal feature flag
produces the same result as using the default order-processing behavior.

### Objective

Ensure backward compatibility after introducing feature flags into
the process_order method.

### Arrange

Create equivalent orders with known prices and quantities.

### Act

Process one order without specifying a feature flag.

Process the other order with the Normal feature flag.

### Assert

Verify that:

- Both orders are processed successfully.
- Both orders produce the same total.
- The Normal mode does not apply a discount or surcharge.

### Why This Matters

Feature flags allow new functionality to be introduced without changing
existing application behavior.

This test protects the original order calculation while additional
calculation modes are introduced.

### Concepts Practiced

- Google Test
- Feature flag testing
- Default parameter behavior
- Backward compatibility
- Regression testing
- Arrange-Act-Assert



## Discount Feature Flag Test

This test verifies that OrderProcessor correctly applies a 10% discount
when the Discount feature flag is selected.

### Objective

Confirm that Discount mode reduces the original order total by 10%
without affecting the rest of the order-processing behavior.

### Arrange

Create an order containing items with known prices and quantities.

For example:

- Unit price: $100
- Quantity: 2
- Original total: $200

### Act

Process the order using the Discount feature flag.

### Assert

Verify that:

- The order is processed successfully.
- The final order total is $180.
- The correct 10% discount is applied.

### Calculation

Original total: $200
Discount: $200 × 0.10 = $20
Final total: $200 - $20 = $180

### Concepts Practiced

- Google Test
- Feature flag testing
- Discount calculations
- Arrange-Act-Assert
- Business-rule verification
- Regression testing


## Surcharge Feature Flag Test

This exercise completes the feature-flag testing suite by verifying
that OrderProcessor applies a 15% surcharge when Surcharge mode
is selected.

### Objective

Ensure that the Surcharge feature flag correctly increases
the original order total by 15%.

### Arrange

Create an order with known prices and quantities.

Example:
- Unit price: $100
- Quantity: 2
- Original total: $200

### Act

Process the order using the Surcharge feature flag.

### Assert

Verify that:
- Order processing succeeds.
- A 15% surcharge is applied.
- The final order total equals $230.

### Calculation

Original total: $200
Surcharge: $200 × 0.15 = $30
Final total: $200 + $30 = $230

## Completed Feature Flag Tests

| Feature Flag | Expected Behavior |
|--------------|-------------------|
| Normal | Preserve original total |
| Discount | Apply 10% discount |
| Surcharge | Apply 15% surcharge |

## Future Improvements

Additional calculation modes can be introduced by:

1. Defining a new feature flag.
2. Implementing the corresponding calculation behavior.
3. Adding unit tests to verify the new mode.

## Concepts Practiced

- Google Test
- Feature flag testing
- Surcharge calculations
- Regression testing
- Extensible business logic
- Arrange-Act-Assert
- Refactoring for testability
