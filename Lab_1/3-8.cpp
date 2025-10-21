/*Дана сигнатура функции: void leftTriangle (int x);
Необходимо реализовать функцию таким образом, чтобы она выводила на экран
треугольник из символов ‘*’ у которого х символов в высоту, а количество символов в
ряду совпадает с номером строки.
Пример 1:
x=2
результат:
*
**
Пример 2:
x=4
результат:
*
**
***
****/
#include <iostream>

void leftTriangle(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

int main() {
    int x;
    bool success = false;
    while (!success) {
        std::cout << "Введите число: ";
        std::cin >> x;
        if (std::cin.fail() || std::cin.peek() != '\n' || x <= 0) {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    leftTriangle(x);
}