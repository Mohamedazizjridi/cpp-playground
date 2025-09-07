#include<iostream>
#include<list>
#include<string>
using namespace std;
// constructor has the same name as the class
// its has no return type
// its automatically called when an object is created
class YoutubeChannel
{
    // access modifier make attributes accessible outside the class
    private:
        string Name;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    protected:
        // accessible in derived class
        string OwnerName;
    public:
        YoutubeChannel(string name , string ownerName)
        {
            Name=name;
            OwnerName=ownerName;
            SubscribersCount=0;
        }
        // method 
        void getinfo()
        {
            cout<<"Name: "<<Name<<endl;
            cout<<"Owner Name: "<<OwnerName<<endl;
            cout<<"Subscribers Count: "<<SubscribersCount<<endl;
            cout<<"Videos: "<<endl;
            for(string e:PublishedVideoTitles)
            {
                cout<<e<<endl;
            }
        }
        void Subscribe()
        {
            SubscribersCount++;
        }
        void Unsubscribe()
        {
            if(SubscribersCount>0)
            {
                SubscribersCount--;
            }
        }
        void publishVideo(string title)
        {
            PublishedVideoTitles.push_back(title);
        }
        string getName(){
            return Name;
        }
        void setName(string name){
            Name=name;
        }
        string getOwnerName(){
            return OwnerName;
        }
    };
    // inhertance
class cookingYoutubechannel : public YoutubeChannel{
    // ride class  ----- base class
    // public -- means all public members of base class will be public members of derived class
    public:
        // constructor
        cookingYoutubechannel(string name , string ownerName):YoutubeChannel(name,ownerName){
        }
        void practice(){
            cout<<OwnerName<<" is practicing cooking, learning new recipes , watching cooking videos"<<endl;
        }

};
int main()
{
    // object creation
    cookingYoutubechannel yt("Code with Harry","Harry");
    yt.getName();
    yt.setName("Code with harry 2.0");
    yt.practice();
    return 0;
}