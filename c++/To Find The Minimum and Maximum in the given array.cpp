//To Find The Minimum and Maximum in the given array.

#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    std::cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }        
    }

    std::cout << "\nThe min value of array is: " << min << std::endl;
    std::cout << "The max value of array is: " << max << std::endl;
    return 0;
}
