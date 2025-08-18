#include <iostream>
using namespace std;

void print(int x) {
    cout << "Printing int: " << x << endl;
}
void print(double x) {
    cout << "Printing double: " << x << endl;
}
void print(string s) {
    cout << "Printing string: " << s << endl;
}

int main() {
    print(10);        // Calls print(int)
    print(3.14);      // Calls print(double)
    print("Hello");   // Calls print(string)
    return 0;
}
