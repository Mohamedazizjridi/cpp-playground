// operator overloading : 
// 1. binary operator overloading
// 2. unary operator overloading
#include <iostream>
#include <string>
#include <list>
using namespace std;
struct Youtubechannel {
    string Name;
    int Subscriberscount;
    Youtubechannel(string name, int subs) {
        Name = name;
        Subscriberscount = subs;
    }
    //should not change the original object
    // hence const at the end
    bool operator==(const Youtubechannel& yt) const {
        return this->Name==yt.Name; // this-> please give me Name from my own struct
    }
};
// Definition of operator<< outside the struct
ostream& operator<<(ostream& out, const Youtubechannel& yt) {
    out << "Name : " << yt.Name << endl;
    out << "Subscriberscount : " << yt.Subscriberscount << endl;
    return out;
}

struct mycollection{
    list<Youtubechannel> channels;
    void operator+=(Youtubechannel yt){
        this->channels.push_back(yt); // this-> please give me channels from my own struct
    }
    void operator-=(Youtubechannel yt){
        this->channels.remove(yt);
    }
};
ostream& operator<<(ostream& out , const mycollection& mycoll)
{
    out << "my collection of youtube channels" << endl;
    for(const auto& yt : mycoll.channels)
    {
        out << yt; // calls operator<<(out,yt)
    }
    return out;
}
int main() {
    Youtubechannel yt1("CodeWithHarry", 1000000);
    cout << yt1;
    operator<<(cout,yt1); // same as cout<<yt1
    mycollection mycoll;
    mycoll+=yt1; // mycoll.operator+=(yt1)
    return 0;
}