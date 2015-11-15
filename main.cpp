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
    cout << "1. Add a new member" << endl;
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
    cout << "1. Add a new project" << endl;
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
    int memberType;
    string _username, _password, _name, _phone, _email;

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
            case 2:
                goto ProjectMenu;
            case 3:
                goto ManageMenu;
            case 4:
                goto AdminMenu;
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
            SignUp:
                cout << endl;
                cout << "      Add a new member      " << endl;
                cout << "----------------------------" << endl;
                cout << ">> Please enter member type:" << endl;
                cout << "    1. Student" << endl;
                cout << "    2. Teacher" << endl;
                cin >> _selector;
                selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                switch (selector) {
                    case 1:
                        memberList.push_front(new student);
                        break;
                    case 2:
                        memberList.push_front(new teacher);
                        break;
                    default:
                        break;
                }
                memberIter = memberList.begin();
                cout << ">> Please enter username:" << endl;
                cin >> _username;
                (*memberIter)->setUsername(_username);
                cout << ">> Please enter password:" << endl;
                cin >> _password;
                (*memberIter)->chgPwd("",_password);
                cout << ">> Please enter name:" << endl;
                cin >> _name;
                (*memberIter)->setName(_name);
                cout << ">> Please enter phone:" << endl;
                cin >> _phone;
                (*memberIter)->setPhone(ValidInfo::validSelector(_phone, "0123456789-"));
                cout << ">> Please enter E-mail:" << endl;
                cin >> _email;
                (*memberIter)->setEmail(ValidInfo::validEmail(_email));
                cout << "Congratulations! You've successfully add a new member." << endl
                     << "Following are what you input: " << endl;
                (*memberIter)->printInfo();
                cout << ">> Thwn you want to:" << endl;
                cout << "    1. Add another member" << endl;
                cout << "    2. Back to Member Menu" << endl;
                cin >> _selector;
                selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                switch (selector) {
                    case 1:
                        goto SignUp;
                    case 2:
                        goto MemberMenu;
                    default:
                        break;
                }
                break;
            case 2:
                cout << endl;
                cout << "      List all members      " << endl;
                cout << "----------------------------" << endl;
                memberIter = memberList.begin();
                for (int i = 1; memberIter != memberList.end();i++, memberIter++) {
                    cout << i << ". " << (*memberIter)->getName() << endl;
                }
                cout << "----------------------------" << endl;
                cout << endl;
                goto MainMenu;
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