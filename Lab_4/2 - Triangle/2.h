#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <string>

class Triangle {
private:
    double a, b, c;

    // приватный метод вычисления площади
    double area() const;

public:
    // Конструкторы
    Triangle();
    Triangle(double x, double y, double z);
    Triangle(const Triangle& t);

    // Сеттеры
    void setA(double x);
    void setB(double x);
    void setC(double x);

    // Геттеры
    double getA() const;
    double getB() const;
    double getC() const;

    // Проверка существования треугольника
    bool exists() const;

    // Унарный оператор: площадь (~t)
    double operator~() const;

    // Приведение типов
    operator double() const;     // неявное: периметр
    explicit operator bool() const; // явное: существует ли

    // Сравнение по площади
    bool operator<(const Triangle& other) const;
    bool operator>(const Triangle& other) const;

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Triangle& t);
};

// безопасный ввод числа
double inputDouble(const std::string& prompt, double minVal = 0.000001, double maxVal = 1e9);

#endif