// Q. Write a C++ program to overload unary operators that is increment and decrement.

#include <iostream>

using namespace std;
 
class Num 
{
private:
    int n;
public:
    void getnum(int x)
    {
        n = x;
    }

    void dispnum()
    {
        std::cout << "Value of n is: " << n << std::endl;
    }

    void operator ++()
    {
        n = ++n;
    }

    void operator --()
    {
        n = --n;
    }
};

int main()
{
std::cout << "\n--------------------------------------------------" << std::endl;
std::cout << "--------------------------------------------------" << std::endl;
 
Num num;
num.getnum(10);

++num;
std::cout << "After increment " << std::endl;
num.dispnum();

--num;
std::cout << "After decrement " << std::endl;
num.dispnum();

std::cout << "--------------------------------------------------" << std::endl;
std::cout << "--------------------------------------------------" << std::endl;
 
return 0;
}
