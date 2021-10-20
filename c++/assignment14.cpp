//C++ program to read time in seconds and convert in time format (HH:MM:SS) using class
#include <iostream>
#include <cmath>
using namespace std;

class Time
{
private:
    int n, hours = 0, mins = 0, secs = 0, remtime;

public:
    void get_data()
    {
        std::cout << "Enter the time in seconds: ";
        cin >> n;
    }

    void conversion()
    {
        hours = n / (60 * 60);
        remtime = n % (60 * 60);
        mins = remtime / 60;
        secs = remtime % 60;
    }

    void display()
    {
        std::cout << "The time in HH:MM:SS format is: " << hours << ":" << mins << ":" << secs << std::endl;
    }
};

int main()
{   
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    Time obj;
    obj.get_data();
    obj.conversion();
    obj.display();

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
