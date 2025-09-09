# 📘 C++ Operator Overloading (Beginner → Advanced)

## 🔹 1. Basics
- Operator overloading lets you redefine operators (`+`, `-`, `[]`, etc.) for custom classes.
- You **cannot create new operators** or change **precedence/associativity**.

### Example: `+` Operator
```cpp
class Complex {
    double real, imag;
public:
    Complex(double r=0, double i=0): real(r), imag(i) {}
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

---

## 🔹 2. Member vs Non-Member
- **Member function**: when the left operand is your class.
- **Non-member (friend)**: when it isn’t (e.g. `operator<<` with `cout`).

### Example: `<<` Operator (non-member)
```cpp
#include <iostream>
class Complex {
    double real, imag;
public:
    Complex(double r=0, double i=0): real(r), imag(i) {}
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        return os << c.real << " + " << c.imag << "i";
    }
};
```

---

## 🔹 3. Unary Operators
- Pre/post increment, negation, logical NOT.

### Example: Pre/Post Increment
```cpp
class Counter {
    int value;
public:
    Counter(int v=0): value(v) {}
    // Pre-increment
    Counter& operator++() { ++value; return *this; }
    // Post-increment
    Counter operator++(int) { Counter tmp=*this; ++value; return tmp; }
};
```

---

## 🔹 4. Comparison Operators

### Example: `==` and `<`
```cpp
class Complex {
    double real, imag;
public:
    Complex(double r=0, double i=0): real(r), imag(i) {}
    bool operator==(const Complex& other) const {
        return real==other.real && imag==other.imag;
    }
    bool operator<(const Complex& other) const {
        return (real*real+imag*imag) < (other.real*other.real+other.imag*other.imag);
    }
};
```

---

## 🔹 5. Assignment & Compound Assignment

### Example: `=` and `+=`
```cpp
class Complex {
    double real, imag;
public:
    Complex(double r=0, double i=0): real(r), imag(i) {}
    Complex& operator=(const Complex& other) {
        real = other.real; imag = other.imag; return *this;
    }
    Complex& operator+=(const Complex& other) {
        real += other.real; imag += other.imag; return *this;
    }
};
```

---

## 🔹 6. Special Operators

### Example: Subscript `[]`
```cpp
class Array {
    int data[10];
public:
    int& operator[](int index) { return data[index]; }
};
```

### Example: Function Call `()`
```cpp
class Functor {
public:
    int operator()(int x, int y) { return x + y; }
};
```

### Example: Arrow `->`
```cpp
class PtrWrapper {
    int* ptr;
public:
    PtrWrapper(int* p): ptr(p) {}
    int* operator->() { return ptr; }
};
```

---

## 🔹 7. Conversion Operators

### Example: Class → Primitive
```cpp
class Complex {
    double real, imag;
public:
    Complex(double r=0, double i=0): real(r), imag(i) {}
    operator double() const { return real; } // converts to double
};
```

---

## 🔹 8. Best Practices
- Return **reference** for `=`, `+=`, etc.
- Use **const correctness**.
- Use `explicit` for constructors to avoid implicit conversions.
- Prefer **friend** for symmetric operators (`+`, `-`, `*`, etc.).

---

## 🔹 9. Operators You Can Overload
✅ `+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> <<= >>= [] () -> ->* new delete new[] delete[]`

❌ Cannot overload:  
`.` `.*` `::` `?:` `sizeof` `typeid`

---

## 🔹 10. Example: Custom String
```cpp
#include <iostream>
#include <cstring>
class MyString {
    char* str;
public:
    MyString(const char* s="") {
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }
    MyString operator+(const MyString& other) const {
        char* buffer = new char[strlen(str)+strlen(other.str)+1];
        strcpy(buffer, str);
        strcat(buffer, other.str);
        MyString temp(buffer);
        delete[] buffer;
        return temp;
    }
    bool operator==(const MyString& other) const {
        return strcmp(str, other.str)==0;
    }
    friend std::ostream& operator<<(std::ostream& os, const MyString& s) {
        return os << s.str;
    }
    ~MyString(){ delete[] str; }
};
```

---

📌 With operator overloading, you can make custom types behave like built-in types!
