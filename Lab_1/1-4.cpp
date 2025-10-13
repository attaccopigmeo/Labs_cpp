/*Дана сигнатура функции: bool isPositive (intx);
Необходимо реализовать функцию таким образом, чтобы она принимала число
x и возвращала true, если оно положительное.
Пример 1:
x=3
результат: true
Пример 2:
x=-5
результат: false*/
#include <iostream>

bool isPositive(int x) {
    if (x > 0) { //число 0 считается нейтральным, поэтому его не вписываем в положительные
        return true;
    } else {
        return false;
    }
}

int main() {
    int x;
    bool success = false;
    while (!success) {
        std::cout << "Введите число: ";
        std::cin >> x;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::cout << "Число " << x << " является положительным: " << isPositive(x) << std::endl;
}