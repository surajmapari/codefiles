//Take any dimension array from user and print the even numbers in the array

#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

int main()
{
    int row, column;
    std::cout << "Enter the number of rows columns: ";
    cin >> row >> column;
    int matrix[row][column];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << "\nmatrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    list<int> evenlist;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                evenlist.push_back(matrix[i][j]);
            }
        }
    }

    std::cout << "The even numbers in the array are: ";
    for (auto const &i : evenlist)
    {
        std::cout << i << " ";
    }

    return 0;
}
