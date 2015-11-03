#ifndef LABMANAGE_MEMBER_H
#define LABMANAGE_MEMBER_H

#include <string>

class member {
private:
    std::string username, password;     // Account info
    int level;                          // User level
    std::string name, phone, email;     // Detailed info
public:
    member() = default;
    member(const std::string &s1, const std::string &s2, const int lv):
            username(s1), password(s2), level(lv) { };
    ~member();

    // Get user info
    std::string getUsername() {return username;};
    int getLevel() {return level;};
    std::string getName() {return name;};
    std::string getPhone() {return phone;};
    std::string getEmail() {return email;};

    // Set user info
    void setName(const std::string inputName) {name = inputName;};
    void setPhone(const std::string inputPhone) {phone = inputPhone;};
    void setEmail(const std::string inputEmail) {email = inputEmail;};
    void chgPwd(const std::string currentPwd, const std::string inputPwd);
    bool checkAcct(const std::string currentPwd);
};

#endif //LABMANAGE_MEMBER_H
