#include <iostream>
#include <string>
#include <cwchar>
#include <locale>

class FullName {
public:
    std::string surname;
    std::string name;
    std::string patronymic;

    std::string toString() const {
        std::string result;
        if (!surname.empty()) result += surname;
        if (!name.empty()) {
            if (!result.empty()) result += " ";
            result += name;
        }
        if (!patronymic.empty()) {
            if (!result.empty()) result += " ";
            result += patronymic;
        }
        return result;
    }

    void print() const {
        std::cout << toString() << std::endl;
    }
};

// только кириллица и дефис
bool isValidRussian(const std::string& str) {
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

std::string inputValidation(const std::string& prompt, bool allowEmpty = false) {
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
            std::cout << "Неверный ввод — не должно быть пробелов. Попробуйте ещё раз.\n";
        } else if (!isValidRussian(value)) {
            std::cout << "Ошибка: допустимы только русские буквы и дефис. Попробуйте ещё раз.\n";
        } else {
            success = true;
        }
    }
    return value;
}

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    FullName person_1{"", "Клеопатра", ""};
    FullName person_2{"Пушкин", "Александр", "Сергеевич"};
    FullName person_3{"Маяковский", "Владимир", ""};

    std::cout << "Существующие имена:\n";
    person_1.print();
    person_2.print();
    person_3.print();

    std::cout << "\nДобавим нового человека:\n";
    std::cout << "(если хотите пропустить фамилию или отчество, просто нажмите Enter)\n";

    FullName newPerson;
    newPerson.surname = inputValidation("Введите фамилию: ", true);
    newPerson.name = inputValidation("Введите имя: ");
    newPerson.patronymic = inputValidation("Введите отчество: ", true);

    std::cout << "\nВы ввели: ";
    newPerson.print();

    return 0;
}
