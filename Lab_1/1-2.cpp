/*Дана сигнатура функции: int sumLastNums (int x);
Необходимо реализовать функцию таким образом, чтобы она возвращала
результат сложения двух последних знаков числах, предполагая, что знаков в
числе не менее двух. Подсказки:
int x=123%10; // х будет иметь значение 3
int у=123/10; // у будет иметь значение 12*/
#include <iostream>
#include <string>

std::string result(std::string prompt) {
    int a;
    while (true) {
        std::cout << prompt;
        std::cin >> a;

        auto sumLastNums = [] (int a)
        { int b, c;
        b = a % 10; 
        c = (a / 10) % 10; 
        return b + c;};

        if (std::cin.fail() || std::cin.peek() != '\n' || a / 10 < 1) {
            std::cout << "Неверный ввод." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            return "Результат: " + std::to_string(sumLastNums(a));
        }
    }
}

int main() {
    std::string prompt = "Введите число (не менее, чем два знака): ";
    std::cout << result(prompt) << std::endl;
}