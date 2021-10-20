/* Q1.Take the details from user(name, city, state, address) and pass it as parameters to
a function. The function takes these parameters and prints the details. Make the
country parameter as default. If any user does not provide country details, the
default value should be printed.*/

#include <bits/stdc++.h>
using namespace std;

void print(string name, string city, string state, string address, string country)
{
    std::cout << "Name is: " << name <<std::endl;
    std::cout << "City: " << city <<std::endl;
    std::cout << "State: " << state <<std::endl;
    
    if (country == "")
    {
        std::cout << "Country: " << "India" <<std::endl;
    }
    else
    {
        std::cout << "Country: " << country <<std::endl;
    }
    std::cout << "Address: " << address <<std::endl;
}

int main()
{   
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    string name, city, state, address;
    string country = "India";
    std::cout << "Enter the name: ";
    getline(cin, name);
    std::cout << "Enter the city: ";
    getline(cin, city);
    std::cout << "Enter the state: ";
    getline(cin, state);
    std::cout << "Enter the country: ";
    getline(cin, country);
    std::cout << "Enter the address: ";
    getline(cin, address);
    std::cout << "\n-----------------------------------------------" << std::endl;

    print(name, city, state, address, country);

    std::cout << "\n-----------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    
    return 0;
}
