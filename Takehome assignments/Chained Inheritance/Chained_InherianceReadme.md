# Chained Inheritance in C++

This example demonstrates **chained inheritance**: a class inherits from a class that is itself derived from another class. The inheritance chain in the program is:

```text
Device -> Computer -> Laptop
```

`Computer` inherits from `Device`, and `Laptop` inherits from `Computer`. As a result, a `Laptop` object can use public members declared by `Computer` and `Device`, as well as its own members.

## What each class does

### `Device` — base class

`Device` stores a device's `brand` and whether it is powered on. Both data members are private, so other classes cannot access them directly. Its public `togglePower()` method changes the power state and prints whether the device is turning on or off. `getBrand()` provides read-only access to the brand.

### `Computer` — intermediate derived class

`Computer` publicly inherits from `Device` and adds a processor name and RAM size. Its constructor accepts the device brand, processor, and RAM size. The initializer `: Device(b)` passes the brand to the base-class constructor before initializing the computer-specific data.

`runDiagnostics()` prints the computer's processor and RAM. The `getProcessor()` and `getRamSize()` methods let derived classes read those private members.

### `Laptop` — final derived class

`Laptop` publicly inherits from `Computer`, and therefore also gets access to the public interface inherited from `Device`. It adds a battery percentage and weight. Its constructor passes the brand, processor, and RAM to `Computer` with `: Computer(b, cpu, ram)`, then initializes the laptop-specific values.

`displayFullSpecs()` prints information from all three levels of the chain. It uses getters to access the private members of `Device` and `Computer`, and reads its own private members directly. `chargeBattery()` prints a charging message and sets the battery percentage to 100.

## How the program runs

In `main()`, the program creates `myWorkLaptop` with the following values:

| Property | Value |
|---|---|
| Brand | Dell XPS |
| Processor | Intel Core i7 |
| RAM | 16 GB |
| Battery | 45% |
| Weight | 1.2 kg |

The constructor calls happen from the top of the inheritance chain down: `Device` is initialized first, then `Computer`, and finally `Laptop`. The program then:

1. Calls the inherited `togglePower()` method to turn the device on.
2. Calls `displayFullSpecs()` to show the brand, processor, RAM, battery, and weight.
3. Calls the inherited `runDiagnostics()` method from `Computer`.
4. Calls `chargeBattery()` to set the battery to 100%.
5. Calls `togglePower()` again to turn the device off.

The specifications are displayed before the battery is charged, so the displayed battery value is `45%`. The program does not print the updated battery percentage afterward.

## Key idea

Chained inheritance lets a derived class build on functionality from multiple levels without duplicating it. `Laptop` uses laptop-specific behavior, computer behavior, and device behavior through one inheritance chain. In this example, **public inheritance** preserves the public interfaces of the base classes, while private data stays encapsulated and is read through public getter methods.
