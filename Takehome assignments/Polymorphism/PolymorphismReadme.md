# Polymorphism in C++

This example demonstrates **runtime polymorphism**: a base-class pointer can refer to objects of different derived classes, and a call to a virtual function runs the implementation that matches the actual object.

The class hierarchy in the program is:

```text
             Actuator
             /      \
     ServoMotor   StepperMotor
```

Both `ServoMotor` and `StepperMotor` publicly inherit from `Actuator`. They provide their own versions of the same motion function, so the control code can work with either type through the common `Actuator` interface.

## What each class does

### `Actuator` — base class

`Actuator` stores an `actuatorID` as a protected member. This lets derived classes use the identifier while keeping it unavailable to unrelated code. Its constructor initializes the ID.

The virtual `executeMotion()` method provides generic actuator behavior. Because it is declared `virtual`, calls made through an `Actuator` pointer can be dispatched to a derived-class implementation at runtime. The virtual destructor allows safe cleanup if derived objects are later managed through base-class pointers.

### `ServoMotor` — positional actuator

`ServoMotor` inherits from `Actuator` and adds a private `targetAngle`. Its constructor initializes the base-class ID and the target angle. It overrides `executeMotion()` to print a message about adjusting the PWM pulse to rotate to that angle at the requested speed.

The `override` specifier makes the compiler verify that this function overrides a virtual function from the base class.

### `StepperMotor` — step-based actuator

`StepperMotor` inherits from `Actuator` and adds a private `stepsPerRev` value. Its constructor initializes the base-class ID and the step count. Its `executeMotion()` override prints a message about pulsing the motor coils at the requested step frequency.

## How the program runs

In `main()`, the program creates a `ServoMotor` named `armJoint` with ID `Servo_SG90` and a target angle of 90 degrees, and a `StepperMotor` named `linearDrive` with ID `NEMA17_Stepper` and 200 steps per revolution.

First, an `Actuator*` pointer refers to `armJoint`, then to `linearDrive`. The same call, `actuatorPtr->executeMotion(...)`, invokes the matching derived implementation each time because `executeMotion()` is virtual.

Next, the program stores pointers to both objects in a `controlSystem` array and loops over it. Each iteration calls `executeMotion(50.0)` through an `Actuator*`. Although the call is written identically, runtime dispatch selects `ServoMotor::executeMotion()` for the servo and `StepperMotor::executeMotion()` for the stepper.

## Key idea

Polymorphism allows different derived objects to be controlled through one shared base-class interface. In this example, virtual dispatch selects behavior based on the actual object a base pointer refers to, so the control code does not need a separate call pattern for every actuator type.
