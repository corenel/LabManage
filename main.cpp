#include "Member.h"
#include "Project.h"
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
    cout << "3. Quit" << endl;
    cout << "Please choose one: " << endl;
    cin >> _selector;
    selector = atoi(_selector);
}

void memberMenu() {
    cout << "Member Menu" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Login" << endl;
    cout << "3. Show Profile" << endl;
    cout << "4. Edit Profile" << endl;
    cout << "5. Change Password" << endl;
    cout << "6. List all members" << endl;
    cin >> _selector;
    selector = atoi(_selector);
}

void projectMenu() {
    cout << "Project Menu" << endl;
    cout << "1. Add new project" << endl;
    cout << "2. List all projects" << endl;
    cout << "3. Edit projects" << endl;
    cin >> _selector;
    selector = atoi(_selector);
}