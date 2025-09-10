#include<iostream>
using namespace std;

class Book {
public:
	string Title;
	string Author;
	float* Rates;
	int RatesCounter;

	Book(string title, string author) {
		Title = title;
		Author = author;

		RatesCounter = 2;
		Rates = new float[RatesCounter];
		Rates[0] = 5;
		Rates[1] = 4;
	}

	~Book() {
		delete[] Rates;
		Rates = nullptr;
	}
    Book(const Book& origninal)
    {
        Title=origninal.Title;
        Author=origninal.Author;
        RatesCounter=origninal.RatesCounter;
        Rates=new float[RatesCounter];
        for(int i=0;i<RatesCounter;i++)
        {
            Rates[i]=origninal.Rates[i];
        }
    }
};

int main() {

	Book book1("Millionaire Fastlane", "M.J. DeMarco");
    // same those invoke copy constructor
	Book book2=book1;
    Book book3(book2);
	cin.get();
}