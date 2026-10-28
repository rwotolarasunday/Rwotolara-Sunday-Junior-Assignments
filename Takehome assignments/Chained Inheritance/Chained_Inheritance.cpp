#include <iostream>
#include <string>

using namespace std;

// 1. Base Class: Device
class Device {
private: 
    string brand;
    bool isPoweredOn;

public:
    // Constructor
    Device(string b) {
        brand = b;
        isPoweredOn = false;
    }

    // Member function local to Device
    void togglePower() {
        isPoweredOn = !isPoweredOn;
        if (isPoweredOn) {
            cout << brand << " device is now turning ON." << endl;
        } else {
            cout << brand << " device is now turning OFF." << endl;
        }
    }

    const string& getBrand() const {
        return brand;
    }
};

// 2. Intermediate Derived Class: Computer (Inherits from Device)
class Computer : public Device {
private:
    string processor;
    int ramSize;

public:
    // Constructor chaining to the Base class
    Computer(string b, string cpu, int ram) : Device(b) {
        processor = cpu;
        ramSize = ram;
    }

    // Member function local to Computer
    void runDiagnostics() {
        cout << "Running diagnostics on " << processor << " with " << ramSize << "GB RAM..." << endl;
    }

    const string& getProcessor() const {
        return processor;
    }

    int getRamSize() const {
        return ramSize;
    }
};

// 3. Final Derived Class: Laptop (Inherits from Computer)
class Laptop : public Computer {
private:
    int batteryPercentage;
    double weightKg;

public:
    // Constructor chaining to the Intermediate class
    Laptop(string b, string cpu, int ram, int battery, double weight) 
        : Computer(b, cpu, ram) {
        batteryPercentage = battery;
        weightKg = weight;
    }

    // Member function local to Laptop
    void displayFullSpecs() {
        cout << "\n--- Laptop Specifications ---" << endl;
        // Accessing 'brand' inherited from Device
        cout << "Brand: " << getBrand() << endl; 
        // Accessing 'processor' and 'ramSize' inherited from Computer
        cout << "CPU: " << getProcessor() << " | RAM: " << getRamSize() << "GB" << endl; 
        // Accessing local members
        cout << "Battery: " << batteryPercentage << "% | Weight: " << weightKg << "kg" << endl;
        cout << "-----------------------------\n" << endl;
    }
    
    void chargeBattery() {
        cout << "Charging laptop battery from " << batteryPercentage << "% to 100%..." << endl;
        batteryPercentage = 100;
    }
};

int main() {
    // 4. Create an object of the final derived class
    Laptop myWorkLaptop("Dell XPS", "Intel Core i7", 16, 45, 1.2);

    // Demonstrate inherited members from Device
    myWorkLaptop.togglePower(); 

    // Demonstrate locally defined members in Laptop (which also use inherited variables)
    myWorkLaptop.displayFullSpecs();

    // Demonstrate inherited members from Computer
    myWorkLaptop.runDiagnostics();

    // Demonstrate locally defined member in Laptop
    myWorkLaptop.chargeBattery();

    // Turn off (Inherited from Device)
    myWorkLaptop.togglePower();

    return 0;
}