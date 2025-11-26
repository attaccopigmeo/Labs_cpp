#include <iostream>
#include "2.h"

int main() {
    setlocale(LC_ALL, "ru");

    double a1 = inputDouble("Введите сторону a: ");
    double b1 = inputDouble("Введите сторону b: ");
    double c1 = inputDouble("Введите сторону c: ");
    Triangle t1(a1, b1, c1);

    std::cout << "\nТреугольник t1: " << t1 << "\n";
    std::cout << "Существует: " << (static_cast<bool>(t1) ? "Да" : "Нет") << "\n";
    std::cout << "Периметр: " << static_cast<double>(t1) << "\n";
    std::cout << "Площадь: " << ~t1 << "\n\n";

    double a2 = inputDouble("Введите сторону a: ");
    double b2 = inputDouble("Введите сторону b: ");
    double c2 = inputDouble("Введите сторону c: ");
    Triangle t2(a2, b2, c2);

    std::cout << "\nТреугольник t2: " << t2 << "\n";
    std::cout << "Существует: " << (static_cast<bool>(t2) ? "Да" : "Нет") << "\n";
    std::cout << "Периметр: " << static_cast<double>(t2) << "\n";
    std::cout << "Площадь: " << ~t2 << "\n\n";

    if (t1 > t2)
        std::cout << "t1 имеет большую площадь, чем t2.\n";
    else if (t1 < t2)
        std::cout << "t2 имеет большую площадь, чем t1.\n";
    else
        std::cout << "Площади равны.\n";
    Triangle t3;
    t3.setA(3);
    t3.setB(4);
    t3.setC(5);

    std::cout << "\nt3: " << t3 << " Площадь: " << ~t3 << " Периметр: " << static_cast<double>(t3) << "\n";

    std::cout << "t3 существует? " << (static_cast<bool>(t3) ? "Да" : "Нет") << "\n";

    return 0;
}