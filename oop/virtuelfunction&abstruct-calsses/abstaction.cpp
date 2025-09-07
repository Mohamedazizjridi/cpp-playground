// abstraction : the process of hiding the implementation 
// details and showing only the essential features of the object
// it is achieved using abstract class and pure virtual function
#include <iostream>
using namespace std;
// cannot cerate instance of abstract class
// can create pointer of abstract class

// importance of abstraction
// 1. it helps to reduce complexity
// 2. it helps to increase reusability
// 3. it helps to increase security of the application
class smartPhone
{
    public:
        virtual void takeselfie()=0; // pure virtual function
        virtual void makeCall()=0; // pure virtual function
    
};
class android : public smartPhone{
    public:
        void takeselfie(){
            cout<<"android takes selfie"<<endl;
        }
        void makeCall(){
            cout<<"android makes call"<<endl;
        }
};

int main(){
    smartPhone* s1 = new android();
    s1->takeselfie();
    s1->makeCall();
    delete s1;
    return 0;
}
