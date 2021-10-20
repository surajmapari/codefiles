//Print prime numbers between 1 to 20.

#include <iostream>
using namespace std;

int main()
{
    int counter = 0;
    cout << "\n Prime Numbers Between 1 To 20 :\n";
    for (int i = 2; i <= 20; i++)
    {
        counter = 0;
        //As any number can be divided by 1 and itself so we will not consider 1 & that number

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                counter++;
                break;
            }
        }
        if (counter == 0)
        {
            std::cout << i << std::endl;;
        }
    }
    return 0;
}
