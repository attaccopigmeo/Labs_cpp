/*Дана сигнатура функции: bool isUpperCase (char x);
Необходимо реализовать функцию таким образом, чтобы она принимала
символ x и возвращала true, если это большая буква в диапазоне от ‘A’ до ‘Z’.
Пример 1:
x=’D’
результат: true
Пример 2:
x=’q’
результат: false*/
#include <iostream>
#include <cwctype>
#include <locale>

bool isUpper(wchar_t x) {
    if (std::isupper(x, std::locale())) return true;
    if (std::islower(x, std::locale())) return false;
    return false;
}

int main() {
    std::locale::global(std::locale("ru_RU.UTF-8"));
    wchar_t letter;
    bool success = false;
    while (!success) {
        std::cout << "Введите букву: ";
        std::wcin >> letter;
        if (std::wcin.fail() || !std::isalpha(letter, std::locale())) {
            std::cout << "Неверный ввод." << std::endl;
            std::wcin.clear();
            std::wcin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    if (isUpper(letter)) {
        std::cout << "Буква является заглавной." << std::endl;
    } else {
        std::cout << "Буква является строчной." << std::endl;
    }
}