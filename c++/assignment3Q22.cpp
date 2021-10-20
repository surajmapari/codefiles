//Given an array of n elements, print all elements of the array in reverse order which are at a odd index.

#include <iostream>
using namespace std;

int main()
{
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    int n;
    std::cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    std::cout << "Enter the elements of array: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    std::cout << "The Array is: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nElements in reverse order at odd index: ";
    for (int i = n - 1; i > 0; i--)
    {
        if (i % 2 != 0)
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "\n---------------------------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    return 0;
}
