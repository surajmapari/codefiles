//Simple calculator program for operations - Addition, Subtraction, Multiply, Division

#include <iostream>
#include <cmath>
using namespace std;

double add(double num1, double num2)
{
    double addition = num1 + num2;
    return addition;
}

double sub(double num1, double num2)
{
    double subtraction = num1 - num2;
    return subtraction;
}

double mul(double num1, double num2)
{
    double multiplication = round(num1 * num2) ;
    return multiplication;
}

void div(double num1, double num2, double *q, double *r)
{   
    *q = num1 / num2;
    *r = fmod(num1,num2);
}
int main()
{
    std::cout << "\n------------------------------------------------------------------" << std::endl;
    std::cout << "\n------------------------------------------------------------------" << std::endl;
    
    double num1, num2;
    char opp;
    std::cout << "Enter the first number: ";
    cin >> num1;
    std::cout << "\nEnter the operation( + or - or * or /): ";
    cin >> opp;
    std::cout << "\nEnter the second number: ";
    cin >> num2;

    if (opp == '+')
    {
        std::cout << "\nAddition of " << num1 << " + " << num2 << " = " << add(num1, num2);
    }
    else if (opp == '-')
    {
        std::cout << "\nSubtraction of " << num1 << " - " << num2 << " = " << sub(num1, num2);
    }
    else if (opp == '*')
    {
        std::cout << "\nMultiplication of " << num1 << " * " << num2 << " = " << mul(num1, num2);
    }
    else if (opp = '/')
    {   
        double quotient, remainder;
        div(num1, num2, &quotient, &remainder);
        std::cout << "\nDivision of " << num1 << " / " << num2 << " = " << quotient;
        std::cout << "\nAnd the Reaminder is: " << remainder;
    }

    std::cout << "\n------------------------------------------------------------------" << std::endl;
    std::cout << "\n------------------------------------------------------------------" << std::endl;
    
    return 0;
}
