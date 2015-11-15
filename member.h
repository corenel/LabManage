#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class member {
    friend admin;
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

    // Set user info
    void setName(const std::string inputName) {name = inputName;};
    void setPhone(const std::string inputPhone) {phone = inputPhone;};
    void setEmail(const std::string inputEmail) {email = inputEmail;};
    void chgPwd(const std::string currentPwd, const std::string inputPwd);
    bool checkAcct(const std::string currentPwd);
};

class admin : public member {
public:
    admin() = default;
    admin(const std::string &s1, const std::string &s2):
            username(s1), password(s2), level(3) { };
    ~admin();
    void setPwd(const std::string currentPwd, const std::string inputPwd, const member &user);
};

class teacher : public member {
public:
    teacher() = default;
    teacher(const std::string &s1, const std::string &s2):
            username(s1), password(s2), level(2) { };
    ~teacher();
};

class student : public member {
public:
    student() = default;
    student(const std::string &s1, const std::string &s2):
            username(s1), password(s2), level(2) { };
    ~student();
};

#endif //MEMBER_H
