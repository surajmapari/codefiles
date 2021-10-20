//Declare a structure to represent a complex number (a number having a real part and imaginary part).
//Write C++ functions to add, subtract, multiply and divide two complex numbers.

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

struct complex
{
    float realpart;
    float imgpart;
};

class Complex
{
private:
    float addreal, addimg, subreal, subimg, mulreal, mulimg, divreal, divimg;
    float realpart1, realpart2, imgpart1, imgpart2;

public:
    void complexaddsub(float realpart1, float realpart2, float imgpart1, float imgpart2)
    {
        addreal = realpart1 + realpart2;
        addimg = imgpart1 + imgpart2;
        std::cout << "Addition of ((" << realpart1 << ")+(" << imgpart1 << "i))"
                  << " and ((" << realpart2 << ")+(" << imgpart2 << "i))"
                  << " is: ((" << addreal << ")+(" << addimg << "i))";
        std::cout << std::endl;

        subreal = realpart1 - realpart2;
        subimg = imgpart1 - imgpart2;
        std::cout << "Subtraction of (" << realpart1 << "+" << imgpart1 << "i)"
                  << " and (" << realpart2 << "+" << imgpart2 << "i)"
                  << " is: ((" << subreal << ")+(" << subimg << "i))";
        std::cout << "\n------------------------------------------------------------------" << std::endl;
    };

    void complexmuldiv(float realpart1, float realpart2, float imgpart1, float imgpart2)
    {
        mulreal = ((realpart1 * realpart2) - (imgpart1 * imgpart2));
        mulimg = ((realpart1 * imgpart2) + (realpart2 * imgpart1));
        std::cout << "Multiplication of (" << realpart1 << "+" << imgpart1 << "i)"
                  << " and (" << realpart2 << "+" << imgpart2 << "i)"
                  << " is: ((" << mulreal << ")+(" << mulimg << "i))";
        std::cout << std::endl;

        divreal = ((realpart1 * realpart2) + (imgpart1 * imgpart2)) / (pow(realpart2, 2) + pow(imgpart2, 2));
        divimg = ((realpart2 * imgpart1)) - ((realpart1 * imgpart2)) / (pow(realpart2, 2) + pow(imgpart2, 2));
        std::cout<< "Division of (" << realpart1 << "+" << imgpart1 << "i)"
                 << " and (" << realpart2 << "+" << imgpart2 << "i)"
                 << " is: ((" << divreal << ")+(" << divimg << "i))";
        std::cout << "\n------------------------------------------------------------------" << std::endl;
    };
};

int main()
{
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    int n = 2;
    struct complex c[n];
    Complex cobj;
    int addition[n];

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the Complex Number " << i + 1 << " Real Part: ";
        cin >> c[i].realpart;
        std::cout << "Enter the Complex Number " << i + 1 << " Imaginary Part: ";
        cin >> c[i].imgpart;
    }
    std::cout << "------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "The Complex Number " << i + 1 << " is: ((" << c[i].realpart << ")+(" << c[i].imgpart << "i))";
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------------------------------" << std::endl;

    cobj.complexaddsub(c[0].realpart, c[1].realpart, c[0].imgpart, c[1].imgpart);
    cobj.complexmuldiv(c[0].realpart, c[1].realpart, c[0].imgpart, c[1].imgpart);

    std::cout << "------------------------------------------------------------------" << std::endl;

    return 0;
}
