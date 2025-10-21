/*Дана сигнатура функции: bool equalNum (int x);
Необходимо реализовать функцию таким образом, чтобы она возвращала true, если все
знаки числа одинаковы, и false в ином случае.
Подсказки:
intx=123%10; // х будет иметь значение 3
intу=123/10; // у будет иметь значение 12
Пример 1:
x=1111
результат: true
Пример 2:
x=1211
результат: false*/
#include <iostream>

bool equalNum(int x) {
    x = std::abs(x); // чтобы работало и с отрицательными числами, берем x по модулю
    int lastDigit = x % 10;
    while (x > 0) {
        if (x % 10 != lastDigit)
            return false;
        x /= 10;
    }
    return true;
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
    std::cout << "Результат: " << equalNum(x) << std::endl;
}