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