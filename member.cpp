#include "Member.h"
#include <iostream>

bool member::checkAcct(const std::string currentUsername, const std::string currentPwd) {
    if ((currentPwd == password) && (currentUsername == username)) {
        return true;
    }
    else {
        return false;
    }
}

void member::chgPwd(const std::string currentPwd, const std::string inputPwd){
    if (checkAcct(username, currentPwd)) {
        password = inputPwd;
        std::cout << "Current password has been changed successfully." << std::endl;
    }
    else {
        std::cout << "Invalid username or password." << std::endl;
    }
}

void member::resetPwd(member *user, const std::string &inputPwd) {
    if (level == 3) {
        user->password = inputPwd;
        std::cout << "Current password has been changed." << std::endl;
    }
    else {
        std::cout << "Error: No Admin permission." << std::endl;
    }
}

void member::addPrj(project *newPrj) {
    bool _include = false;
    if (!prj.empty()){
        for (std::list<project*>::iterator p = prj.begin(); p != prj.end(); p++) {
            if ((*p)->getID() ==  newPrj->getID()) {
                _include =true;
                break;
            }
        }
        if (!(_include)) {
            prj.push_front(newPrj);
        }
    }
    else {
        prj.push_front(newPrj);
    }
}

void member::removePrj(project *deletePrj) {
    if (!prj.empty()){
        prj.remove(deletePrj);
    }
    else {
        std::cout << "You haven't participated in any projrct." << std::endl;
    }
}

void member::printMyPrj() {
    std::cout << "----------------------------" << std::endl;
    for (std::list<project*>::iterator prjIter = prj.begin(); prjIter != prj.end(); prjIter++) {
        std::cout << (*prjIter)->getID() << ". " << (*prjIter)->getName() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}
