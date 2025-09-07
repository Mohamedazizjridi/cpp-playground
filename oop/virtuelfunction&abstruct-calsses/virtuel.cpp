// virtual function
// pure virtual function
// abstract class
#include <iostream>
using namespace std;
// virtual function : a function in base class which is overridden in derived class
// it is declared using virtual keyword
// it is used to achieve runtime polymorphism
// if a base class pointer is used to point to a derived class object
// then the derived class function is called
// if the function is declared as virtual in base class
// if the function is not declared as virtual in base class
// then the base class function is called
class instrument
{
public:
    virtual void makeSound()
    {
        cout << "instrument is playing " << endl;
    }
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

