
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
