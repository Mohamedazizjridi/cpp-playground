#include <iostream>
#include <cmath>
using namespace std;
// friend function example
// dont use to much friend function
// use when its really necessary
// it breaks the encapsulation and data hiding
// but sometimes its necessary
// friend function is not a member of the class
// but it can access the private members of the class
// friend function is declared inside the class with the keyword friend
// friend function is defined outside the class 
class EquilateralTriangle // forward declaration
{
    private: 
        float side;
        float circumference;
        float area;
    public:
        void setside(float s) {
            side = s;
            circumference = 3 * side;
            area = (sqrt(3) / 4) * side * side;
        }
    friend void print(EquilateralTriangle et); // friend function
};
void print(EquilateralTriangle et) {
    cout<<et.area<<endl;
    cout<<et.circumference<<endl;
}
int main(){
    EquilateralTriangle et;
    et.setside(5.0);
    print(et);
    return 0;
}