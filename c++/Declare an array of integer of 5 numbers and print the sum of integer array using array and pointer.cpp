//Q1 Declare an array of integer of 5 numbers and print the sum of integer array using array and pointer

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    int n;
    std::cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    std::cout << std::endl;

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr[i] = element;
    }
    std::cout << std::endl;

    std::cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n" << std::endl;

    int sum = 0, *ptrarr = arr;
    for (int i = 0; i < n; i++)
    {
        sum = sum + *ptrarr;
        *ptrarr++;
    }
    std::cout << "The sum of elements in an array is: " << sum;

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
