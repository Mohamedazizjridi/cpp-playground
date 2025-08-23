/*
Types of Smart Pointers
C++ libraries provide implementations of smart pointers in the following types:

              auto_ptr
              unique_ptr
              shared_ptr
              weak_ptr

*/
/////////////////////////////////////////////////////////////////////// auto_ptr/////////////////////////////////////////////////////////////////////////////////////
// 1. auto_ptr
// In C++, auto_ptr is a smart pointer that automatically manages the lifetime of a dynamically allocated object. It takes ownership of the object it points to, ensuring that the object is automatically deleted when the auto_ptr goes out of scope.

//       Syntax:
//       auto_ptr <type> name;
//       where,
//       type: Pointer type.
//       name: Name assigned to the pointer.

#include <iostream>
#include <memory>
using namespace std;

int main() {
    
    // Pointer declaration
    auto_ptr<int> ptr1(new int(10));
    cout << *ptr1 << endl;
    
    // Transfer ownership to
    // pointer ptr2, 
    auto_ptr<int> ptr2 = ptr1;
    cout << *ptr2;
    return 0;
}
////////////////////////////////////////////////////////////////////unique_ptr/////////////////////////////////////////////////////////////////////////////////////
// 2. unique_ptr
// unique_ptr stores one pointer only at a time. We cannot copy unique_ptr, only transfer ownership of the object to another unique_ptr using the move() method.
#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() { return length * breadth; }
};

int main() {

    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl;

    unique_ptr<Rectangle> P2;

    // Copy the addres of P1 into p2
    P2 = move(P1);
    cout << P2->area();
    return 0;
}

////////////////////////////////////////////////////////// shared_ptr //////////////////////////////////////////////////////////////////////////////////////////////


// 3. shared_ptr
// By using shared_ptr, more than one pointer can point to same object at a time, and it will maintain a reference counter using the use_count() method.
#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() { return length * breadth; }
};

int main() {
    
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl;

    shared_ptr<Rectangle> P2;
    
    // P1 and P2 are pointing 
    // to same object
    P2 = P1;
    cout << P2->area() << endl;
    cout << P1->area() << endl;
    cout << P1.use_count();
    return 0;
}
//////////////////////////////////////////////////// Weak_ptr/////////////////////////////////////////////////////////////////////////////////////////////////////

// weak_ptr is a smart pointer that holds a non-owning reference to an object. 
// It's much more similar to shared_ptr except it will not maintain a reference counter. In this case, a pointer will not have a stronghold on the object. 
// The reason is to avoid the circular dependency created by two or more object pointing to each other using shared_ptr.




#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() { return length * breadth; }
};

int main() {
    
    // Create shared_ptr Smart Pointer
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    
    // Created a weak_ptr smart pointer
    weak_ptr<Rectangle> P2 (P1);
    cout << P1->area() << endl;
    
    // Returns the number of shared_ptr 
    // objects that manage the object
    cout << P2.use_count();
    return 0;
}










