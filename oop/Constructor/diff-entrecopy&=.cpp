#include <iostream>
using namespace std;
// deference between copy constructor and assignment operator
// copy constructor is used to initialize a new object from an existing object
// assignment operator is used to copy the value from one existing object to another existing object
// both have the same name as the class and no return type + non return type
// copy constructor has one parameter which is a reference to the object of the same class
// assignment operator has one parameter which is a reference to the object of the same class and returns a reference to the object of the same class
// both must be placed in the public section of the class
class Movie {
public:
	string Name;
	string Genre;
	float Rating;
    int actorsCount;
    string* Actors;
	Movie(string name, string genre, float rating) {
		Name = name;
		Genre = genre;
		Rating = rating;
        actorsCount=0;
        Actors=new string[actorsCount];
	}
	Movie()
	{
		Name = "";
		Genre = "";
		Rating = 0;
        actorsCount=0;
        Actors=new string[actorsCount];
	}
    ~Movie(){
        delete [ ] Actors;
        Actors=nullptr;
    }
	Movie(const Movie& original) {
		Name = original.Name;
		Genre = original.Genre;
		Rating = original.Rating;
        actorsCount=original.actorsCount;
        Actors=new string[actorsCount];
        for(int i=0;i<actorsCount;i++)
        {
            Actors[i]=original.Actors[i];
        }
	}
	Movie& operator=(const Movie& original) {
        // self assignment check
        // if the address of the original object is different from the address of the current object
        // then we can proceed with the assignment
        // otherwise we skip the assignment
        // avoid self destruction !! 
			if(&original!=this)
            {
                    Name = original.Name;
                Genre = original.Genre;
                Rating = original.Rating;
                actorsCount=original.actorsCount;
                delete [] Actors;
                Actors=new string[actorsCount];
                for(int i=0;i<actorsCount;i++)
                {
                    Actors[i]=original.Actors[i];
                }
                return *this;
            }
	}
    void addActor(string actorName)
    {
        string* temp=new string[actorsCount+1];
        for(int i=0;i<actorsCount;i++)
        {
            temp[i]=Actors[i];
        }
        temp[actorsCount]=actorName;
        actorsCount++;
        delete [] Actors;
        Actors=temp;
        temp=nullptr;
    }
};
// copy constructor && assignment operator need to be created when you use pointers && deal with dynamic memory allocation
int main()
{
	Movie movie1("The Dark Knight", "Action", 9.5);
	Movie movie2("The Lion King", "Animated", 8);

	Movie movie3;
	Movie movie4(movie1);
	movie4 = movie2;
	//movie4.operator=(movie2); 
    // copy constructor is invoked here
	Movie movie5 = movie1;
    // assignment operator is invoked here
	movie5 = movie2;

	cin.get();
}