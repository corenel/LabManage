#ifndef VALIDINFO_H
#define VALIDINFO_H

#include <iostream>
#include <string>

class ValidInfo {
public:
    static std::string validEmail (const std::string &_email);
    static std::string validSelector(const std::string &_selector, const std::string &AllowedChars);

};


#endif //VALID_H
