//Write a program in C++ to enroll student in course
//display subject with maximum marks out of three

#include <iostream>
#include <stdio.h>
using namespace std;

struct course
{
    string name;
    int sub1marks;
    int sub2marks;
    int sub3marks;
};

class Course
{
private:
    int sub1m, sub2m, sub3m;
    int maxm;

public:
    int count;
    void analyze(int sub1m, int sub2m, int sub3m)
    {
        if (sub1m > sub2m && sub1m > sub3m)
        {
            count = 1;
            maxm = sub1m;
        }
        else if (sub2m > sub1m && sub2m > sub3m)
        {
            count = 2;
            maxm = sub2m;
        }
        else
        {
            count = 3;
            maxm = sub3m;
        }
        std::cout << "(subject1, subject2, subject3) = (" << sub1m << ", " << sub2m << ", " << sub3m << ")";
        std::cout << "\nsubject with the maximum marks is \""
                  << "subject" << count << " with " << maxm << " marks\"";
    };
};

int main()
{
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------------------------" << std::endl;

    int n;
    std::cout << "Enter the number of stuents to enroll: ";
    cin >> n;
    struct course c[n];
    std::cout << "-----------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the name of the student" << i + 1 << ": ";
        cin >> c[i].name;
        std::cout << "Enter the marks of the subject1 of student" << i + 1 << ": ";
        cin >> c[i].sub1marks;
        std::cout << "Enter the marks of the subject2 of student" << i + 1 << ": ";
        cin >> c[i].sub2marks;
        std::cout << "Enter the marks of the subject3 of student" << i + 1 << ": ";
        cin >> c[i].sub3marks;
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------" << std::endl;

    Course cobj;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Name of the student" << i + 1 << " is: " << c[i].name << std::endl;
        cobj.analyze(c[i].sub1marks, c[i].sub2marks, c[i].sub3marks);
        std::cout << "\n" << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------------------------" << std::endl;

    return 0;
}
