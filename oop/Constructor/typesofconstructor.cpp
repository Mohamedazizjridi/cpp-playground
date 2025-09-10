#include<iostream>
using namespace std;
// constructor types in C++
// 1. Default constructor
// 2. Parameterized constructor
// 3. Copy constructor
// 4. Move constructor
// have the same name as the class and no return type + non return type
// in the public section of the class
class User{
    public:
        string firstname;
        string lastname;
        int age ;
        string email;
    // Default constructor  
    User(){};
    // Parameterized constructor
    User(string fn, string ln, int a, string em) {
        firstname = fn;
        lastname = ln;
        age = a;
        email = em;
    }    
};
int main(){
    User u1;
    u1.firstname = "John";
    u1.lastname = "Doe";
    u1.age = 30;
    u1.email = "john.doe@example.com";
}