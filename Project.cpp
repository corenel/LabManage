#include "Project.h"

void project::addMember(member *newMember) {
    bool _include = false;
    if (!participant.empty()){
        for (std::list<member*>::iterator mem = participant.begin(); mem != participant.end(); mem++) {
            if ((*mem)->getID() ==  newMember->getID()) {
                _include =true;
                break;
            }
        }
        if (!(_include)) {
            participant.push_front(newMember);
        }
    }
    else {
        participant.push_front(newMember);
    }
}

void project::removeMember(member *deleteMember) {
    if (!participant.empty()){
        participant.remove(deleteMember);
    }
    else {
        std::cout << "This project has no participant." << std::endl;
    }
}

void project::printPrj() {
    std::cout << "----------------------------" << std::endl;
    std::cout << "ID: " << getID() << std::endl;
    std::cout << "Project Name: " << getName() << std::endl;
    std::cout << "Dead Line: " << getDDL() << std::endl;
    std::cout << "Participants; " << std::endl;
    for (std::list<member*>::iterator mem = participant.begin(); mem != participant.end(); mem++) {
        std::cout << (*mem)->getName() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}
