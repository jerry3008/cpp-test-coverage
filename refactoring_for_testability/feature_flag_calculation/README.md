
# Feature Flag Order Calculation

This exercise introduces feature-flag-controlled pricing behavior
into the OrderProcessor class.

## Objective

Support three calculation modes while preserving the existing
order-processing behavior.

## Calculation Modes

- Normal: Use the existing order total.
- Discount: Apply a 10% discount.
- Surcharge: Apply a 15% surcharge.

## Example

For an order worth $100:

| Mode | Final Total |
|------|-------------|
| Normal | $100 |
| Discount | $90 |
| Surcharge | $115 |

## Implementation

The OrderProcessor selects the appropriate calculation behavior
based on the configured feature flag.

The Normal mode preserves the original calculation.

## Testing

The existing unit test verifies that the Normal mode continues
to produce the expected order total without modification.

Future tests can verify the Discount and Surcharge modes.

## Concepts Practiced

- Feature flags
- Conditional business logic
- Refactoring
- Behavior preservation
- Regression testing
- C++ enums and switch statements
- Testability
