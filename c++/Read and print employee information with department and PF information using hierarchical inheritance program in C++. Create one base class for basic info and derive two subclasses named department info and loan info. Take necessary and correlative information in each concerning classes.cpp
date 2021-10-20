/* Q.Read and print employee information with department and PF information using hierarchical 
inheritance program in C++. Create one base class for basic info and derive two subclasses named
department info and loan info. Take necessary and correlative information in each concerning classes.*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
 
class basic_info
{
public:
    string name, empid, gender;
    void set_basicinfo()
    {
        std::cout << "Enter your name: ";
        getline(cin, name);
        std::cout << "Enter your gender: ";
        getline(cin, gender);
        std::cout << "Enter the of your employee id: ";
        getline(cin, empid);
    }

    void display()
    {
        std::cout << "Your name is: " << name << std::endl;
        std::cout << "Your gender is: " << gender << std::endl;
        std::cout << "Your empid is: " << empid << std::endl;
    }
};

class department_info: public basic_info
{   
public:
    string department;

    void set_dept()
    {   
        basic_info::set_basicinfo();
        std::cout << "Enter the name of the your department(computer/finance/marketing/etc): ";
        getline(cin, department);
    }

    void display()
    {
        std::cout << "Your name is: " << name << std::endl;
        std::cout << "Your gender is: " << gender << std::endl;
        std::cout << "Your empid is: " << empid << std::endl;
        std::cout << "Your department is: " << department << std::endl;
    }
};

class loan_info: public basic_info
{
private:
    string mystr;    
public:
    double loan;

    void set_loan()
    {   
        basic_info::set_basicinfo();
        std::cout << "Enter the amount of loan taken: ";
        getline(cin, mystr);
        stringstream(mystr) >> loan;
    }

    void display()
    {
        std::cout << "Your name is: " << name << std::endl;
        std::cout << "Your gender is: " << gender << std::endl;
        std::cout << "Your empid is: " << empid << std::endl;
        std::cout << "Your amount of loan taken is: " << loan << std::endl;
    }
};


int main()
{
std::cout << "\n--------------------------------------------------" << std::endl;
std::cout << "--------------------------------------------------" << std::endl;

department_info obj;
obj.set_dept();
obj.display();

std::cout << "--------------------------------------------------" << std::endl;

loan_info obj1;
obj1.set_loan();
obj1.display();
 
std::cout << "--------------------------------------------------" << std::endl;
std::cout << "--------------------------------------------------" << std::endl;
 
return 0;
}
