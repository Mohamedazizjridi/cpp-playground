#include <iostream>
#include <vector>
#include <algorithm> // for std::remove
#include <string>
using namespace std;

// Observer Interface
class Observer {
public:
    virtual void update(const string& weather) = 0;
    virtual ~Observer() {}
};

// Subject Interface
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

// ConcreteSubject Class
class WeatherStation : public Subject {
private:
    vector<Observer*> observers; // list of observers
    string weather;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(weather);
        }
    }

    void setWeather(const string& newWeather) {
        weather = newWeather;
        notifyObservers();
    }
};

// ConcreteObserver Class: PhoneDisplay
class PhoneDisplay : public Observer {
private:
    string weather;

    void display() {
        cout << "Phone Display: Weather updated - " << weather << endl;
    }

public:
    void update(const string& weather) override {
        this->weather = weather;
        display();
    }
};

// ConcreteObserver Class: TVDisplay
class TVDisplay : public Observer {
private:
    string weather;

    void display() {
        cout << "TV Display: Weather updated - " << weather << endl;
    }

public:
    void update(const string& weather) override {
        this->weather = weather;
        display();
    }
};

// Usage / Demo
int main() {
    WeatherStation weatherStation;

    PhoneDisplay phoneDisplay;
    TVDisplay tvDisplay;

    // Register observers
    weatherStation.addObserver(&phoneDisplay);
    weatherStation.addObserver(&tvDisplay);

    // Simulating weather changes
    weatherStation.setWeather("Sunny");
    weatherStation.setWeather("Rainy");
    weatherStation.setWeather("Cloudy");

    // Remove one observer
    weatherStation.removeObserver(&tvDisplay);

    // Notify remaining observer
    weatherStation.setWeather("Windy");

    return 0;
}