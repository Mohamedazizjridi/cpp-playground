#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r=0, double i=0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
     // Member version (not recommended)
    // Left operand is the object itself, so usage is reversed: c1 << cout;
    ostream& operator<<(ostream& os) {
        os << real << " + " << imag << "i";
        return os;
    }

   // Friend version (recommended)
    // Left operand is the ostream, right operand is the object: cout << c1;
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    // Overload >> operator
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real and imaginary parts: ";
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    Complex c1(1.5, 2.5), c2(2.0, 3.5);
    Complex c3 = c1 + c2;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c3 << endl;

    Complex c4;
    cin >> c4;
    cout << "You entered: " << c4 << endl;

   // Using member version (weird and nonstandard)
    // c1 << cout;  
    return 0;
}
