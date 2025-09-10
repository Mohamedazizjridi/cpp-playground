#include <iostream>
using namespace std;
// interfaces in C++ contract for what a class can do :  define set of methods that the class must implement
// interface is a class that has only pure virtual functions
// a pure virtual function is a virtual function that has no implementation
// it is declared by assigning 0 to the function declaration
// a class that inherits from an interface must implement all the pure virtual functions of the interface
class Shape {
    public:
        virtual void draw() = 0; // pure virtual function
        virtual double area() = 0; // pure virtual function
};  
class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
        void draw() override {
            cout << "Drawing a circle with radius: " << radius << endl;
        }
        double area() override {
            return 3.14159 * radius * radius;
        }
};  
int main() {
    Shape* shape = new Circle(5.0);
    shape->draw();
    cout << "Area: " << shape->area() << endl;
    delete shape;
    return 0;
}