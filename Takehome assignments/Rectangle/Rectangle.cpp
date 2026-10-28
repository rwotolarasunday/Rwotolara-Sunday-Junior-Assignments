#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;

    // These getters are private because only the class itself needs them.
    // Outside code cannot call getWidth or getLength directly.
    double getWidth() const {
        return width;
    }

    double getLength() const {
        return length;
    }

public:
    // Default constructor. Starts the rectangle with zero width and zero length.
    Rectangle() {
        width = 0.0;
        length = 0.0;
    }

    // Setter for width. Public so the user can set it from main.
    void setWidth(double w) {
        width = w;
    }

    // Setter for length. Same idea as setWidth.
    void setLength(double l) {
        length = l;
    }

    // Area is width times length. It calls the private getters instead of
    // touching width and length directly, which keeps the logic in one place.
    double getArea() const {
        return getWidth() * getLength();
    }

    // Perimeter is two times (width plus length).
    double getPerimeter() const {
        return 2 * (getWidth() + getLength());
    }
};

int main() {
    // Make a rectangle object.
    Rectangle myRectangle;

    // Set the two dimensions using the public setters.
    myRectangle.setWidth(5.5);
    myRectangle.setLength(10.0);

    // Call the public methods and print the results.
    cout << "Rectangle Dimensions: 5.5 x 10.0\n";
    cout << "Area: " << myRectangle.getArea() << "\n";
    cout << "Perimeter: " << myRectangle.getPerimeter() << "\n";

    return 0;
}
