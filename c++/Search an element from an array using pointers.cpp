//Q2 Search an element from an array using pointers

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

    int search, *ptrarr = arr;
    std::cout << "Enter the element to search: ";
    cin >> search;
    for (int i = 0; i < n - 1; i++)
    {
        if (search == *ptrarr)
        {
            std::cout << std::endl;
            std::cout << "Element " << search << " found at index: " << i << std::endl;
            break;
        }
        else
        {
            *ptrarr++;
        }
    }

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
