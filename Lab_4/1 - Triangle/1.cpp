#include "1.h"
#include <iostream>
#include <limits>

Triangle::Triangle() : a(0), b(0), c(0) {} // конструктор по умолчанию
Triangle::Triangle(double x, double y, double z) : a(x), b(y), c(z) {} // конструктор с параметрами
Triangle::Triangle (const Triangle& other) : a(other.a), b(other.b), c (other.c) {} // копирующий конструктор

// Сеттеры
void Triangle::setA(double x) { a = x; }
void Triangle::setB(double y) { b = y; }
void Triangle::setC(double z) { c = z; }

//Геттеры
double Triangle::getA() const { return a; }
double Triangle::getB() const { return b; }
double Triangle::getC() const { return c; }

// Проверка существования
bool Triangle::exists() const {
    return (a + b > c) && (b + c > a) && (a + c > b) && a > 0 && b > 0 && c > 0;
}

std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    os << "Стороны треугольника: a = " << t.a << ", b = " << t.b << ", c = " << t.c;
    return os;
}


double inputDouble(const std::string& msg, double minVal, double maxVal) {
    double value;
    std::cout << msg;
    while (!(std::cin >> value) || value < minVal || value > maxVal) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка. Введите число в диапазоне [" << minVal << "; " << maxVal << "]: ";
    }
    std::cin.ignore(10000, '\n');
    return value;
}