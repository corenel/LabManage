#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <list>
#include "Project.h"

class project;

class member {
protected:
    std::string username, password;     // Account info
    int memberID, level;                // User level
    std::string name, phone, email;     // Detailed info
    std::list<project *> prj;
public:
    // Constructor
    member() : memberID(memberIDCnt++) {};
    member(const std::string &s1, const std::string &s2, const int lv):
            username(s1), password(s2), level(lv), memberID(memberIDCnt++){ };
    member(const std::string &s1, const std::string &s2, const std::string &s3,
           const std::string &s4, const std::string &s5, const int lv) :
           username(s1), password(s2), name(s3), phone(s4), email(s5), level(lv), memberID(memberIDCnt++){ };
    // Destructor
    ~member();

    static int memberIDCnt;

    // Get user info
    std::string getUsername() const {return username;};
    int getID() const {return memberID;};
    int getLevel() const {return level;};
    std::string getName() const {return name;};
    std::string getPhone() const {return phone;};
    std::string getEmail() const {return email;};
    void printInfo() const { std::cout << getID() << " " << username << " ******** "
                                       << name << " " << phone << " " << email << std::endl;}
    void printMyPrj();
    virtual void showPermission() = 0;

    // Set user info
    void setName(const std::string inputName) {name = inputName;};
    void setPhone(const std::string inputPhone) {phone = inputPhone;};
    void setEmail(const std::string inputEmail) {email = inputEmail;};
    void setUsername(const std::string inputUsername) {username = inputUsername;};
    void addPrj(project* newPrj);
    void removePrj(project* deletePrj);
    void chgPwd(const std::string currentPwd, const std::string inputPwd);
    void resetPwd(member *user, const std::string &inputPwd);
    bool checkAcct(const std::string currentUsername, const std::string currentPwd);
};

class admin : public member {
public:
    admin() = default;
    admin(const std::string &s1, const std::string &s2):
            member(s1, s2, 3) { };
    admin(const std::string &s1, const std::string &s2, const std::string &s3,
            const std::string &s4, const std::string &s5) :
            member(s1, s2, s3, s4, s5, 3){ };
    ~admin();

    virtual void showPermission() { std::cout << "Your have FULL admin permission." << std::endl;};
};

class teacher : public member {
public:
    teacher() = default;
    teacher(const std::string &s1, const std::string &s2):
            member(s1, s2, 2) { };
    teacher(const std::string &s1, const std::string &s2, const std::string &s3,
           const std::string &s4, const std::string &s5) :
            member(s1, s2, s3, s4, s5, 2){ };
    ~teacher();

    virtual void showPermission() { std::cout << "Your have LIMITED admin permission." << std::endl;};
};

class student : public member {
public:
    student() = default;
    student(const std::string &s1, const std::string &s2):
            member(s1, s2, 1) { };
    student(const std::string &s1, const std::string &s2, const std::string &s3,
            const std::string &s4, const std::string &s5) :
            member(s1, s2, s3, s4, s5, 1){ };
    ~student();

    virtual void showPermission() { std::cout << "Your have NO admin permission." << std::endl;};
};

#endif //MEMBER_H
