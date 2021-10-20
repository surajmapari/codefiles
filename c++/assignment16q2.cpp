/*"Write a Class to represent a vector(a series of float values).
Include Member function to perform the following task
1)To create a vector.
2)To modify the value of given element
3) to multiply scalar value
4)To display Vector
Use appropriate constructor where ever required*/

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class Vector
{
private:
    float x, y, z;

public:
    Vector();
    ~Vector();

    void set_vector()
    {
        std::cout << "Enter the scaler value in x direction: ";
        cin >> x;
        std::cout << "Enter the scaler value in y direction: ";
        cin >> y;
        std::cout << "Enter the scaler value in z direction: ";
        cin >> z;
    }

    void modify()
    {
        display();
        char c;
        std::cout << "Enter the direction in which you want to modify vector(x or y or z): ";
        cin >> c;
        if (c == 'x')
        {
            std::cout << "Enter new value for x: ";
            cin >> x;
        }
        else if (c == 'y')
        {
            std::cout << "Enter new value for y: ";
            cin >> y;
        }
        else if (c == 'z')
        {
            std::cout << "Enter new value for z: ";
            cin >> z;
        }
        display();
    }

    void multiply()
    {
        float scalar;
        std::cout << "Enter the scalar quantity to multiply: ";
        cin >> scalar;
        x = x * scalar;
        y = y * scalar;
        z = z * scalar;
        display();
    }

    void display()
    {
        std::cout << "Now vector is: " << x << "i + " << y << "j + " << z << "k" << std::endl;
    }
};

Vector::Vector()
{
    std::cout << "Enter the scaler value in x direction: ";
    cin >> x;
    std::cout << "Enter the scaler value in y direction: ";
    cin >> y;
    std::cout << "Enter the scaler value in z direction: ";
    cin >> z;
}
 
int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    Vector vtr;
    vtr.set_vector();

    std::cout << "--------------------------------------------------" << std::endl;

    vtr.modify();

    std::cout << "--------------------------------------------------" << std::endl;

    vtr.multiply();

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
