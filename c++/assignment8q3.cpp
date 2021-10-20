//Q3 Write a program to find largest ,2nd largest from an array using pointers

#include <iostream>
using namespace std;

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    int n;
    std::cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n], temp;
    //std::cout << arr << std::endl;

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
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            
        }
        
    }
    std::cout << "Sorted array in descending order is: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "First Largest element from array is: " << arr[0] << std::endl;
    std::cout << "Second Largest element from array is: " << arr[1] << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
