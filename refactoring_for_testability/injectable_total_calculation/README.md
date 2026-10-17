# Injectable Order Total Calculation

This exercise makes the order-total calculation behavior of `OrderProcessor`
configurable.

## Objective

The previous exercise extracted the existing order-total logic into:

`default_total_calculation`

This exercise allows `process_order` to optionally receive an alternative
calculation function.

## Default Behavior

When no calculation function is supplied, `OrderProcessor` continues to use:

`default_total_calculation`

This preserves the existing behavior of the application.

## Custom Behavior

A caller can provide an alternative calculation function when different
pricing behavior is required.

Conceptually:

```text
                    process_order
                         |
              +----------+----------+
              |                     |
        No function             Function provided
              |                     |
              v                     v
 default_total_calculation    custom calculation

 Why This Matters

The calculation algorithm is no longer permanently embedded in the order
processing workflow.

Different calculation strategies can be supplied without rewriting the
entire OrderProcessor.

This also creates a useful testing seam because tests can provide controlled
calculation behavior.

Concepts Practiced
std::function
Function parameters
Behavior injection
Default behavior
Creating seams
Dependency injection
Refactoring for testability
Separation of concerns
Strategy-like behavior




## Surcharge Calculation Test

This test verifies that `OrderProcessor` can use an alternative order-total
calculation function.

### Scenario

A custom calculation function is supplied to `process_order` that applies
a surcharge to the normal order total.

### Test Flow

The test follows the Arrange-Act-Assert pattern.

#### Arrange

Create an order containing known items and define a custom calculation
function that applies the required surcharge.

#### Act

Pass the custom calculation function to `process_order`.

#### Assert

Verify that the resulting order total includes the expected surcharge.

## Why This Test Matters

Previously, order-total calculation behavior was embedded directly inside
`process_order`.

The implementation was gradually refactored by:

1. Extracting the default calculation into its own method.
2. Allowing an alternative calculation function to be supplied.
3. Testing the processor with custom calculation behavior.

The `OrderProcessor` can now support different pricing calculations without
changing its core order-processing logic.

## Concepts Practiced

- `std::function`
- Lambdas
- Behavior injection
- Testing seams
- Arrange-Act-Assert
- Refactoring for testability
- Custom calculation strategies
- Behavior preservation