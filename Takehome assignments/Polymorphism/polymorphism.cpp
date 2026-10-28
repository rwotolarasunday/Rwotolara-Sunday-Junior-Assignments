#include <iostream>
#include <string>

using namespace std;

// 1. Parent Class
class Actuator {
protected:
    string actuatorID;

public:
    Actuator(string id) : actuatorID(id) {}

    // Virtual member function enabling runtime polymorphism
    virtual void executeMotion(double intensity) const {
        cout << "[" << actuatorID << "] Executing generic actuator movement at " 
             << intensity << "% capacity..." << endl;
    }

    // Virtual destructor for safe cleanup when using base pointers
    virtual ~Actuator() {}
};

// 2. First Derived Class: ServoMotor
class ServoMotor : public Actuator {
private:
    int targetAngle;

public:
    ServoMotor(string id, int angle) : Actuator(id), targetAngle(angle) {}

    // Overriding the virtual function for positional PWM movement
    void executeMotion(double intensity) const override {
        cout << "[" << actuatorID << "] Adjusting PWM pulse to rotate to " 
             << targetAngle << " degrees at " << intensity << "% speed." << endl;
    }
};

// 3. Second Derived Class: StepperMotor
class StepperMotor : public Actuator {
private:
    int stepsPerRev;

public:
    StepperMotor(string id, int steps) : Actuator(id), stepsPerRev(steps) {}

    // Overriding the virtual function for discrete step sequence drive
    void executeMotion(double intensity) const override {
        cout << "[" << actuatorID << "] Pulsing motor coils for " 
             << stepsPerRev << " steps/rev at " << intensity << "% step frequency." << endl;
    }
};

int main() {
    // Create objects of derived classes
    ServoMotor armJoint("Servo_SG90", 90);
    StepperMotor linearDrive("NEMA17_Stepper", 200);

    // 4. Demonstrate runtime polymorphism using a single Base-Class Pointer
    cout << "--- Polymorphism via Base-Class Pointer ---" << endl;

    Actuator* actuatorPtr = nullptr; // Base class pointer

    // Point to ServoMotor object
    actuatorPtr = &armJoint;
    cout << "Pointer aimed at ServoMotor  -> ";
    actuatorPtr->executeMotion(75.0); // Executes ServoMotor::executeMotion

    // Point to StepperMotor object
    actuatorPtr = &linearDrive;
    cout << "Pointer aimed at StepperMotor -> ";
    actuatorPtr->executeMotion(100.0); // Executes StepperMotor::executeMotion

    // 5. Demonstrate runtime polymorphism inside a system array loop
    cout << "\n--- Polymorphism in a Control Array ---" << endl;

    Actuator* controlSystem[2] = { &armJoint, &linearDrive };

    for (int i = 0; i < 2; i++) {
        // The exact same line of code executes different behavior at runtime
        // based on the actual object the pointer references.
        controlSystem[i]->executeMotion(50.0);
    }

    return 0;
}