/* Q. Overload the binary multiplication(*) operator to calculate product of two objects
 and overload the equality operator(==) to check whether two objects are equal.*/

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class ABC
{
public:
    int num;
    ABC(){}
    ABC(int n)
    {
        num = n;
    }

    bool operator==(ABC obj1)
    {
        if ((num == obj1.num))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int operator*(ABC obj1, ABC obj2)
{
    ABC obj;
    obj.num = obj1.num * obj2.num;
    return obj.num;
}

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Enter first object parameter: ";
    int fnum;
    cin >> fnum;
    ABC obj1(fnum);

    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Enter second object parameter: ";
    int snum;
    cin >> snum;
    ABC obj2(snum);

    std::cout << "--------------------------------------------------" << std::endl;
    int product = obj1 * obj2;
    std::cout << "Product of first object and second object: " << product << std::endl;

    if (obj1 == obj2)
    {
        std::cout << "First object is equal to Second object." << std::endl;
    }
    else
    {
        std::cout << "First object is not equal to Second object." << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
