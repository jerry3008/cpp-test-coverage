
# Interface Segregation Principle — Notification System

## Overview

This exercise introduces the Interface Segregation Principle (ISP)
by refactoring a notification system with an oversized interface.

## Problem

The original INotificationService interface contains methods for:

- Sending notifications
- Validating notifications
- Logging notifications
- Storing notifications

This design combines multiple responsibilities into one interface.

## Objective

Introduce smaller interfaces to separate notification logging
and storage responsibilities.

## Interfaces

### INotificationLogger

Defines the contract for logging notifications.

### INotificationStorage

Defines the contract for storing notifications.

### INotificationService

Retains notification-related behavior and reuses the new
interfaces as required by the exercise.

## Concepts Practiced

- SOLID principles
- Interface Segregation Principle
- Abstract classes
- Pure virtual functions
- Interface inheritance
- Separation of concerns
- C++ object-oriented design

## Key Takeaway

Prefer focused interfaces that allow classes to depend only
on the functionality they actually require.
