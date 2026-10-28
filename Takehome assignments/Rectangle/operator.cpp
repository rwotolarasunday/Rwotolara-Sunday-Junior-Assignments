#include <iostream>
using namespace std;
class Point{
     

    public:
            int x;
        int y;
     Point(int x, int y) : x(x), y(y) {}
     Point operator+(const Point& other) const{
        return Point(x + other.x, y + other.y);
     }

};
int main(){
    Point p1(1,2);
    Point p2(1,2);
    Point p3 = p1 + p2;
    cout << "Result: (" << p3.x << ", " << p3.y << ")" << endl;
    return 0;
}