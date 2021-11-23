/* A palindrome is a string of character that‘s the same forward and backward. Typically,punctuation, capitalization, and spaces are ignored.
For example, “Poor Dan is in a droop”is a palindrome, as can be seen by examining the characters “poor danisina droop”
and observing that they are thesame forward and backward. One way to check for apalindrome is to reverse the characters in the string
and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program with functions
1. To print original string followed by reversed string using stack
2. To check whether given string is palindrome or not */

#include <iostream>
#include <string.h>
#include <sstream>
#define MAX 50
using namespace std;

class stack
{
private:
    int length, top, count;
    char data[MAX], entered[MAX];
    void push_data(char element);
    char pop_data();

public:
    stack()
    {
        top = -1;
        length = 0;
        count = 0;
    }
    void create();
    void check();
    void rev_display();
};

void stack::create()
{
    std::cout << "Enter a string: ";
    cin.getline(entered, MAX);
    length = strlen(entered);
}

void stack::push_data(char element)
{
    if (top == MAX - 1)
    {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }
    data[++top] = element;
}

char stack::pop_data()
{
    if (top == -1)
    {
        std::cout << "Stack Underflow!" << std::endl;
    }
    char temp = data[top--];
    return temp;
}

void stack::check()
{
    for (int i = 0; i < length; i++)
    {
        push_data(entered[i]);
    }
    for (int i = 0; i < length; i++)
    {
        if (entered[i] == pop_data())
        {
            count++;
        }
    }
    if (count == length)
    {
        std::cout << "String is a palindrome" << std::endl;
    }
    else
    {
        std::cout << "String is NOT a palindrome" << std::endl;
    }
}

void stack::rev_display()
{
    string temp = "";
    for (int i = length - 1; i >= 0; i--)
    {
        temp.push_back(data[i]);
    }
    std::cout << "Reverse of string is: " << temp << std::endl;
}
int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    stack obj;
    obj.create();
    obj.check();
    obj.rev_display();

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}