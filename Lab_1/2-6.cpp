/*Дана сигнатура функции: bool sum3 (int x, int y, int z);
Необходимо реализовать функцию таким образом, чтобы она возвращала true,
если два любых числа (из трех принятых) можно сложить так, чтобы получить
третье.*/
#include <iostream>

bool sum3(int x, int y, int z) {
    if (x + y == z || x + z == y || y + z == x) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int a, b, c;
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
    success = false;
    while (!success) {
        std::cout << "Введите число: ";
        std::cin >> c;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::cout << sum3(a, b, c) << std::endl;
}