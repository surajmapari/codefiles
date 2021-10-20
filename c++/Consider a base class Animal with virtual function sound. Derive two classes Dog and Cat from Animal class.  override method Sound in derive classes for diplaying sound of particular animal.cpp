/* Q. Implement Late Binding for following Case Study. 
Consider a base class Animal with virtual function sound. Derive two classes Dog and Cat from Animal class. 
override method Sound in derive classes for diplaying sound of particular animal. */

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class Animal
{
public:
    virtual void sound(){};
};

class Dog : public Animal
{
public:
    void sound()
    {
        std::cout << "This is sound of Dog." << std::endl;
    }
};

class Cat : public Animal
{
public:
    void sound()
    {
        std::cout << "This is sound of Cat." << std::endl;
    }
};

int main()
{
std::cout << "\n--------------------------------------------------" << std::endl;
std::cout << "--------------------------------------------------" << std::endl;
 
Animal *ptr;

Dog obj1;
Cat obj2;

ptr = &obj1;
ptr->sound();

ptr = &obj2;
ptr->sound();
 
std::cout << "--------------------------------------------------" << std::endl;
std::cout << "--------------------------------------------------" << std::endl;
 
return 0;
}
