/*Дана сигнатура функции: String makeDecision (int x, int y);
Необходимо реализовать функцию таким образом, чтобы она возвращала
строку, которая включает два принятых функцией числа и корректно
выставленный знак операции сравнения (больше, меньше, или равно).*/
#include <iostream>
#include <string>

std::string makeDecision(int x, int y) {
    if (x == y) {
        return std::to_string(x) + " = " + std::to_string(y);
    } else if (x < y) {
        return std::to_string(x) + " < " + std::to_string(y);
    } else {
        return std::to_string(x) + " > " + std::to_string(y);
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
    std::cout << makeDecision(a, b) << std::endl;
}