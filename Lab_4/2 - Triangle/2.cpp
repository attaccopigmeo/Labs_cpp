#include "2.h"
#include <cmath>
#include <limits>
#include <iostream>

double Triangle::area() const {
    if (!exists()) return 0.0;
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

Triangle::Triangle() : a(0.0), b(0.0), c(0.0) {}
Triangle::Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
Triangle::Triangle(const Triangle& t) : a(t.a), b(t.b), c(t.c) {}

void Triangle::setA(double x) { a = x; }
void Triangle::setB(double x) { b = x; }
void Triangle::setC(double x) { c = x; }

double Triangle::getA() const { return a; }
double Triangle::getB() const { return b; }
double Triangle::getC() const { return c; }

bool Triangle::exists() const {
    return (a > 0 && b > 0 && c > 0 &&
            a + b > c && a + c > b && b + c > a);
}

double Triangle::operator~() const {
    return area();
}

Triangle::operator double() const {
    return a + b + c; // периметр
}

Triangle::operator bool() const {
    return exists();
}

bool Triangle::operator<(const Triangle& other) const {
    return this->area() < other.area();
}

bool Triangle::operator>(const Triangle& other) const {
    return this->area() > other.area();
}

std::ostream& operator<<(std::ostream& os, const Triangle& t) {
    os << "a = " << t.a << ", b = " << t.b << ", c = " << t.c;
    return os;
}

double inputDouble(const std::string& prompt, double minVal, double maxVal) {
    double value;
    std::cout << prompt;
    while (!(std::cin >> value) || value < minVal || value > maxVal) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введите число в диапазоне ["
                  << minVal << "; " << maxVal << "]:\n"
                  << prompt;
    }
    std::cin.ignore(10000, '\n');
    return value;
}