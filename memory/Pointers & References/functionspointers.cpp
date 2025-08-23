#include <iostream>
using namespace std;

// Different operations
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
int power(int a, int b) { 
    int result = 1;
    for(int i = 0; i < b; i++) result *= a;
    return result;
}

// Function that accepts another function as parameter
int calculate(int x, int y, int (*operation)(int, int)) {
    return operation(x, y);
}

int main() {
    cout << "Add: " << calculate(5, 3, add) << endl;           // 8
    cout << "Multiply: " << calculate(5, 3, multiply) << endl; // 15
    cout << "Power: " << calculate(5, 3, power) << endl;       // 125
    
    return 0;
}
