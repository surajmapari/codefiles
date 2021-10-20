//1.Demonstrate the use of pointer to structure with one real life example of your own

#include <iostream>
using namespace std;

struct Employee
{
    string ename;
    int esalary;
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    struct Employee e;
    struct Employee *p = &e;
    std::cout << "Enter the name of the employee: ";
    getline(cin, (*p).ename);
    //std::cout << std::endl;
    std::cout << "Enter the salary of the employee: ";
    cin >> (*p).esalary;
    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Employee name is: " << (*p).ename << std::endl;
    std::cout << "Employee salary is: " << (*p).esalary << std::endl;

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
