//Write C++ program to store information ( Name, rollno and marks ) of students using structure.
//And display store information.

#include <iostream>
using namespace std;

struct students
{
    string name;
    int rollno;
    int marks;
};

int main()
{   
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    string name;
    int n, rollno, marks;
    std::cout << "Enter the number of students: ";
    cin >> n;
    struct students s[n];
    std::cout << "-------------------------------------------------------" << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the name of student " << i + 1 << ": ";
        cin >> s[i].name;
        std::cout << "Enter the rollno of student " << i + 1 << ": ";
        cin >> s[i].rollno;
        std::cout << "Enter the marks of student " << i + 1 << ": ";
        cin >> s[i].marks;
        std::cout << "-------------------------------------------------------" << std::endl;
    }

    std::cout << "--------------DISPLAYING INPUTED DATA------------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Name of student " << i + 1 << ": " << s[i].name << std::endl;
        std::cout << "Rollno of student " << i + 1 << ": " << s[i].rollno << std::endl;
        std::cout << "Marks of student " << i + 1 << ": " << s[i].marks << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    return 0;
}
