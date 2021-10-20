/* Q1. Write a C++ program to perform matrix addition or multiplication on integer and floating type
data types on 3 by 3 matrix by using function template */

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

// addition
template <class Matrixint, class Matrixdouble>
void add(Matrixint matrix1[][3], Matrixdouble matrix2[][3])
{
    Matrixdouble matrix3[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// subtraction
template <class Matrixint, class Matrixdouble>
void sub(Matrixint matrix1[][3], Matrixdouble matrix2[][3])
{
    Matrixdouble matrix3[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// multiplication
template <class Matrixint, class Matrixdouble>
void mul(Matrixint matrix1[][3], Matrixdouble matrix2[][3])
{
    Matrixdouble matrix3[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// display both matrices
template <class Matrixint, class Matrixdouble>
void display(Matrixint matrix1[][3], Matrixdouble matrix2[][3])
{
    std::cout << "Matrix of integer data type is" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Matrix of double data type is" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    int matrix1[3][3];
    double matrix2[3][3];
    int n;

    std::cout << "Enter Matrix of integer data type" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "Enter the value at [" << i << "] [" << j << "] :";
            cin >> matrix1[i][j];
        }
    }
    std::cout << std::endl;

    std::cout << "Your Matrix of integer data type is" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Enter Matrix of double data type" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "Enter the value at [" << i << "] [" << j << "] :";
            cin >> matrix2[i][j];
        }
    }
    std::cout << std::endl;

    std::cout << "Your Matrix of double data type is" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;

    do
    {
        std::cout << "1.Display entered matrix" << std::endl;
        std::cout << "2.Addition of matrix" << std::endl;
        std::cout << "3.Subtraction of matrix" << std::endl;
        std::cout << "4.Multiplication of matrix" << std::endl;
        std::cout << "5.Exit" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        cin >> n;
        std::cout << "--------------------------------------------------" << std::endl;

        switch (n)
        {
        case 1:
            display(matrix1, matrix2);
            std::cout << "--------------------------------------------------" << std::endl;
            break;

        case 2:
            std::cout << "Matrix after addition is" << std::endl;
            add(matrix1, matrix2);
            std::cout << "--------------------------------------------------" << std::endl;
            break;

        case 3:
            std::cout << "Matrix after subtraction is" << std::endl;
            sub(matrix1, matrix2);
            std::cout << "--------------------------------------------------" << std::endl;
            break;

        case 4:
            std::cout << "Matrix after multiplication is" << std::endl;
            mul(matrix1, matrix2);
            std::cout << "--------------------------------------------------" << std::endl;
            break;

        case 5:
            std::cout << "Program Ended" << std::endl;
            break;

        default:
            std::cout << "Enter the valid number" << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;
            break;
        }
    } while (n != 5);

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
