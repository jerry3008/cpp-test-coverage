# Preparing OrderDatabase for Mocking

This exercise prepares the database dependency used by `OrderProcessor`
for future mocking and isolated unit testing.

## Objective

The existing `OrderProcessor` is directly coupled to the concrete
`OrderDatabase` implementation.

Because `OrderDatabase` performs real database operations, this dependency
makes isolated unit testing difficult.

The goal of this exercise is to introduce an interface for database
operations while preserving the existing application behavior.

## Design

The database dependency evolves from:

```text
OrderProcessor
      |
      v
OrderDatabase

to:

OrderProcessor
      |
      v
OrderDatabase
      |
      v
IOrderDatabase

At this stage, OrderProcessor is not changed to depend on the interface.

Instead, OrderDatabase is prepared by implementing the new
IOrderDatabase abstraction.

Why This Matters

The interface defines a contract for database operations without requiring
consumers to know how those operations are implemented.

A later refactoring can allow OrderProcessor to depend on the abstraction:

              IOrderDatabase
                /        \
               /          \
      OrderDatabase    MockOrderDatabase
          REAL              TEST

Production code can use the real database implementation, while tests can
eventually provide a mock implementation that performs no actual database
operations.

Concepts Practiced
C++ interfaces
Abstract classes
Pure virtual functions
Dependency inversion
Dependency isolation
Preparing dependencies for mocking
Testability
Refactoring legacy code

The conceptual C++ change is something along these lines:

```cpp
class IOrderDatabase
{
  
  public:
    virtual Order GetOrderById(int order_id) = 0;
    virtual  void UpdateOrder(const Order& od) = 0;
    virtual ~IOrderDatabase() = default;
};

and then:

class OrderDatabase : public IOrderDatabase
{
    public:
        Order GetOrderById(int order_id) override {
            std::cout << "[Database Operation] Should not happen in tests!" << std::endl;
            return Order{order_id};
        }

        void UpdateOrder(const Order& order) override{
            std::cout << "[Database Operation] Should not happen in tests!" << std::endl;
        }
};