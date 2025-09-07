#include <iostream>
using namespace std;
// pure virtual function : a virtual function in base class which is declared using 0
// function  that not defined in the base class and must be overridden in derived class
// abstract class : a class that has at least one pure virtual function
// we cannot create object of abstract class
class instrument
{
public:
    virtual void makeSound()=0; // pure virtual function
};
// drived class
class Accordion : public instrument
{
    public :
        void makeSound()
        {
            cout << "Accordion is playing " << endl;
        }
};
int main(){
    instrument* i1 = new Accordion();
    i1->makeSound();
    delete i1;
    return 0;
}

