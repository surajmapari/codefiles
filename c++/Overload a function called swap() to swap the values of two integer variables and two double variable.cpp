/* Q2. Overload a function called swap() to swap the values of
a) Two integer variables
b) Two double variable  */

#include <iostream>
#include <stdio.h>
using namespace std;

class Swap
{
public:
    void swap(int &a1, int &b1)
    {   
    int temp = a1;
    a1 = b1;
    b1 = temp;
    };

    void swap(double &a1, double &b1)
    {   
    double temp = a1;
    a1 = b1;
    b1 = temp;
    };
};

int main()
{   
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    
    Swap obj;
    int a = 10, b = 20;
    std::cout << "Before Swaping type-integer (a, b) is: ("<< a << ", " << b << ")" << std::endl;
    obj.swap(a,b);
    std::cout << "After Swaping type-integer (a, b) is: ("<< a << ", " << b << ")" << std::endl;
    std::cout << "\n--------------------------------------------------" << std::endl;

    double c = 12, d = 23;
    std::cout << "Before Swaping type-double (a, b) is: ("<< c << ", " << d << ")" << std::endl;
    obj.swap(c,d);
    std::cout << "After Swaping type-double (a, b) is: ("<< c << ", " << d << ")" << std::endl;

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------\n" << std::endl;

    return 0;
}
