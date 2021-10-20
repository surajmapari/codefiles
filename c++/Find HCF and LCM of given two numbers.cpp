//Find HCF and LCM of given two numbers.

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int numOne, numTwo, lcm, hcf, a, b, temp;
    cout << "Enter Two Numbers: ";
    cin >> numOne >> numTwo;
    a = numOne;
    b = numTwo;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    hcf = a;
    lcm = (numOne * numTwo) / hcf;
    cout << "\nLCM (" << numOne << ", " << numTwo << ") = " << lcm;
    cout << "\nHCF (" << numOne << ", " << numTwo << ") = " << hcf;
    cout << endl;

    return 0;
}
