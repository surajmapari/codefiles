/*ATM access is to be given to the account holders.
The operations user will be able to carry out are as follows: deposit and withdraw amount,
change pin, update the information of an account, remove account.*/

#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class BankAccount
{
private:
    int depositamount, withdrawamount, n, findaccnum;
    string mystring;

public:
    int accbal = 0, accpin;
    long long accnum;
    string acctype;
    list<string> accname;

    void _account()
    {
        std::cout << "Enter the Account Number: ";
        getline(cin, mystring);
        stringstream(mystring) >> accnum;
        //std::cout <<  << std::endl;

        std::cout << "Enter the type of the Account(simple or joint): ";
        getline(cin, acctype);

        if (acctype == "joint")
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
                accname.push_back(mystring);
            }
        }
        else if (acctype == "simple")
        {
            std::cout << "Enter the name of the Account holder: ";
            getline(cin, mystring);
            accname.push_back(mystring);
        }

        std::cout << "Enter the balance amount: ";
        getline(cin, mystring);
        stringstream(mystring) >> accbal;

        std::cout << "Enter the 4 digit password(pin) of the Account: ";
        while (getline(cin, mystring) && mystring.size() != 4)
        {
            std::cout << "Enter Again.Pin must be of 4 digits only." << std::endl;
        }
        stringstream(mystring) >> accpin;
        std::cout << "--------------------------------------------------" << std::endl;
    }

    void deposit()
    {
        std::cout << "Enter the amount to deposit: ";
        getline(cin, mystring);
        stringstream(mystring) >> depositamount;
        accbal = accbal + depositamount;
        std::cout << "Your Updated balance is: " << accbal << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }

    void withdraw()
    {
        std::cout << "Enter the amount to withdraw: ";
        getline(cin, mystring);
        stringstream(mystring) >> withdrawamount;

        if (accbal - withdrawamount >= 0)
        {
            accbal = accbal - withdrawamount;
            std::cout << "Your Updated balance is: " << accbal << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;
        }
        else if (accbal == 0)
        {
            std::cout << "Can't Withdraw Your Total Balance is: " << accbal << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;
        }
        else
        {
            int negamount = accbal - withdrawamount;
            int removeamount = withdrawamount - (-negamount);
            accbal = accbal - removeamount;
            std::cout << "You were able to withdraw only: " << removeamount << std::endl;
            std::cout << "Your Updated balance is: " << accbal << std::endl;
            std::cout << "--------------------------------------------------" << std::endl;
        }
    }

    void change_pin()
    {
        std::cout << "Enter the new pin: ";
        while (getline(cin, mystring) && mystring.size() != 4)
        {
            std::cout << "Please enter the valid 4 digit pin." << std::endl;
        }
        stringstream(mystring) >> accpin;
        std::cout << "Your account pin changed successfully" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }

    void show_info()
    {
        std::cout << "Account number is: " << accnum << std::endl;
        std::cout << "Account type is: " << acctype << std::endl;
        if (acctype == "simple")
        {
            std::cout << "Account holder name is: ";
            for (auto const &i : accname)
            {
                std::cout << i;
            }
        }
        else if (acctype == "joint")
        {
            std::cout << "Account holder names are : ";
            for (auto it = accname.begin(); it != accname.end(); ++it)
            {
                std::cout << *it << ", ";
            }
        }
        std::cout << std::endl;
        std::cout << "Account balance is: " << accbal << std::endl;
        std::cout << "Account password(pin) is: " << accpin << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }

    void update_account()
    {
        std::cout << "Enter the new details of the account: " << std::endl;
        _account();
    }
};

int main()
{
    std::cout << "\n--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    BankAccount bankaobj;
    std::cout << "Creating the new account..." << std::endl;
    bankaobj._account();
    std::cout << "Account created successfully." << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    int n;
    do
    {
        std::cout << "1.Deposit the amount" << std::endl;
        std::cout << "2.Withdraw the amount" << std::endl;
        std::cout << "3.Change pin of the account" << std::endl;
        std::cout << "4.Show account information" << std::endl;
        std::cout << "5.Update information of the account" << std::endl;
        std::cout << "6.Remove/Delete the account" << std::endl;
        std::cout << "7.Exit" << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        string mystring;
        std::cout << "Enter the task number you want to do: ";
        getline(cin, mystring);
        stringstream(mystring) >> n;

        switch (n)
        {
        case 1:
            bankaobj.deposit();
            break;
        case 2:
            bankaobj.withdraw();
            break;
        case 3:
            bankaobj.change_pin();
            break;
        case 4:
            bankaobj.show_info();
            break;
        case 5:
            bankaobj.update_account();
            break;
        case 6:
            // BankAccount object has already been created. Object will automatically gets deleted after
            //it becomes out of scope. It means the end of program
            break;
        case 7:
            //exiting the program
            break;
        default:
            break;
        }
    } while (n != 6 && n != 7);

    if (n == 6)
    {
        std::cout << "Account deleted successfully." << std::endl;
    }

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}
