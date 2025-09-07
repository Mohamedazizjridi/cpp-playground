#include<iostream>
#include<list>
#include<string>
using namespace std;
class YoutubeChannel
{
    // access modifier make attributes accessible outside the class
    public:
        string Name;
        int SubscribersCount;
        string OwnerName;
        list<string> PublishedVideoTitles;
};
int main()
{
    // object creation
    YoutubeChannel yt;
    yt.Name="Code with Harry";
    yt.OwnerName="Hary";
    yt.SubscribersCount=1000000;
    yt.PublishedVideoTitles={"C++ for beginners","html tuto"};
    cout<<"Name: "<<yt.Name<<endl;
    cout<<"Owner Name: "<<yt.OwnerName<<endl;
    cout<<"Subscribers Count: "<<yt.SubscribersCount<<endl;
    cout<<"Videos: "<<endl;
    for(string e:yt.PublishedVideoTitles)
    {
        cout<<e<<endl;
    }
    return 0;
}