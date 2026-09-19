# UpdateOrderDate gMock Test

This exercise uses Google Mock (gMock) to unit test the `UpdateOrderDate`
behavior of `OrderProcessor` without accessing a real database.

## Objective

Verify the behavior of `UpdateOrderDate` when the requested order exists.

The test uses a mock implementation of `IOrderDatabase` to control database
responses and verify interactions.

## Test Flow

### Arrange

Create a test order containing basic information such as:

- Order ID
- Customer name
- Customer email

Configure the mock database to return the test order when `OrderProcessor`
requests it.

Set expectations for the database operations that should occur.

### Act

Call `UpdateOrderDate` on the `OrderProcessor`.

### Assert

Verify that:

- `UpdateOrderDate` returns the expected result.
- The order is retrieved from the database.
- The expected database update operation occurs.
- No real database access is required.

## gMock Expectations

Google Mock's `EXPECT_CALL` allows the test to describe how a dependency
should be used.

For example:

```cpp
EXPECT_CALL(*mock_order_database_,  GetOrderById(order_id)).WillOnce(::testing::Return(order1));
EXPECT_CALL(*mock_order_database_, UpdateOrder(::testing::_)).Times(1);
This both controls the mock's behavior and verifies that the expected
interaction occurs.

Why This Matters

The test isolates OrderProcessor from external database infrastructure.

Instead of:

OrderProcessor -> Real Database

the test uses:

OrderProcessor -> IOrderDatabase -> MockOrderDatabase

This makes the test faster, deterministic, and safe to run repeatedly.

Concepts Practiced
Google Test
Google Mock
EXPECT_CALL
WillOnce
Return
Mock expectations
Interaction testing
Dependency injection
Test isolation