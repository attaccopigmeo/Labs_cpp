/*Дана сигнатура функции: double safeDiv (int x, int y);
Необходимо реализовать функцию таким образом, чтобы она возвращала
деление x на y, и при этом гарантировала, что не будет выкинута ошибка
деления на 0. При делении на 0 следует вернуть из функции число 0. Подсказка:
смотри ограничения на операции типов данных.
Пример 1:
x=5 y=0
результат: 0
Пример 2:
x=8 y=2
результат: 4*/
#include <iostream>

double safeDiv(int a, int b) {
    if (b == 0) {
        return 0.0;
    }
    return static_cast<double>(a) / b;
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
        std::cout << "Введите число: ";
        std::cin >> y;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    auto result = safeDiv(x, y);
    std::cout << "Результат: "<< result << std::endl;
}