/* Q. Using class template write a program Input n numbers into an array and 
print the element is ascending order.(array sorting) */

#include <iostream>
using namespace std;

template <class Template>
class Sort
{
public:
    void sort_data(int *arr, int n);
    void display_data(int *arr, int n);
};

template <class Template>
void Sort<Template>::sort_data(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <class Template>
void Sort<Template>::display_data(int *arr, int n)
{
    std::cout << "array is: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    int n;
    std::cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the element " << i + 1 << ": ";
        cin >> arr[i];
    }
    std::cout << "--------------------------------------------------" << std::endl;

    Sort<class Template> t;

    std::cout << "Entered ";
    t.display_data(arr, n);

    t.sort_data(arr, n);

    std::cout << "Sorted ";
    t.display_data(arr, n);

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
