#include "fullname.h"
#include <iostream>
#include <sstream>
#include <locale>
#include <cwchar>

bool FullName::isValidRussian(const std::string& str) {
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

std::string FullName::inputValidation(const std::string& prompt, bool allowEmpty) {
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

FullName::FullName(std::string last, std::string first, std::string middle)
    : surname(std::move(last)), name(std::move(first)), patronymic(std::move(middle)) {}

std::string FullName::toString() const {
    std::ostringstream oss;
    bool added = false;

    if (!surname.empty()) {
        oss << surname;
        added = true;
    }

    if (!name.empty()) {
        if (added) oss << ' ';
        oss << name;
        added = true;
    }

    if (!patronymic.empty()) {
        if (added) oss << ' ';
        oss << patronymic;
    }

    return oss.str();
}

FullName FullName::createFromInput() {
    std::string last = inputValidation("Введите фамилию (можно пропустить): ", true);
    std::string first = inputValidation("Введите имя: ", false);
    std::string middle = inputValidation("Введите отчество (можно пропустить): ", true);
    return FullName(last, first, middle);
}