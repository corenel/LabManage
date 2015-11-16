#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <list>
#include "Member.h"

class member;

class project{
private:
    std::string name;
    std::string deadLine;
    int prjId;
    std::list<member *> participant;
public:
    project() : prjId(prjIDCnt++) {};
    project(const std::string &s): name(s), prjId(prjIDCnt++) { };
    project(const std::string &s1, const std::string &s2):
            name(s1), deadLine(s2), prjId(prjIDCnt++)  { };
    ~project();

    static int prjIDCnt;

    int getID() const {return prjId;};
    std::string getName() const {return name;};
    std::string getDDL() const {return deadLine;};
    void printPrj();

    void setName(const std::string inputName) {name = inputName;};
    void setDDL(const std::string inputDDL) {deadLine = inputDDL;};

    void addMember(member *newMember);
    void removeMember(member *deleteMember);

};
#endif //PROJECT_H
