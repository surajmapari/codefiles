//Find whether the given number is positive or negative. Also state whether it is even or odd number.

#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
    int n;
    std::cout << "Enter the number: " << std::endl;
    cin >> n;

    if (n > 0)
    {
        if (n % 2 == 0)
        {
            std::cout << "Entered number is positive and even." << std::endl;
        }
        else
        {
            std::cout << "Entered number is positive and odd." << std::endl;
        }
    }

    else if (n == 0)
    {
        std::cout << "Entered number is zero." << std::endl;
    }    
    
    else
    {
        if (n % 2 == 0)
        {
            std::cout << "Entered number is negative and even." << std::endl;
        }
        else
        {
            std::cout << "Entered number is negative and odd." << std::endl;
        }
    }

    return 0;
}
