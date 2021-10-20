//Write a simple C++ program to validate username and password using Class and Object:
//If username is "user" and password is "pwd" then print successful message else print unsuccessful.

#include <iostream>
using namespace std;

class login
{
private:
    string user1, pwd1;

public:
    void loginfunc(string user1, string pwd1)
    {
        if (user1 == "user" && pwd1 == "pwd")
        {
            std::cout << "\nLogin Successful" << std::endl;            
        }
        else
        {
            std::cout << "\nLogin Unsuccessful (Invalid Username or Password)" << std::endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    string user, pwd;
    std::cout << "Enter the username: ";
    cin >> user;
    std::cout << "\nEnter the password: ";
    cin >> pwd;
    
    login obj;    
    obj.loginfunc(user, pwd);
    
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}
