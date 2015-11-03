#include "Member.h"
#include <iostream>

bool member::checkAcct(const std::string currentPwd) {
    if (currentPwd == password) {
        return true;
    }
    else {
        return false;
    }
}

void member::chgPwd(const std::string currentPwd, const std::string inputPwd){
    if (checkAcct(currentPwd)) {
        password = inputPwd;
        std::cout << "Current password has been changed." << std::endl;
    }
    else {
        std::cout << "Invalid username or password." << std::endl;
    }
}
