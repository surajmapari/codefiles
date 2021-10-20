//Swaping numbers using pointers or addresses

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

//swaping using pointers
void swap(int *a, int *b)
{   
    int temp = *a;
    *a= *b;
    *b = temp;
}

// //swaping using addresses
// void swap(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

int main()
{   
    std::cout << "\n------------------------------------------------------------------" << std::endl;
    std::cout << "\n------------------------------------------------------------------" << std::endl;

    int a, b, temp;
    std::cout << "Enter the first numbser: ";
    cin >> a;
    std::cout << "Enter the second number: ";
    cin >> b;
    std::cout << "Before swaping(firstnumber, second number)=  " << a << "  " << b << "  " << &a << "  " << &b;

    //swaping using pointers
    swap(&a, &b);

    // //swaping using addresses
    // swap(a, b);

    std::cout << std::endl;
    std::cout << "After swaping(firstnumber, second number)=  " << a << "  " << b << "  " << &a << "  " << &b;

    std::cout << "\n------------------------------------------------------------------" << std::endl;
    std::cout << "\n------------------------------------------------------------------" << std::endl;

    return 0;
}
