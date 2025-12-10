#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "Name.h"
#include <ctime>
#include <string>

/// <summary>
/// Человек, наследует Имя, содержит дату рождения.
/// Может вычислять возраст и знак зодиака.
/// </summary>
class Person : public Name
{
private:
    int day, month, year;

public:
    Person(const std::string& last,
           const std::string& first,
           const std::string& patr,
           int d, int m, int y)
        : Name(last, first, patr), day(d), month(m), year(y) {}

    /// <summary>Вычисляет возраст.</summary>
    int GetAge() const
    {
        time_t t = time(nullptr);
        tm* now = localtime(&t);

        int age = now->tm_year + 1900 - year;
        if (now->tm_mon + 1 < month ||
            (now->tm_mon + 1 == month && now->tm_mday < day))
            age--;

        return age;
    }

    /// <summary>Возвращает знак зодиака.</summary>
    std::string GetZodiac() const
    {
        if ((day>=21 && month==3) || (day<=20 && month==4)) return "Овен";
        if ((day>=21 && month==4) || (day<=21 && month==5)) return "Телец";
        if ((day>=22 && month==5) || (day<=21 && month==6)) return "Близнецы";
        if ((day>=22 && month==6) || (day<=22 && month==7)) return "Рак";
        if ((day>=23 && month==7) || (day<=23 && month==8)) return "Лев";
        if ((day>=24 && month==8) || (day<=23 && month==9)) return "Дева";
        if ((day>=24 && month==9) || (day<=23 && month==10)) return "Весы";
        if ((day>=24 && month==10) || (day<=22 && month==11)) return "Скорпион";
        if ((day>=23 && month==11) || (day<=21 && month==12)) return "Стрелец";
        if ((day>=22 && month==12) || (day<=20 && month==1)) return "Козерог";
        if ((day>=21 && month==1) || (day<=19 && month==2)) return "Водолей";
        return "Рыбы";
    }
};

#endif