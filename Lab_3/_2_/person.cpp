#include "person.h"
#include <iostream>
#include <string>

Person::Person(FullName n, int h) : fullname(std::move(n)), height(h) {}

void Person::print() const {
    std::cout << fullname.toString() << ", рост " << height << " см" << std::endl;
}

Person Person::createFromInput() {
    FullName n = FullName::createFromInput();
    int h = 0;

    while (true) {
        std::cout << "Введите рост (в сантиметрах): ";
        std::string line;
        std::getline(std::cin, line);
        try {
            h = std::stoi(line);
            if (h > 0 && h < 300) break;
            else std::cout << "Некорректный рост.\n";
        } catch (...) {
            std::cout << "Ошибка ввода числа.\n";
        }
    }

    return Person(n, h);
}