//Q1. Write a program to add two complex numbers using friend function.

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class complexnum2;
class complexnum1
{
private:
    int realpart1, imgpart1;
public:
    void get_complexnum1()
    {
        std::cout << "Enter the Complex Number 1 Real Part: ";
        cin >> realpart1;
        std::cout << "Enter the Complex Number 1 Imaginary Part: ";
        cin >> imgpart1;
    }
    friend void addcomplexnum(complexnum1 obj1, complexnum2 obj2);
};

class complexnum2
{
private:
    int realpart2, imgpart2;
public:
    void get_complexnum2()
    {
        std::cout << "Enter the Complex Number 2 Real Part: ";
        cin >> realpart2;
        std::cout << "Enter the Complex Number 2 Imaginary Part: ";
        cin >> imgpart2;
    }
    friend void addcomplexnum(complexnum1 obj1, complexnum2 obj2);
};

void addcomplexnum(complexnum1 obj1, complexnum2 obj2)
{
    int addreal = obj1.realpart1 + obj2.realpart2;
        int addimg = obj1.imgpart1 + obj2.imgpart2;
        std::cout << "Addition of ((" << obj1.realpart1 << ")+(" << obj1.imgpart1 << "i))"
                  << " and ((" << obj2.realpart2 << ")+(" << obj2.imgpart2 << "i))"
                  << " is: ((" << addreal << ")+(" << addimg << "i))";
        std::cout << std::endl;
}
 
int main()
{
    std::cout << "\n------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    complexnum1 obj1;
    complexnum2 obj2;
    obj1.get_complexnum1();
    std::cout << "------------------------------------------------------------------" << std::endl;
    obj2.get_complexnum2();
    std::cout << "------------------------------------------------------------------" << std::endl;
    addcomplexnum(obj1, obj2);

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    return 0;
}
