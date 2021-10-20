/*"Write a program  in C++ for Patient Class using constructor and destructor.
Class name: Patient
Class Members: int  heartRate; 
    double moneyOwed; 
    string   name;  

Member function:int getHeartRate() 
    void setHeartRate(int heartRate)//parametrized Constructor
    double getMoneyOwed() 
    void setMoneyOwed 
    string getName() 
    void setName(string name) )//parametrized Constructor
Destructor:~Patient() {} 
This could be defined outside  the class definition instead"*/

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class Patient
{
private:
    int heartRate, hr;
    double moneyOwed;
    string name, nm;

public:
    Patient();
    ~Patient();

    void setName(string nm)
    {
        name = nm;
    }

    void setHeartRate(int hr)
    {
        heartRate = hr;
    }

    void setMoneyOwed()
    {
        std::cout << "Enter money owed: ";
        cin >> moneyOwed;
    }

    string getName()
    {
        return name;
    }

    int getHeartRate()
    {
        return heartRate;
    }

    double getMoneyOwed()
    {
        return moneyOwed;
    }
};

Patient::Patient()
{   

}

Patient::~Patient()
{

}

int main()
{   
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    string name; int heartrate, moneyowed;
    std::cout << "Enter your Name: ";
    cin >> name;
    std::cout << "Enter your HeartRate: ";
    cin >> heartrate;

    Patient obj;
    obj.setName(name);
    obj.setHeartRate(heartrate);
    obj.setMoneyOwed();

    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Your name is: " << obj.getName() << std::endl;
    std::cout << "Your HeartRate is: " << obj.getHeartRate() << std::endl;
    std::cout << "Money Owed By you is: " << obj.getMoneyOwed() << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
