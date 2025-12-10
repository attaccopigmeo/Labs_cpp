#pragma once
#ifndef NAME_H
#define NAME_H

#include <string>
#include <sstream>

/// <summary>
/// Базовый класс Имя.
/// Может содержать Фамилию, Имя, Отчество (любое может отсутствовать).
/// </summary>
class Name
{
protected:
    std::string lastName;
    std::string firstName;
    std::string patronymic;

public:
    Name(const std::string& last = "",
         const std::string& first = "",
         const std::string& patr = "")
        : lastName(last), firstName(first), patronymic(patr) {}

    /// <summary>
    /// Преобразует к строке: "Фамилия Имя Отчество"
    /// Пропускает пустые части.
    /// </summary>
    std::string ToString() const
    {
        std::ostringstream ss;
        if (!lastName.empty()) ss << lastName << " ";
        if (!firstName.empty()) ss << firstName << " ";
        if (!patronymic.empty()) ss << patronymic;
        return ss.str();
    }
};

#endif
