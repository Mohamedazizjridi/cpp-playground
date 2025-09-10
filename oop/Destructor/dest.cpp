#include <iostream>
using namespace std;
// destructor in C++
// destructor is a special member function of the class
// it is used to destroy the objects of the class
// it is called automatically when the object goes out of scope
// it has the same name as the class but is preceded by a tilde (~)
// it has no return type and no parameters
// one per class +must be placed in the public section of the class
class Book{
    public:
        string title;
        string author;
        int* rate;
        int ratecount;
    Book(string t, string a){
        ratecount = 2;
        rate = new int[ratecount]; // dynamically allocate memory for ratings
        rate[0] = 5; // example ratings
        rate[1] = 4;
        title = t;
        author = a;
    }
    // destructor
    ~Book(){
        delete [] rate; // free dynamically allocated memory
        rate =nullptr; // avoid dangling pointer
        cout << "Destructor called for book: " << title << endl;
    }
};
int main(){
    Book b1("1984", "George Orwell");
    Book b2("To Kill a Mockingbird", "Harper Lee");
    cout << "Book 1: " << b1.title << " by " << b1.author << endl;
    cout << "Book 2: " << b2.title << " by " << b2.author << endl;
    // destructors will be called automatically here when b1 and b2 go out of scope
   // b2 is destroyed first followed by b1
    return 0;
}