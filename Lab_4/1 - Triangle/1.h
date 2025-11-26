#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <string>

class Triangle {
private:
    double a, b, c;

public:
    Triangle(); // конструктор по умолчанию
    Triangle(double x, double y, double z); // конструктор с параметрами
    Triangle (const Triangle& other); // копирующий конструктор

    // Сеттеры
    void setA(double x);
    void setB(double y);
    void setC(double z);

    //Геттеры
    double getA() const;
    double getB() const;
    double getC() const;

    // Проверка существования
    bool exists() const;

    friend std::ostream& operator<<(std::ostream& os, const Triangle& t);
};

double inputDouble(const std::string& msg, double minVal = 0.0, double maxVal = 1e9);

#endif