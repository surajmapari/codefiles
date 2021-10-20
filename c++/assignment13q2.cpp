//Q2. Write a program to swap values of data members of two classes using friend function.

#include <iostream>
using namespace std;

class Two;
class One
{
private:
    int a;

public:
    void get_data()
    {
        std::cout << "Enter the first number: ";
        cin >> a;
    }

    int display()
    {
        return a;
    }

    friend void swap(One &obj1, Two &obj2);
};

class Two
{
private:
    int b;

public:
    void get_data()
    {
        std::cout << "Enter the second number: ";
        cin >> b;
    }

    int display()
    {
        return b;
    }
    friend void swap(One &obj1, Two &obj2);
};

void swap(One &obj1, Two &obj2)
{
    int temp = obj1.a;
    obj1.a = obj2.b;
    obj2.b = temp;
}

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    One obj1;
    Two obj2;

    obj1.get_data();
    obj2.get_data();
    std::cout << "Before swaping first and second number is: " << obj1.display() << " and " << obj2.display() << std::endl;

    swap(obj1, obj2);

    std::cout << "After swaping first and second number is: " << obj1.display() << " and " << obj2.display() << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
