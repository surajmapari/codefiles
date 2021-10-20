/*Q. Consider the base class called shape.Use this class to store two double type.
Values that can be used to compute are of figures. Derive two specific classes called 
triangle and rectangle from shape. Add to the base class, a member function get_data() to initialize base class data
members and another funtion display_area() to compute and display area of figures.Make display area as virtual function
and redefine this function in the derived classes to suit the requirements.
Using these three classes design a program that will accept values from users for triangle or rectangle respectively and display area.*/

#include <iostream>
using namespace std;

class Triangle;
class Rectangle;
class Shape
{
public:
    double value1, value2;
    void get_data()
    {
        std::cout << "Enter the value1: ";
        cin >> value1;
        std::cout << "Enter the value2: ";
        cin >> value2;
    }

    virtual void display_area() = 0;
};

class Triangle : public Shape
{
public:
    void display_area()
    {
        std::cout << "Area of triangle is: " << 0.5 * value1 * value2 << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    void display_area()
    {
        std::cout << "Area of rectangle is: " << value1 * value2 << std::endl;
    }
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    Shape *stptr;

    Triangle tobj;
    stptr = &tobj;
    std::cout << "Enter Base and Height" << std::endl;
    stptr->get_data();
    stptr->display_area();

    std::cout << "--------------------------------------------------" << std::endl;

    Rectangle robj;
    stptr = &robj;
    std::cout << "Enter Length and Breadth" << std::endl;
    stptr->get_data();
    stptr->display_area();

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
