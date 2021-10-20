//Create class student print details of a students such as Roll_no,Name,Total marks and percentage
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Student
{
private:
    string name, mystring;
    int rollnum, marks[5], totalmarks = 0;
    float percentage;

public:
    void get_data()
    {
        std::cout << "Enter the name of the student: ";
        getline(cin, mystring);
        stringstream(mystring) >> name;

        std::cout << "Enter the roll number of the student: ";
        getline(cin, mystring);
        stringstream(mystring) >> rollnum;

        std::cout << "Enter the marks of the student" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Enter marks of subject" << i + 1 << " : ";
            getline(cin, mystring);
            stringstream(mystring) >> marks[i];
        }
    }

    void display()
    {
        std::cout << "Name of the student is: " << name << std::endl;
        std::cout << "Roll number is: " << rollnum << std::endl;
        std::cout << "Marks in all 5 subjects are: ";
        for (int i = 0; i < 5; i++)
        {
            std::cout << marks[i] << " ";
        }
        for (int i = 0; i < 5; i++)
        {
            totalmarks = totalmarks + marks[i];
        }
        std::cout << std::endl;
        std::cout << "Total marks is: " << totalmarks << std::endl;
        float percentage = ((totalmarks * 100) / 500);
        std::cout << "Student Percentage is: " << percentage << std::endl;
    }
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    Student obj;
    obj.get_data();
    std::cout << "--------------------------------------------------" << std::endl;
    obj.display();

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
