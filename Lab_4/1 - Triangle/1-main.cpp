#include <iostream>
#include "1.h"

int main() {
    setlocale(LC_ALL, "ru");
    double a = inputDouble("Введите сторону a: ", 0.0001);
    double b = inputDouble("Введите сторону b: ", 0.0001);
    double c = inputDouble("Введите сторону c: ", 0.0001);
    Triangle t1(a, b, c);
    if (t1.exists()) {
        std::cout << "Треугольник существует.\n";
    } else {
        std::cout << "Треугольник не существует.\n";
    }
    Triangle t2;
    std::cout << "t2 (по умолчанию): " << t2 << "\n";
    t2.setA(3);
    t2.setB(4);
    t2.setC(5);
    std::cout << "t2 после установки значений: " << t2 << "\n";
    if (t2.exists()) {
        std::cout << "Треугольник существует.\n";
    } else {
        std::cout << "Треугольник не существует.\n";
    }
    Triangle t3(t1);
    std::cout << "t3 (копия t1): " << t3 << "\n";

    return 0;
}