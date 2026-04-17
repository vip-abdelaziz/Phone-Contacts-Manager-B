// #include<cmath>
#include <iostream>
#include <cctype>
#include <limits>
// #include <array>
#include <algorithm> // علشان نستخدم sort , reverse , count
// #include <string.h> // for funcution name is strcat()
#include "Classes.h"
#include <vector>
using namespace std;
/*
-1 Add contact
-2 Display All contact
-3 Search contact
-4 Update contact
-5 Show contact count
-0 Exit
*/

void showMenu();
void Add();
void Display();
void Search();
void Update();
void Count();

string RemoveSpace(string str);
bool IsAllDigits(string str);

vector<Contact> contacts;
int main()
{

    int chooser;
    do
    {
        showMenu();
        cin >> chooser;
        while (chooser > 5 || chooser < 0)
        {
            cout << "Invalid option\nEnter again from 0 to 5\n";
            cin >> chooser;
        }
        switch (chooser)
        {
        case 1:
            Add();
            break;
        case 2:
            Display();
            break;
        case 3:
            Search();
            break;
        case 4:
            Update();
            break;
        case 5:
            Count();
            break;
        case 0:
            cout << "Thanks :) \n";
        }

    } while (chooser != 0);
}

void showMenu()
{
    cout << "\n+-----------------------------------+\n";
    cout << "|       PHONE CONTACTS MANAGER      |\n";
    cout << "+-----------------------------------+\n";
    cout << "| 1. Add Contact                   |\n";
    cout << "| 2. Display Contacts              |\n";
    cout << "| 3. Search Contact                |\n";
    cout << "| 4. Update Contact                |\n";
    cout << "| 5. Contacts Count                |\n";
    cout << "| 0. Exit                          |\n";
    cout << "+-----------------------------------+\n";
    cout << "Enter choice: ";
}

void Add()
{
    int number;
    cout << "\n[ Add Contact ]\n";
    cout << "How many contacts to add? ";
    cin >> number;

    while (number <= 0)
    {
        cout << "Invalid! Enter a positive number: ";
        cin >> number;
    }

    for (int i = 0; i < number; i++)
    {
        string name, phone, email, address;
        Contact c1;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n--- Contact " << i + 1 << " ---\n";

        cout << "Name    : ";
        cin >> name;
        c1.setName(name);

        cout << "Phone   : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, phone);
        phone = RemoveSpace(phone);
        c1.setPhone(phone);

        cout << "Email  (option) : ";
        cin >> email;
        c1.setEmail(email);

        cout << "Address : ";
        cin >> address;
        c1.setAddress(address);

        contacts.push_back(c1);
        cout << "Contact added successfully!\n";
    }
}
void Display()
{
    for (int i = 0; i < contacts.size(); i++)
    {
        contacts[i].Display();
    }
}

void Search()
{
    bool found = false;
    string phoneSearch;
    cout << "enter the phone for search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, phoneSearch);
    phoneSearch = RemoveSpace(phoneSearch);

    for (int i = 0; i < contacts.size(); i++)
    {
        if (phoneSearch == contacts[i].getPhone())
        {
            contacts[i].Display();
            found = true;
        }
    }
    if (!found)
        cout << "Not Found\n";
}
void Update()
{
    string phoneSearch;
    cout << "\n[ Update Contact ]\n";
    cout << "Enter phone to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, phoneSearch);
    phoneSearch = RemoveSpace(phoneSearch);

    for (int i = 0; i < contacts.size(); i++)
    {
        if (phoneSearch == contacts[i].getPhone())
        {
            cout << "\nContact found:\n";
            contacts[i].Display();

            string newName, newPhone, newEmail, newAddress;

            cout << "\n--- Enter new values (or press Enter to keep) ---\n";

            cout << "Name    : ";
            getline(cin, newName);
            if (!newName.empty())

contacts[i].setName(newName);

            cout << "Phone   : ";
            getline(cin, newPhone);
            newPhone = RemoveSpace(newPhone);
            if (!newPhone.empty())
                contacts[i].setPhone(newPhone);

            cout << "Email   : ";
            getline(cin, newEmail);
            if (!newEmail.empty())
                contacts[i].setEmail(newEmail);

            cout << "Address : ";
            getline(cin, newAddress);
            if (!newAddress.empty())
                contacts[i].setAddress(newAddress);

            cout << "\nUpdated successfully!\n";
            contacts[i].Display();
            return;
        }
    }

    cout << "Not Found!\n";
}
void Count()
{
    cout << "Your count is " << contacts.size() << endl;
}

string RemoveSpace(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
