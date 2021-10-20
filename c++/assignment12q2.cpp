//Q2. Write a class with data members name, roll no, and marks in 5 subjects.
//Write a friend function which is calculating average of 5 subjects.
//Display all details of student with average marks.

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;
 
class Student
{
private:
    string name, mystring;
    int rollnum, marks[5], n;
public:
    void get_data()
    {
        n = 1;
        //std::cout << "Enter the number of students: ";
        //getline(cin, mystring);
        //stringstream(mystring) >> n;
        for (int i = 0; i < n; i++)
        {
            std::cout << "Enter the name of student" << i+1 << " : ";
            getline(cin, name);
            std::cout << "Enter the roll number of student" << i+1 << " : ";
            getline(cin, mystring);
            stringstream(mystring) >> rollnum;
            std::cout << "Enter the marks of student in 5 subjects " << std::endl;
            for (int i = 0; i < 5; i++)
            {
                std::cout << "Enter the marks in subject" << i+1 << " : ";
                getline(cin, mystring);
                stringstream(mystring) >> marks[i];
            }
            
        }
        
    }

    void display()
    {
        std::cout << "The name of the student is: " << name << std::endl;
        std::cout << "The roll number of the student is: " << rollnum << std::endl;
        std::cout << "Marks in 5 subjects are: ";
        for (int i = 0; i < 5; i++)
        {
            std::cout << marks[i] << ", ";
        }
        std::cout << std::endl;   
    } 

    friend double average_marks(Student obj);   
};

double average_marks(Student obj)
{
    double sum = 0, avgmarks;
    for (int i = 0; i < 5; i++)
    {
       sum = sum + obj.marks[i];
    }
    avgmarks = sum/5;
    return avgmarks;
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    Student obj;
    obj.get_data();
    std::cout << "--------------------------------------------------" << std::endl;
    obj.display();
    std::cout << "Average Marks of 5 subjects is: " << average_marks(obj) << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
