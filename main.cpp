#include "Member.h"
#include "Project.h"
#include "ValidInfo.h"
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <cstdlib>

using namespace std;

string _selector;
int selector;

void mainMenu() {
    cout << "==========================================================" << endl;
    cout << "                        Main Menu                         " << endl;
    cout << "==========================================================" << endl;
    cout << "1. Member" << endl;
    cout << "2. Project" << endl;
    cout << "3. Management" << endl;
    cout << "4. Administration" << endl;
    cout << "5. Quit" << endl;
    cout << ">> Please choose one operation: ";
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector, "12345").c_str());
}

void memberMenu() {
    cout << "==========================================================" << endl;
    cout << "                       Member Menu                        " << endl;
    cout << "==========================================================" << endl;
    cout << "1. Add new member" << endl;
    cout << "2. List all members" << endl;
    cout << "3. Back" << endl;
    cout << ">> Please choose one operation: ";
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector, "123").c_str());
}

void projectMenu() {
    cout << "==========================================================" << endl;
    cout << "                       Project Menu                       " << endl;
    cout << "==========================================================" << endl;
    cout << "1. Add new project" << endl;
    cout << "2. List all projects" << endl;
    cout << "3. Edit projects" << endl;
    cout << "4. Back" << endl;
    cout << ">> Please choose one operation: ";
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector, "1234").c_str());
}

void manageMenu() {
    cout << "==========================================================" << endl;
    cout << "                     Management Menu                      " << endl;
    cout << "==========================================================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Show Profile" << endl;
    cout << "3. Edit Profile" << endl;
    cout << "4. Change Password" << endl;
    cout << "5. Participate in a project" << endl;
    cout << "6. Back" << endl;
    cout << ">> Please choose one operation: ";
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector, "123456").c_str());
}

void adminMenu() {
    cout << "==========================================================" << endl;
    cout << "                        Admin Menu                        " << endl;
    cout << "==========================================================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Edit user information" << endl;
    cout << "3. Edit project information" << endl;
    cout << "4. Back" << endl;
    cout << ">> Please choose one operation: ";
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector, "1234").c_str());
}
int main() {
    list<member*> memberList;
    list<member*>::iterator memberIter;
    member *loggedMember = new member();
    bool _logged = false;
    string _username, _password, name, _phone, _email;

    cout << "==========================================================" << endl;
    cout << "|      |     |\\  /|                                     | " << endl;
    cout << "|  /~~||~~\\  | \\/ |/~~||/~\\ /~~|/~~|/~/|/~\\ /~\\ /~/|/~\\~|~" << endl;
    cout << "|__\\__||__/  |    |\\__||   |\\__|\\__|\\/_|   |   |\\/_|   || " << endl;
    cout << "                                \\__|       Ver 2015.11.16 " << endl;
    cout << "==========================================================" << endl;
    cout << "           Welcome to the Lab Management System.          " << endl;
    cout << endl;
    cout << endl;

    MainMenu:
        mainMenu();
        switch (selector) {
            case 1:
                goto MemberMenu;
                break;
            case 2:
                goto ProjectMenu;
                break;
            case 3:
                goto ManageMenu;
                break;
            case 4:
                goto AdminMenu;
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                break;
        }
    MemberMenu:
        memberMenu();
        switch (selector) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                goto MainMenu;
            default:
                break;
        }
    ProjectMenu:
        projectMenu();
        switch (selector) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                goto MainMenu;
            default:
                break;
        }
    ManageMenu:
        manageMenu();
        switch (selector) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                goto MainMenu;
            default:
                break;
        }
    AdminMenu:
        adminMenu();
        switch (selector) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                goto MainMenu;
            default:
                break;
        }
    return  0;
}