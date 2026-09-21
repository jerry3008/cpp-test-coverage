# Extracting Inline Dependencies

This exercise refactors `OrderProcessor` to improve how its dependencies are
managed.

## Problem

The existing implementation creates new `DatabaseConnection` and
`PaymentGateway` objects every time an order is processed.

Conceptually:

```text
ProcessOrder()
    -> create DatabaseConnection
    -> create PaymentGateway
    -> process order
Repeated calls therefore repeatedly create the same types of dependencies.

Refactoring

The database connection and payment gateway are moved from local variables
inside the processing method to read-only fields of OrderProcessor.

This allows the processor to reuse the same dependency objects across
multiple calls.

Before
OrderProcessor
    |
    +-- ProcessOrder()
          |
          +-- new DatabaseConnection
          +-- new PaymentGateway
After
OrderProcessor
    |
    +-- DatabaseConnection
    |
    +-- PaymentGateway
    |
    +-- ProcessOrder()
    +-- ProcessOrder()
    +-- ProcessOrder()

The dependencies belong to the processor rather than being recreated inside
each processing operation.

Benefits
Avoids unnecessary object creation
Reuses dependencies across processing calls
Makes dependency ownership clearer
Improves code organization
Prepares the class for further dependency-injection refactoring
Concepts Practiced
Refactoring
Dependency management
Object lifetime
Class fields
Read-only dependencies
Separation of concerns
Preparing legacy code for testability