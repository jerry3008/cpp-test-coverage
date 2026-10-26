
# Implementing Order Processing with Surcharges

## Course
Using the Sprout Method for Safe Code Refactoring in C++

## Objective
Introduce surcharge processing into an existing order-processing
system using the Sprout Method.

## Problem
Adding new functionality directly to existing code can introduce
regressions and make testing more difficult.

## Approach
Use the Sprout Method to implement new surcharge functionality
in a separate method while preserving existing behavior.

## Implementation
- Review the existing OrderProcessor implementation.
- Implement the new surcharge-processing method.
- Preserve the existing order-processing logic.
- Prepare for additional unit tests in subsequent exercises.

## Testing
Upcoming exercises will introduce test coverage for the new
surcharge-processing method.

## Concepts Practiced
- C++ refactoring
- Sprout Method
- Legacy code maintenance
- Separation of concerns
- Regression prevention
- Unit testing




## Parameterized Surcharge Tests

### Objective

Verify that the surcharge-processing method correctly handles
multiple valid surcharge values using Google Test parameterization.

### Approach

Instead of writing individual tests for each surcharge value,
we use one parameterized test with multiple input combinations.

Each test case supplies:
- A surcharge value
- An expected order total

### Testing Strategy

The test follows the Arrange-Act-Assert pattern:

1. Arrange an order with a known initial total.
2. Act by processing the order using the specified surcharge.
3. Assert that the final order total matches the expected result.

### Benefits

- Reduces duplicated test code
- Improves test coverage
- Makes additional test cases easier to introduce
- Helps verify consistent behavior
- Supports safe refactoring

### Concepts Practiced

- C++ Google Test
- Parameterized testing
- TestWithParam
- TEST_P
- INSTANTIATE_TEST_SUITE_P
- Sprout Method
- Regression testing
- Boundary-value testing

## Lesson Summary

This lesson demonstrated how to safely extend existing
order-processing functionality using the Sprout Method.

New surcharge behavior was introduced separately from the
existing processing logic and verified through unit tests.

Parameterized tests further improved coverage by validating
multiple surcharge values without duplicating test logic.

