#include <iostream>
#include <cmath>
using namespace std;
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
    friend class homework; // friend class
    friend ostream& operator<<(ostream& out, const EquilateralTriangle& et);
};
ostream& operator<<(ostream& out, const EquilateralTriangle& et) {
    out<<et.area<<endl;
    out<<et.circumference<<endl;
    return out;}
class homework{
public:
    void print(EquilateralTriangle et) {
    cout<<et.area<<endl;
    cout<<et.circumference<<endl;
}

};
int main(){
    EquilateralTriangle et;
    et.setside(5.0);
    homework h;
    h.print(et);
    return 0;
}