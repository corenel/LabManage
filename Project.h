#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include "Member.h"

class project{
private:
    int prj_id;
    std::string name;
    std::string ddl;
    std::vector<member> participant;
public:
    project() = default;
    project(const std::string &s): name(s) { };
    project(const std::string &s1, const std::string &s2):
            name(s1), ddl(s2) { };
    ~project();
    int getID() const {return prj_id;};
    std::string getName() const {return name;};
    void setID(const int inputID) {prj_id = inputID;};
    void setName(const std::string inputName) {name = inputName;};
    void add(member const &newP) {participant.push_back(newP);};

};
#endif //PROJECT_H
