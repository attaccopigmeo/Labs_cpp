#include <iostream>


int lastNumSum(int a, int b) {
    int c = a % 10, d = b % 10;
    return c + d;
}


int main() {
    int a = 0, b = 0;
    std::cout << "Введите число a: ";
    std::cin >> a;
    for(int i = 0; i < 4; i++) {
        std::cout << "Введите число b: ";
        std::cin >> b;
        std::cout << "Сумма " << a << " + " << b << " = ";
        a = lastNumSum(a, b);
        std::cout << a << std::endl;
    }
}