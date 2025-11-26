#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <cwchar>

class Name {
private:
    std::string lastName;
    std::string firstName;
    std::string middleName;

    static bool isValidRussian(const std::string& str) {
        std::setlocale(LC_ALL, "ru_RU.UTF-8");

        std::wstring wstr;
        mbstate_t state{};
        const char* src = str.c_str();
        size_t len = mbsrtowcs(nullptr, &src, 0, &state);
        if (len == static_cast<size_t>(-1)) return false;
        wstr.resize(len);
        src = str.c_str();
        mbsrtowcs(&wstr[0], &src, len, &state);

        for (wchar_t wc : wstr) {
            if (wc == L'-') continue;
            if (!((wc >= L'А' && wc <= L'я') || wc == L'Ё' || wc == L'ё')) {
                return false;
            }
        }
        return true;
    }

    static std::string inputValidation(const std::string& prompt, bool allowEmpty = false) {
        std::string value;
        bool success = false;

        while (!success) {
            std::cout << prompt;
            std::getline(std::cin, value);

            if (allowEmpty && value.empty()) {
                success = true;
            } else if (value.empty()) {
                std::cout << "Поле не может быть пустым. Попробуйте ещё раз.\n";
            } else if (value.find(' ') != std::string::npos) {
                std::cout << "Ошибка: не должно быть пробелов. Попробуйте ещё раз.\n";
            } else if (!isValidRussian(value)) {
                std::cout << "Ошибка: допустимы только русские буквы и дефис.\n";
            } else {
                success = true;
            }
        }
        return value;
    }

public:
    Name(std::string last = "", std::string first = "", std::string middle = "")
        : lastName(std::move(last)), firstName(std::move(first)), middleName(std::move(middle)) {}

    std::string toString() const {
        std::ostringstream oss;
        bool added = false;

        if (!lastName.empty()) {
            oss << lastName;
            added = true;
        }

        if (!firstName.empty()) {
            if (added) oss << ' ';
            oss << firstName;
            added = true;
        }

        if (!middleName.empty()) {
            if (added) oss << ' ';
            oss << middleName;
        }

        return oss.str();
    }

    static Name createFromInput() {
        std::string last = inputValidation("Введите фамилию (можно пропустить): ", true);
        std::string first = inputValidation("Введите имя: ");
        std::string middle = inputValidation("Введите отчество (можно пропустить): ", true);
        return Name(last, first, middle);
    }
};