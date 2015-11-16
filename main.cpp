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
int member::memberIDCnt = 0;
int project::prjIDCnt = 0;

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
    cout << "3. Back" << endl;
    cout << ">> Please choose one operation: ";
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector, "123").c_str());
}

void manageMenu() {
    cout << "==========================================================" << endl;
    cout << "                     Management Menu                      " << endl;
    cout << "==========================================================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Show Profile" << endl;
    cout << "3. Edit Profile" << endl;
    cout << "4. Participate in a project" << endl;
    cout << "5. Quit a project" << endl;
    cout << "6. List my project" << endl;
    cout << "7. List participant of a project" << endl;
    cout << "8. Back" << endl;
    cout << ">> Please choose one operation: ";
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector, "12345678").c_str());
}

void adminMenu() {
    cout << "==========================================================" << endl;
    cout << "                        Admin Menu                        " << endl;
    cout << "==========================================================" << endl;
    cout << "0. Show my permission" << endl;
    cout << "1. Edit user password" << endl;
    cout << "2. Edit project information" << endl;
    cout << "3. Delete a member" << endl;
    cout << "4. Delete a project" << endl;
    cout << "5. Back" << endl;
    cout << ">> Please choose one operation: ";
    cin >> _selector;
    selector = atoi(ValidInfo::validSelector(_selector, "012345").c_str());
}
int main() {
    list<member*> memberList;
    list<member*>::iterator memberIter;
    member *loggedMember;
    bool _logged = false;
    int memberType;
    list<project*> prjList;
    list<project*>::iterator prjIter;
    string _username, _password, _currentpwd, _name, _phone, _email, _prjName, _prjDDL;

    member *m1, *m2, *m3, *su;
    project *p1, *p2;
    su = new admin("admin", "admin", "Super User", "123", "xx@xx.xx");
    m1 = new student("zs", "zs", "Zhang San", "123", "xx@xx.xx");
    m2 = new student("ls", "ls", "Li si", "123", "xx@xx.xx");
    m3 = new teacher("wh", "wh", "Wang Hui", "123", "xx@xx.xx");
    memberList.push_front(su);
    memberList.push_front(m1);
    memberList.push_front(m2);
    memberList.push_front(m3);
    p1 = new project("OOP Final Project", "2015-11-16");
    p2 = new project("Mid Term test", "2015-11-12");
    prjList.push_front(p1);
    prjList.push_front(p2);

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
            case 2:
                cout << endl;
                cout << "      List all members      " << endl;
                cout << "----------------------------" << endl;
                for (memberIter = memberList.begin(); memberIter != memberList.end(); memberIter++) {
                    cout << (*memberIter)->getID() << ". " << (*memberIter)->getName() << endl;
                }
                cout << "----------------------------" << endl;
                cout << endl;
                goto MemberMenu;
            case 3:
                goto MainMenu;
            default:
                break;
        }
    ProjectMenu:
        projectMenu();
        switch (selector) {
            case 1:
            AddPrj:
                cout << endl;
                cout << "       Add new project      " << endl;
                cout << "----------------------------" << endl;
                prjList.push_front(new project);
                prjIter = prjList.begin();
                cout << ">> Please enter project name:" << endl;
                cin >> _prjName;
                (*prjIter)->setName(_prjName);
                cout << ">> Please enter project DeadLine:" << endl;
                cin >> _prjDDL;
                (*prjIter)->setDDL(_prjDDL);
                cout << "Congratulations! You've successfully add a new project." << endl
                << "Following are what you input: " << endl;
                (*prjIter)->printPrj();
                cout << ">> Then you want to:" << endl;
                cout << "    1. Add another projrct" << endl;
                cout << "    2. Back to Project Menu" << endl;
                cin >> _selector;
                selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                switch (selector) {
                    case 1:
                        goto AddPrj;
                    case 2:
                        goto ProjectMenu;
                    default:
                        break;
                }
            case 2:
                cout << endl;
                cout << "      List all members      " << endl;
                cout << "----------------------------" << endl;
                for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                    cout << (*prjIter)->getID() << ". " << (*prjIter)->getName() << endl;
                }
                cout << "----------------------------" << endl;
                cout << endl;
                goto MainMenu;
            case 3:
                goto MainMenu;
            default:
                break;
        }
    ManageMenu:
        manageMenu();
        switch (selector) {
            case 1:
            Login:
                cout << endl;
                cout << "          Login in          " << endl;
                cout << "----------------------------" << endl;
                cout << ">> Please enter your username: " << endl;
                cin >> _username;
                cout << ">> Please enter your password: " << endl;
                cin >> _password;
                for (memberIter = memberList.begin(); memberIter != memberList.end(); memberIter++) {
                    if ((*memberIter)->checkAcct(_username, _password)) {
                        cout << endl;
                        cout << "Login Successfuly!" << endl;
                        cout << "Welcome " << (*memberIter)->getName() << endl;
                        cout << endl;
                        loggedMember = *memberIter;
                        _logged = true;
                        goto ManageMenu;
                    }
                }
                cout << "Error: Invalid username or password. Please try again." << endl;
                goto Login;
            case 2:
                cout << endl;
                cout << "        Show Profile        " << endl;
                cout << "----------------------------" << endl;
                if (!_logged) {
                    cout << "Please login first." << endl;
                    goto Login;
                }
                else {
                    loggedMember->printInfo();
                }
                goto ManageMenu;
            case 3:
            EditProfile:
                cout << endl;
                cout << "        Edit Profile        " << endl;
                cout << "----------------------------" << endl;
                if (!_logged) {
                    cout << "Please login first." << endl;
                    goto Login;
                }
                else {
                    cout << "1. Name" << endl;
                    cout << "2. Phone" << endl;
                    cout << "3. E-mail" << endl;
                    cout << "4. Username" << endl;
                    cout << "5. Password" << endl;
                    cout << "6. Back" << endl;
                    cout << ">> Please choose one operation: ";
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "123456").c_str());
                    switch (selector) {
                        case 1:
                            cout << ">> Please enter name:" << endl;
                            cin >> _name;
                            loggedMember->setName(_name);
                            cout << "Your name has been changede to " << loggedMember->getName() << " successfully!" << endl;
                            goto EditProfile;
                        case 2:
                            cout << ">> Please enter phone:" << endl;
                            cin >> _phone;
                            loggedMember->setPhone(ValidInfo::validSelector(_phone, "0123456789-"));
                            cout << "Your phone has been changede to " << loggedMember->getPhone() << " successfully!" << endl;
                            goto EditProfile;
                        case 3:
                            cout << ">> Please enter E-mail:" << endl;
                            cin >> _email;
                            loggedMember->setEmail(ValidInfo::validEmail(_email));
                            cout << "Your E-mail has been changede to " << loggedMember->getEmail() << " successfully!" << endl;
                            goto EditProfile;
                        case 4:
                            cout << ">> Please enter username:" << endl;
                            cin >> _username;
                            loggedMember->setUsername(_username);
                            cout << "Your username has been changede to " << loggedMember->getUsername() << " successfully!" << endl;
                            goto EditProfile;
                        case 5:
                        ChgPwd:
                            cout << ">> Please enter your current password:" << endl;
                            cin >> _currentpwd;
                            if (loggedMember->checkAcct(loggedMember->getUsername(), _currentpwd)){
                                cout << ">> Please enter your expected password:" << endl;
                                cin >> _password;
                                loggedMember->chgPwd(_currentpwd,_password);
                                goto EditProfile;
                            }
                            else {
                                std::cout << "Error: Invalid current password. Please try again." << std::endl;
                                goto ChgPwd;
                            }
                        case 6:
                            goto ManageMenu;
                        default:
                            break;
                    }
                }
            case 4:
            PartInPrj:
                cout << endl;
                cout << "  Participate in a project  " << endl;
                cout << "----------------------------" << endl;
                if (!_logged) {
                    cout << "Please login first." << endl;
                    goto Login;
                }
                else {
                    cout << "Plaease choose a project to take part in: " << endl;
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        cout << (*prjIter)->getID() << ". " << (*prjIter)->getName() << endl;
                    }
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "1234567890").c_str());
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        if ((*prjIter)->getID() == selector) {
                            (*prjIter)->addMember(loggedMember);
                            loggedMember->addPrj(*prjIter);
                            cout << "Congratulations! You've participated in " << (*prjIter)->getName() << " successfully!" << endl;
                            break;
                        }
                    }
                    cout << ">> Then you want to:" << endl;
                    cout << "    1. Participate in another projrct" << endl;
                    cout << "    2. Back to Manage Menu" << endl;
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                    switch (selector) {
                        case 1:
                            goto PartInPrj;
                        case 2:
                            goto ManageMenu;
                        default:
                            break;
                    }
                }
            case 5:
            QuitPrj:
                cout << endl;
                cout << "       Quit a project       " << endl;
                cout << "----------------------------" << endl;
                if (!_logged) {
                    cout << "Please login first." << endl;
                    goto Login;
                }
                else {
                    cout << "Plaease choose a project to quit: " << endl;
                    loggedMember->printMyPrj();
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "1234567890").c_str());
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        if ((*prjIter)->getID() == selector) {
                            (*prjIter)->removeMember(loggedMember);
                            loggedMember->removePrj(*prjIter);
                            cout << "Congratulations! You've quit " << (*prjIter)->getName() << " successfully!" << endl;
                            break;
                        }
                    }
                    cout << ">> Then you want to:" << endl;
                    cout << "    1. Quit another projrct" << endl;
                    cout << "    2. Back to Manage Menu" << endl;
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                    switch (selector) {
                        case 1:
                            goto QuitPrj;
                        case 2:
                            goto ManageMenu;
                        default:
                            break;
                    }
                }
            case 6:
                cout << endl;
                cout << "       List my project      " << endl;
                cout << "----------------------------" << endl;
                if (!_logged) {
                    cout << "Please login first." << endl;
                    goto Login;
                }
                else {
                    loggedMember->printMyPrj();
                    goto ManageMenu;
                }
            case 7:
            PrintPrj:
                cout << endl;
                cout << "List participant of a project" << endl;
                cout << "----------------------------" << endl;
                if (!_logged) {
                    cout << "Please login first." << endl;
                    goto Login;
                }
                else {
                    cout << "Plaease choose a project to list: " << endl;
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        cout << (*prjIter)->getID() << ". " << (*prjIter)->getName() << endl;
                    }
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "1234567890").c_str());
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        if ((*prjIter)->getID() == selector) {
                            (*prjIter)->printPrj();
                            break;
                        }
                    }
                    cout << ">> Then you want to:" << endl;
                    cout << "    1. List another projrct" << endl;
                    cout << "    2. Back to Manage Menu" << endl;
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                    switch (selector) {
                        case 1:
                            goto PrintPrj;
                        case 2:
                            goto ManageMenu;
                        default:
                            break;
                    }
                }
            case 8:
                goto MainMenu;
            default:
                break;
        }
    AdminMenu:
        adminMenu();
        switch (selector) {
            case 0:
                cout << endl;
                cout << "      Show my permission    " << endl;
                cout << "----------------------------" << endl;
                if (!_logged) {
                    cout << "Please login first." << endl;
                    goto Login;
                }
                else {
                    loggedMember->showPermission();
                    goto AdminMenu;
                }
            case 1:
            EditUser:
                cout << endl;
                cout << "      Edit User password    " << endl;
                cout << "----------------------------" << endl;
                if (_logged && (loggedMember->getLevel() == 3) ) {
                    cout << "Plaease choose a user to edit: " << endl;
                    for (memberIter = memberList.begin(); memberIter != memberList.end(); memberIter++) {
                        cout << (*memberIter)->getID() << ". " << (*memberIter)->getName() << endl;
                    }
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "1234567890").c_str());
                    for (memberIter = memberList.begin(); memberIter != memberList.end(); memberIter++) {
                        if ((*memberIter)->getID() == selector) {
                            cout << ">> Admin password:" << endl;
                            cin >> _currentpwd;
                            if (loggedMember->checkAcct(loggedMember->getUsername(), _currentpwd)){
                                cout << ">> Please enter your expected password:" << endl;
                                cin >> _password;
                                loggedMember->resetPwd(*memberIter, _password);
                                break;
                            }
                        }
                    }
                    cout << ">> Then you want to:" << endl;
                    cout << "    1. Edit another memeber's password" << endl;
                    cout << "    2. Back to Admin Menu" << endl;
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                    switch (selector) {
                        case 1:
                            goto EditUser;
                        case 2:
                            goto AdminMenu;
                        default:
                            break;
                    }
                }
                else {
                    cout << "Please login as Admin first." << endl;
                    goto Login;
                }
            case 2:
            EditPrj:
                cout << endl;
                cout << "      Edit Project Info     " << endl;
                cout << "----------------------------" << endl;
                if (_logged && (loggedMember->getLevel() >= 2) ) {
                    cout << "Plaease choose a project to edit: " << endl;
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        cout << (*prjIter)->getID() << ". " << (*prjIter)->getName() << endl;
                    }
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "1234567890").c_str());
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        if ((*prjIter)->getID() == selector) {
                            cout << ">> Verify your password:" << endl;
                            cin >> _currentpwd;
                            if (loggedMember->checkAcct(loggedMember->getUsername(), _currentpwd)){
                                cout << ">> Please choose item to edit:" << endl;
                                cout << "    1. Name" << endl;
                                cout << "    2. Deadline" << endl;
                                cin >> _selector;
                                selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                                switch (selector) {
                                    case 1:
                                        cout << ">> Please enter project name:" << endl;
                                        cin >> _prjName;
                                        (*prjIter)->setName(_prjName);
                                    case 2:
                                        cout << ">> Please enter project DeadLine:" << endl;
                                        cin >> _prjDDL;
                                        (*prjIter)->setDDL(_prjDDL);
                                }
                                cout << "Congratulations! You've successfully edit a project." << endl
                                << "Following are what you input: " << endl;
                                (*prjIter)->printPrj();
                                break;
                            }
                        }
                    }
                    cout << ">> Then you want to:" << endl;
                    cout << "    1. Edit another project info" << endl;
                    cout << "    2. Back to Admin Menu" << endl;
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                    switch (selector) {
                        case 1:
                            goto EditPrj;
                        case 2:
                            goto AdminMenu;
                        default:
                            break;
                    }
                }
                else {
                    cout << "Please login as Admin first." << endl;
                    goto Login;
                }
            case 3:
            DeleteUser:
                cout << endl;
                cout << "        Delete a member     " << endl;
                cout << "----------------------------" << endl;
                if (_logged && (loggedMember->getLevel() == 3) ) {
                    cout << "Plaease choose a user to delete: " << endl;
                    for (memberIter = memberList.begin(); memberIter != memberList.end(); memberIter++) {
                        cout << (*memberIter)->getID() << ". " << (*memberIter)->getName() << endl;
                    }
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "1234567890").c_str());
                    for (memberIter = memberList.begin(); memberIter != memberList.end(); memberIter++) {
                        if ((*memberIter)->getID() == selector) {
                            cout << ">> Admin password:" << endl;
                            cin >> _currentpwd;
                            if (loggedMember->checkAcct(loggedMember->getUsername(), _currentpwd)){
                                if (!memberList.empty()){
                                    memberList.remove(*memberIter);
                                }
                                else {
                                    std::cout << "There is no member now." << std::endl;
                                }
                                break;
                            }
                        }
                    }
                    cout << ">> Then you want to:" << endl;
                    cout << "    1. Delete another memeber" << endl;
                    cout << "    2. Back to Admin Menu" << endl;
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                    switch (selector) {
                        case 1:
                            goto DeleteUser;
                        case 2:
                            goto AdminMenu;
                        default:
                            break;
                    }
                }
                else {
                    cout << "Please login as Admin first." << endl;
                    goto Login;
                }
            case 4:
            DeletePrj:
                cout << endl;
                cout << "        Delete a project    " << endl;
                cout << "----------------------------" << endl;
                if (_logged && (loggedMember->getLevel() == 3) ) {
                    cout << "Plaease choose a project to delete: " << endl;
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        cout << (*prjIter)->getID() << ". " << (*prjIter)->getName() << endl;
                    }
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "1234567890").c_str());
                    for (prjIter = prjList.begin(); prjIter != prjList.end(); prjIter++) {
                        if ((*prjIter)->getID() == selector) {
                            cout << ">> Admin password:" << endl;
                            cin >> _currentpwd;
                            if (loggedMember->checkAcct(loggedMember->getUsername(), _currentpwd)){
                                if (!prjList.empty()){
                                    prjList.remove(*prjIter);
                                }
                                else {
                                    std::cout << "There is no project now." << std::endl;
                                }
                                break;
                            }
                        }
                    }
                    cout << ">> Then you want to:" << endl;
                    cout << "    1. Delete another project" << endl;
                    cout << "    2. Back to Admin Menu" << endl;
                    cin >> _selector;
                    selector = atoi(ValidInfo::validSelector(_selector, "12").c_str());
                    switch (selector) {
                        case 1:
                            goto DeletePrj;
                        case 2:
                            goto AdminMenu;
                        default:
                            break;
                    }
                }
            case 5:
                goto MainMenu;
            default:
                break;
        }
    return  0;
}