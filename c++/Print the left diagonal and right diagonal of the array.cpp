//Take a input for a r x c matrix(2D array) where r is number of rows and c is number of columns and r==c.
//Print the left diagonal and right diagonal of the array.

#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

int main()
{
    int row, column;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout << "Enter the number of rows columns: ";
    cin >> row >> column;
    int matrix[row][column];

    std::cout << "Matrix is of: " << row << " * " << column << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout << "Enter the elements of the array: " << std::endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    std::cout << "The Matrix is: " << std::endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    if (row == column)
    {
        list<int> leftdiagonal;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == j)
                {
                    leftdiagonal.push_back(matrix[i][j]);
                }
            }
        }

        list<int> rightdiagonal;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if ((i + j) == (row - 1))
                {
                    rightdiagonal.push_back(matrix[i][j]);
                }
            }
        }

        std::cout << "Left Diagonal : ";
        for (auto const &i : leftdiagonal)
        {
            std::cout << i << " ";
        }

        std::cout << "\nRight Diagonal : ";
        for (auto const &j : rightdiagonal)
        {
            std::cout << j << " ";
        }
        std::cout << "\n---------------------------------------------------------------------------------" << std::endl;
    }
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    return 0;
}
