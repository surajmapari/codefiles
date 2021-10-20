/*Q1. Create two classes DM and DB which stores values of distances.
DM stores distance in m and cm and DB in feet and inches
Write a program that can read values for the class objects and add one object of DM with another object of DB 
use friend function to carry out the addition operation
the object that stores the result may be DM or DB object depending on unit in which the results are required
the display should be in the format of feet and inches or m and cm depending on the object on display*/

#include <iostream>
#include <cmath>
using namespace std;

class DB;
class DM
{
private:
    double meternum, centimeternum;
    double meterresult, centimeterresult;

public:
    void getdata()
    {
        std::cout << "Enter the distance in (meter centimeter) : ";
        cin >> meternum >> centimeternum;
    }
    
    void display()
    {
        std::cout << "Distance is " << meterresult << " meters and " << centimeterresult << " centimeters" << std::endl;
    }

    friend void add(DM DMobj, DB DBobj);
};

class DB
{
private:
    double feetnum, inchesnum;
    double feetresult, inchesresult;

public:
    void getdata()
    {
        std::cout << "Enter the distance in (feet inches) : ";
        cin >> feetnum >> inchesnum;
    }

    void display()
    {
        std::cout << "Distance is " << feetresult << " feets and " << inchesresult << " inches" << std::endl;
    }

    friend void add(DM DMobj, DB DBobj);
};

void add(DM DMobj, DB DBobj)
{
    std::cout << "Press 1 for answer in meter-centimeter" << std::endl;
    std::cout << "Press 2 for answer in feet-inches" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";
    int n;
    while (cin >> n && n != 1 && n != 2)
    {
        std::cout << "Wrong Input.Enter Again: ";
    }
    if (n == 1)
    {
        double sum = (DMobj.meternum * 100 + DMobj.centimeternum + DBobj.feetnum * 30.48 + DBobj.inchesnum * 2.54);
        if (sum >= 100)
        {
            DMobj.meterresult = sum / 100;
            DMobj.centimeterresult = fmod(sum, 100) ;
        }
        else
        {
            DMobj.meterresult = 0;
            DMobj.centimeterresult = sum;
        }
        std::cout << std::endl;
        DMobj.display();
    }
    else if (n == 2)
    {
        double sum = (DMobj.meternum * 39.3701 + DMobj.centimeternum * 0.393701 + DBobj.feetnum * 12 + DBobj.inchesnum);
        if (sum >= 12)
        {
            DBobj.feetresult = sum / 12;
            DBobj.inchesresult = fmod(sum, 100);
        }
        else
        {
            DBobj.feetresult = 0;
            DBobj.inchesresult = sum;
        }
        std::cout << std::endl;
        DBobj.display();
    }
}

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    DM DMobj;
    DB DBobj;
    DMobj.getdata();
    DBobj.getdata();
    std::cout << std::endl;
    add(DMobj, DBobj);

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
