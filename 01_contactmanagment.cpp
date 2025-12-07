#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>
using namespace std;
class Contact
{
public:
    string name;
    string mob;
    string email;
    string Address;
    void input()
    {
        cin.ignore();
        cout << "Enter Name : ";
        getline(cin, name);

        cout << "Enter Mobile NUmber : ";
        cin.ignore();
        getline(cin, mob);

        cout << "Enter YOur Email.. : ";
        cin.ignore();
        getline(cin, email);

        cout << "Enter your Address : ";
        cin.ignore();
        getline(cin, Address);
    }

    void display()
    {
        cout << "| Name : " << name << "| Mobile Number : " << mob << " | Email : " << email << " | Address : "
             << Address << "\n";
    }
};
vector<Contact> contact;
void savedata()
{
    ofstream file("contact.txt");
    if (!file)
    {
        cout << "File not Found --\n";
        return;
    }
    for (int i = 0; i < contact.size(); i++)
    {
        file << contact[i].name << endl;
        file << contact[i].mob << endl;
        file << contact[i].email << endl;
        file << contact[i].Address << endl;
    }
    file.close();
}
void loaddata()
{
    ifstream file("contact.txt");
    if (!file)
        return;

    Contact object;

    while (true)
    {
        getline(file, object.name);
        if (file.fail())
            break;

        file >> object.mob;
        file.ignore();

        getline(file, object.email);
        getline(file, object.Address);

        contact.push_back(object);
    }

    file.close();
}

void addContact()
{
    Contact object;
    object.input();
    contact.push_back(object);
    savedata();
    cout << "Contact Add sucessfuilly-----\n";
}
void searchContact()
{
    Contact object;
    string mobi;
    cout << "Enter Mobile : ";
    cin.ignore();
    getline(cin, mobi);
    for (int i = 0; i < contact.size(); i++)
    {
        if (contact[i].mob == mobi)
        {
            contact[i].display();
            return;
        }
    }
}
void deleteContact()
{
    Contact object;
    string mobi;
    cout << "Enter Mobile Number : ";
    cin.ignore();
    getline(cin, mobi);
    bool found = false;
    for (int i = 0; i < contact.size(); i++)
    {
        if (contact[i].mob == mobi)
        {
            contact.erase(contact.begin() + i);
            savedata();
            found = true;
            cout << "Contact Delete sucessfully \n";
            break;
        }
    }
    if (!found)
    {
        cout << "contact not found \n";
    }
}

void updateContact()
{
    cin.ignore();
    string searchname;
    cout << "Enter the Name you want to update : ";
    getline(cin, searchname);

    bool found = false;
    for (int i = 0; i < contact.size(); i++)
    {
        if (contact[i].name == searchname)
        {
            found = true;
            cout << "Crunt Contact \n";
            contact[i].display();
            cout << "Enter new Contact------\n";
            contact[i].input();
            savedata();
            cout << "\n--Contact Add sucessfuilly------\n";
            break;
        }
    }
    if (!found)
    {
        cout << "Contact not found in hear\n";
    }
}
void showAllContact()
{
    if (contact.empty())
    {
        cout << "No contacts found!\n";
        return;
    }
    cout << "\n---------- All Contacts ----------\n";
    for (int i = 0; i < contact.size(); i++)
    {
        contact[i].display();
    }
}

void sortContact()
{
    if (contact.size() < 2)
    {
        cout << "Not enough to Sort the Contact ";
    }
    sort(contact.begin(), contact.end(),
         [](Contact a, Contact b)
         { return a.name < b.name; });

    savedata();
    cout << "Contacts sorted successfully!\n";
}

int main()
{
    loaddata();
    int choice;
    while (true)
    {
        cout << "\n----------Contact Managment System----------\n";
        cout << "1.Add Contact\n";
        cout << "2.Search Contact\n";
        cout << "3.Delete Contact\n";
        cout << "4.Update Contact\n";
        cout << "5.Show All Contact\n";
        cout << "6.Sort Contact \n";
        cout << "7.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            deleteContact();
            break;
        case 4:
            updateContact();
            break;
        case 5:
            showAllContact();
            break;
        case 6:
            sortContact();
            break;
        case 7:
            cout << "Exiting........";
            return 0;

        default:
            cout << "-----Invalid Choice ------";
            return 0;
        }
    }

    return 0;
}