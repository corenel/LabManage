#include "Member.h"
#include "Project.h"
#include "ValidInfo.h"
#include "cstdlib"
#include <iostream>
#include <string>
#include <list>
#include <iomanip>

using namespace std;

int selector;
string _selector;

void mainMenu() {
    cout << "Main Menu: " << endl;
    cout << "1. Member" << endl;
    cout << "2. Project" << endl;
    cout << "3. Management" << endl;
    cout << "4. Administration" << endl;
    cout << "5. Quit" << endl;
    cout << "Please choose one operation: " << endl;
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector).c_str());
}

void memberMenu() {
    cout << "Member Menu" << endl;
    cout << "1. Add new member" << endl;
    cout << "2. List all members" << endl;
    cout << "3. Back" << endl;
    cout << "Please choose one operation: " << endl;
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector).c_str());
}

void projectMenu() {
    cout << "Project Menu" << endl;
    cout << "1. Add new project" << endl;
    cout << "2. List all projects" << endl;
    cout << "3. Edit projects" << endl;
    cout << "4. Back" << endl;
    cout << "Please choose one operation: " << endl;
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector).c_str());
}

void manageMenu() {
    cout << "Management Menu" << endl;
    cout << "1. Login" << endl;
    cout << "2. Show Profile" << endl;
    cout << "3. Edit Profile" << endl;
    cout << "4. Change Password" << endl;
    cout << "5. Participate in a project" << endl;
    cout << "6. Back" << endl;
    cout << "Please choose one operation: " << endl;
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector).c_str());
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

    return  0;
}