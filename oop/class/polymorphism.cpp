// polimorphism  is the object to have many forms
#include<iostream>
#include<list>
#include<string>
using namespace std;
class YoutubeChannel
{
    private:
        string Name;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    protected:
        string OwnerName;
        int  contentQuality;
    public:
        YoutubeChannel(string name , string ownerName)
        {
            Name=name;
            OwnerName=ownerName;
            SubscribersCount=0;
            contentQuality=0;
        }
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
        void checkAnalyrics(){
            if(contentQuality<5){
                cout<<Name<<" channel is poor"<<endl;
            }
            else if(contentQuality>=5 && contentQuality<10){
                cout<<Name<<" channel is good"<<endl;
            }
            else{
                cout<<Name<<" channel is excelent"<<endl;
            }
        }
    };
class cookingYoutubechannel : public YoutubeChannel{
    
    public:
        cookingYoutubechannel(string name , string ownerName):YoutubeChannel(name,ownerName){
        }
        void practice(){
            cout<<OwnerName<<" is practicing cooking, learning new recipes , watching cooking videos"<<endl;
            contentQuality++;
        }

};
class singerYoutubeChannel  : public YoutubeChannel{

    public:
        singerYoutubeChannel(string name , string ownerName):YoutubeChannel(name,ownerName){
        }
        // different behavior for same function : polymorphism !! 
        void practice(){
            cout<<OwnerName<<" is practicing singing, learning new songs , watching singing videos"<<endl;
            contentQuality++;
        }

};
int main()
{
    // object creation
    cookingYoutubechannel yt("Code with Harry","Harry");
    singerYoutubeChannel y("Singer","Amit");
    yt.getName();
    yt.setName("Code with Harry 2.0");
    yt.practice();
    YoutubeChannel* yt1=&yt;
    YoutubeChannel*yt2=&y;
    yt1->checkAnalyrics();
    yt2->checkAnalyrics();// invoke methodes using pointers 
    return 0;
}