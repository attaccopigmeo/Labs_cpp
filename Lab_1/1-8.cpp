/*Дана сигнатура функции: bool isDivisor (int a, int b);
Необходимо реализовать функцию таким образом, чтобы она возвращала true,
если любое из принятых чисел делит другое нацело.
Пример 1:
a=3 b=6
результат: true
Пример 2:
a=2 b=15
результат: false*/
#include <iostream>

bool isDivisor(int a, int b) {
    if (a % b == 0 || b % a == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int a, b;
    bool success = false;
    while (!success) {
        std::cout << "Введите число: ";
        std::cin >> a;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    success = false;
    while (!success) {
        std::cout << "Введите число: ";
        std::cin >> b;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::cout << "Одно из чисел делится на другое нацело: " << isDivisor(a, b) << std::endl;
}