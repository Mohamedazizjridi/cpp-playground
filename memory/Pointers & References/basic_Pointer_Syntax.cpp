#include <iostream>
using namespace std;

int main() {
    // Step 1: Create a regular variable
    int age = 25;
    
    // Step 2: Create a pointer variable
    int* ptr;  // This pointer can store address of an int
    
    // Step 3: Store the address
    ptr = &age;  // ptr now holds the address of age
    
    // Let's see what we have:
    cout << "Value of age: " << age << endl;         // 25
    cout << "Address of age: " << &age << endl;      // 0x7fff5694a7b4 (some address)
    cout << "Value of ptr: " << ptr << endl;         // 0x7fff5694a7b4 (same address!)
    cout << "Value at ptr: " << *ptr << endl;        // 25 (accessing age through ptr)
    
    return 0;
}
