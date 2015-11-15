#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

class member {
    friend class admin;
protected:
    std::string username, password;     // Account info
    int level;                          // User level
    std::string name, phone, email;     // Detailed info
public:
    member() = default;
    member(const std::string &s1, const std::string &s2, const int lv):
            username(s1), password(s2), level(lv) { };
    ~member();

    // Get user info
    std::string getUsername() const {return username;};
    int getLevel() const {return level;};
    std::string getName() const {return name;};
    std::string getPhone() const {return phone;};
    std::string getEmail() const {return email;};
    void printInfo() const { std::cout << username << " ******** "
                                       << name << " " << phone << " " << email << std::endl;}

    // Set user info
    void setName(const std::string inputName) {name = inputName;};
    void setPhone(const std::string inputPhone) {phone = inputPhone;};
    void setEmail(const std::string inputEmail) {email = inputEmail;};
    void setUsername(const std::string inputUsername) {username = inputUsername;};
    void chgPwd(const std::string currentPwd, const std::string inputPwd);
    bool checkAcct(const std::string currentPwd);
};

class admin : public member {
public:
    admin() = default;
    admin(const std::string &s1, const std::string &s2):
            member(s1, s2, 3) { };
    ~admin();
    void setPwd(const std::string currentPwd, const std::string &inputPwd, member &user);
};

class teacher : public member {
public:
    teacher() = default;
    teacher(const std::string &s1, const std::string &s2):
            member(s1, s2, 2) { };
    ~teacher();
};

class student : public member {
public:
    student() = default;
    student(const std::string &s1, const std::string &s2):
            member(s1, s2, 1) { };
    ~student();
};

#endif //MEMBER_H
