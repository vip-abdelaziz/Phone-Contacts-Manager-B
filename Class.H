#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact
{

private:
    string Name;
    string Phone;
    string Email;
    string Address;

public:
    void setName(string name)
    {
        if (name == " " || name == "")
        {
            cout << "You must enter the name\n";
        }
        else
        {
            Name = name;
        }
    }
    void setPhone(string phone)
    {
        Phone = phone;
    }
    void setEmail(string email)
    {
        Email = email;
    }
    void setAddress(string address)
    {
        Address = address;
    }
    string getName()
    {
        return Name;
    }
    string getPhone()
    {
        return Phone;
    }
    string getEmail()
    {
        return Email;
    }
    string getAddress()
    {
        return Address;
    }
    void Display()
    {
        cout << "+---------------------------+\n";
        cout << "| Name    : " << Name    << "\n";
        cout << "| Phone   : " << Phone   << "\n";
        cout << "| Email   : " << Email   << "\n";
        cout << "| Address : " << Address << "\n";
        cout << "+---------------------------+\n";
    }
};
