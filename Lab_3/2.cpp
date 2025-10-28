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
        // только кириллица
        if (!((wc >= L'А' && wc <= L'я') || wc == L'Ё' || wc == L'ё'))
            return false;
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

class Person {
public:
    FullName fullName;
    int height;

    void print() const {
        std::cout << "Человек с именем " << fullName.toString()
                  << " и ростом " << height << std::endl;
    }
};

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    FullName n1{"", "Клеопатра", ""};
    FullName n2{"Пушкин", "Александр", "Сергеевич"};
    FullName n3{"Маяковский", "Владимир", ""};

    Person p1{n1, 152};
    Person p2{n2, 167};
    Person p3{n3, 189};

    std::cout << "Существующие люди:\n";
    p1.print();
    p2.print();
    p3.print();

    std::cout << "\nДобавим нового человека:\n";
    std::cout << "(если хотите пропустить фамилию или отчество, просто нажмите Enter)\n";

    FullName newName;
    newName.surname = inputValidation("Введите фамилию: ", true);
    newName.name = inputValidation("Введите имя: ");
    newName.patronymic = inputValidation("Введите отчество: ", true);

    int newHeight;
    std::cout << "Введите рост (в см): ";
    while (!(std::cin >> newHeight) || newHeight < 73 || newHeight > 280) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введите положительное число.\nВведите рост (в см): ";
    }
    std::cin.ignore(10000, '\n');

    Person newPerson{newName, newHeight};

    std::cout << "\nВы ввели:\n";
    newPerson.print();

    return 0;
}
