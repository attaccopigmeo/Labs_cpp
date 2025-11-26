#include <iostream>
#include <limits>

class Triangle {
private:
    double a, b, c;

public:
    Triangle() : a(0), b(0), c(0) {} // конструктор по умолчанию
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {} // конструктор с параметрами
    Triangle (const Triangle& other) : a(other.a), b(other.b), c (other.c) {} // копирующий конструктор

    // Сеттеры
    void setA(double x) { a = x; }
    void setB(double y) { b = y; }
    void setC(double z) { c = z; }

    //Геттеры
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    // Проверка существования
    bool exists() const {
        return (a + b > c) && (b + c > a) && (a + c > b) && a > 0 && b > 0 && c > 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Triangle& t) {
        os << "Стороны треугольника: a = " << t.a << ", b = " << t.b << ", c = " << t.c;
        return os;
    }
};

double inputDouble(const std::string& msg, double minVal = 0.0, double maxVal = 1e9) {
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