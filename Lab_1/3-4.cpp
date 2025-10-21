/*Дана сигнатура функции: int pow (int x, int y);
Необходимо реализовать функцию таким образом, чтобы она возвращала результат
возведения x в степень y.
Подсказка: для получения степени необходимо умножить единицу на число x, и сделать
это y раз, т.е. два в третьей степени это 1*2*2*2
Пример:
x=2
y=5
результат: 32*/
#include <iostream>

double pow(double x, int y) {
    double result = 1;
    if (y >= 0)
        for (int i = 0; i < y; i++) result *= x;
    else
        for (int i = 0; i < -y; i++) result /= x;
    return result;
}

int main() {
    int x, y;
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
    success = false;
    while (!success) {
        std::cout << "Введите степень: ";
        std::cin >> y;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::cout << "Результат: " << pow(x, y) << std::endl;
}