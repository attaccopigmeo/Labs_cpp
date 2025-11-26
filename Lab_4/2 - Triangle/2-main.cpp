#include <iostream>
#include <cmath>
#include <limits>
#include <string>

class Triangle {
private:
    double a, b, c;
    double area() const {
        if (!exists()) return 0.0;
        double p = (a + b + c) / 2.0;
        return std::sqrt(p * (p - a) * (p - b) * (p - c)); // формула Герона
    }

public:
    Triangle() : a(0.0), b(0.0), c(0.0) {}
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
    Triangle(const Triangle& t) : a(t.a), b(t.b), c(t.c) {}

    void setA(double x) { a = x; }
    void setB(double x) { b = x; }
    void setC(double x) { c = x; }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    bool exists() const {
        return (a > 0.0 && b > 0.0 && c > 0.0 &&
                a + b > c && a + c > b && b + c > a);
    }

    // Унарная операция: площадь (используется оператор ~)
    double operator~() const {
        return area();
    }

    // Приведение типов
    operator double() const { // неявное: периметр
        return a + b + c;
    }

    explicit operator bool() const { // явное: существует ли треугольник
        return exists();
    }

    // Операторы сравнения по площади
    bool operator<(const Triangle& other) const {
        return this->area() < other.area();
    }

    bool operator>(const Triangle& other) const {
        return this->area() > other.area();
    }

    friend std::ostream& operator<<(std::ostream& os, const Triangle& t) {
        os << "a = " << t.a << ", b = " << t.b << ", c = " << t.c;
        return os;
    }
};

double inputDouble(const std::string& prompt, double minVal = 0.000001, double maxVal = 1e9) {
    double value;
    std::cout << prompt;
    while (!(std::cin >> value) || value < minVal || value > maxVal) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: введите число в диапазоне [" << minVal << "; " << maxVal << "].\n" << prompt;
    }
    std::cin.ignore(10000, '\n');
    return value;
}

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
    if (t1 > t2) {
        std::cout << "t1 имеет большую площадь, чем t2.\n";
    } else if (t1 < t2) {
        std::cout << "t2 имеет большую площадь, чем t1.\n";
    } else {
        std::cout << "Площади равны.\n";
    }

    Triangle t3;
    t3.setA(3); t3.setB(4); t3.setC(5);
    std::cout << "\nt3: " << t3 << " Площадь: " << ~t3 << " Периметр: " << static_cast<double>(t3) << "\n";
    std::cout << "t3 существует? " << (static_cast<bool>(t3) ? "Да" : "Нет") << "\n";

    return 0;
}