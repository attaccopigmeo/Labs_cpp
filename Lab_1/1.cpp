#include <iostream>


int lastNumSum(int a, int b) {
    int c = a % 10, d = b % 10;
    return c + d;
}


int main() {
    int a = 0, b = 0;
    bool success = false;
    while (!success) {
        std::cout << "Введите число a: ";
        std::cin >> a;
        if (!std::cin) {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::string line;
            std::getline(std::cin, line);
        } else {
            success = true;
        }
    }
    for(int i = 0; i < 4; i++) {
        success = false;
        while (!success) {
            std::cout << "Введите число b: ";
            std::cin >> b;
            if (!std::cin) {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::string line;
                std::getline(std::cin, line);
            } else {
                success = true;
            }
        }
        std::cout << "Сумма " << a << " + " << b << " = ";
        a = lastNumSum(a, b);
        std::cout << a << std::endl;
    }
}