/*Дана сигнатура функции: String reverseListNums (int x);
Необходимо реализовать функцию таким образом, чтобы она возвращала
строку, в которой будут записаны все числа от x до 0 (включительно).
Пример:
x=5
результат: “5 4 3 2 1 0”*/
#include <iostream>
#include <string>

std::string reverseListNums(int x) {
    std::string numbers = " ";
    for (int i = x; i >= 0; i --) {
        numbers += std::to_string(i);
        if (i > 0) numbers += " ";
    }
    return numbers;
}

int main() {
    int x;
    bool success = false;
    while (!success) {
        std::cout << "Введите число: ";
        std::cin >> x;
        if (std::cin.fail() || std::cin.peek() != '\n' || x < 0) {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::cout << reverseListNums(x) << std::endl;
}