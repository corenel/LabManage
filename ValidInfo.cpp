#include "ValidInfo.h"

std::string ValidInfo::validEmail(const std::string &_email) {
    int atCount=0;
    auto atIndex = _email.find_first_of('@', 0);
    if (atIndex != std::string::npos && _email.find_first_of('.', atIndex) != std::string::npos)
    {
        for (int i = 0; i < _email.size();i++)
            if (_email[i] == '@')
                atCount++;
        if (atCount == 1)
            return _email;
        else{
            std::cout << "Error: Invalid e-mail address, you couldn't muse more than 1 '@' character. Please try again." << std::endl;
            std::string __email;
            std::cin >> __email;
            return validEmail(__email);
        }
    }
    else{
        std::cout << "Error: Invalid e-mail address. Please try again." << std::endl;
        std::string __email;
        std::cin >> __email;
        return validEmail(__email);
    }
}

std::string ValidInfo::validSelector(const std::string &_selector, const std::string &AllowedChars) {
    for (auto SelectorChar = _selector.begin(); SelectorChar != _selector.end(); SelectorChar++) {
        if (AllowedChars.find(*SelectorChar) == std::string::npos) {
            std::cout << "Error: Invalid input selector number. Please try again." << std::endl;
            std::cout << ">> Please choose one operation: ";
            std::string __selector;
            std::cin >> __selector;
            return validSelector(__selector, AllowedChars);
        }
    }
    return _selector;
}
