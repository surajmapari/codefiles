/* Information about the bank account is to be stored and displayed. The account has the information as
the account number, type of the account, name of the account holder, the balance amount of money, password of the account (pin),
account can be of two types, simple or joint account. If the account type is joint, the account holders are going to be 2 or more.
The balance amount of money cannot be less than zero. Pin has to be of exactly 4 digits.
Read information about the number of people having accounts and display it. */

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

struct Account
{
    int accbal, accpin;
    long long int accnum;
    string acctype;
    list<string> accname;
};

class BankAccount
{
private:
    int n;
    string mystring, name;

public:
    struct Account ab;
    void Entry()
    {
        std::cout << "Enter the Account Number: ";
        getline(cin, mystring);
        stringstream(mystring) >> ab.accnum;

        std::cout << "Enter the type of the Account(simple or joint): ";
        getline(cin, ab.acctype);

        if (ab.acctype == "joint")
        {
            std::cout << "How many account holders are their: ";
            while(getline(cin, mystring) && stringstream(mystring) >> n && n <= 1)
            {
                std::cout << "Enter Again.Account holders must be 2 or more." << std::endl;
            }
            
            for (int i = 0; i < n; i++)
            {
                std::cout << "Enter the name of the Account holder " << i + 1 << ": ";
                getline(cin, mystring);
                ab.accname.push_back(mystring);
            }
        }
        else if (ab.acctype == "simple")
        {
            std::cout << "Enter the name of the Account holder: ";
            getline(cin, mystring);
            ab.accname.push_back(mystring);
        }

        std::cout << "Enter the balance amount: ";
        getline(cin, mystring);
        stringstream(mystring) >> ab.accbal;

        std::cout << "Enter the 4 digit password(pin) of the Account: ";
        while (getline(cin,mystring) && mystring.size() != 4)
        {
            std::cout << "Please enter the valid 4 digit pin." << std::endl;
        }
        stringstream(mystring) >> ab.accpin;
        std::cout << std::endl;
    }

    void display()
    {
        std::cout << "Account number is: " << ab.accnum << std::endl;
        std::cout << "Account type is: " << ab.acctype << std::endl;
        if (ab.acctype == "simple")
        {
            std::cout << "Account holder name is: ";
            for (auto const &i : ab.accname)
            {
                std::cout << i;
            }
        }
        else if (ab.acctype == "joint")
        {
            std::cout << "Account holder names are : ";
            for (auto it = ab.accname.begin(); it != ab.accname.end(); ++it)
            {
                std::cout << *it << ", ";
            }
        }

        std::cout << std::endl;
        std::cout << "Account balance is: " << ab.accbal << std::endl;
        std::cout << "Account password(pin) is: " << ab.accpin << std::endl;
    }
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    BankAccount obj;
    struct Account ab;
    obj.Entry();
    std::cout << "--------------------------------------------------" << std::endl;
    obj.display();

    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
