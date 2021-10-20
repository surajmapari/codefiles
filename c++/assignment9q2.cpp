//2.Demonstrate the use of new and delete operator for dynamic memory allocation

#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    
    int n;
    std::cout << "Enter the size of array: ";
    cin >> n;
    int *arr = new int[n];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }

    std::cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << *(arr + i) << " ";
    }

    delete[] arr;

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
