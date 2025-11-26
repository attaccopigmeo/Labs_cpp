#ifndef FULLNAME_H
#define FULLNAME_H

#include <string>

class FullName {
private:
    std::string surname;
    std::string name;
    std::string patronymic;
    static bool isValidRussian(const std::string& str);
    static std::string inputValidation(const std::string& prompt, bool allowEmpty);

public:
    FullName(std::string last = "", std::string first = "", std::string middle = "");
    std::string toString() const;
    static FullName createFromInput();
};

#endif