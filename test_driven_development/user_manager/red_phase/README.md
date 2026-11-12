
# UserManager — TDD Red Phase

## Course Topic

Test-Driven Development with Dependency Injection in C++

## Objective

Begin testing the UserManager component by writing a failing
test that defines the expected user-management behavior.

## Scenario

The UserManager should support adding users and retrieving
previously added users.

Future exercises will introduce dependency injection and
a fake logger to verify logging behavior.

## Red Phase

The first step of TDD is to write a test before implementing
the functionality.

The test should:

1. Arrange a UserManager and sample user.
2. Act by adding the user.
3. Assert that the expected behavior occurs.
4. Fail until the implementation supports that behavior.

## Upcoming Phases

### Green

Implement the minimum functionality required to pass the test.

### Refactor

Improve the implementation while preserving passing tests.

## Concepts Practiced

- Test-Driven Development
- Red-Green-Refactor
- Google Test
- Unit testing
- Dependency injection preparation
- Test doubles
- Behavior-driven test design
