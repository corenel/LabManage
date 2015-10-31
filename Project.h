#ifndef LABMANAGE_PROJECT_H
#define LABMANAGE_PROJECT_H

#include <string>
#include <vector>

class project{
private:
    int id;
    std::string name;
    std::string ddl;
    vector<member> participant;
public:
    project() = default;
    project(const std::string &s): name(s) { };
    project(const std::string &s1, const std::string &s2):
            name(s1), ddl(s2) { };
    ~project();
    int getID() {return id;};
    std::string getName() {return name;};
    void setID(const int inputID) {id = inputID;};
    void setName(const std::string inputName) {name = inputName;};
    void addP(menmber const &newP) {participant.push_back(newP);};

};
#endif //LABMANAGE_PROJECT_H
