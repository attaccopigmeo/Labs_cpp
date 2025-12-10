#pragma once
#ifndef UNORDERED_UNIQUE_LIST_H
#define UNORDERED_UNIQUE_LIST_H

#include <iostream>
#include <vector>

/// <summary>
/// Класс шаблонного неупорядоченного списка уникальных элементов.
/// Элементы хранятся в обычном std::vector, но без доступа по индексу.
/// </summary>
/// <typeparam name="T">Тип данных элементов списка</typeparam>
template <typename T>
class UnorderedUniqueList
{
private:
    std::vector<T> data; // внутреннее хранилище

public:
    /// <summary>
    /// Проверяет, содержится ли элемент в коллекции.
    /// </summary>
    bool Contains(const T& value) const
    {
        for (const auto& v : data)
            if (v == value) return true;
        return false;
    }

    /// <summary>
    /// Добавляет элемент, если его ещё нет.
    /// </summary>
    void Add(const T& value)
    {
        if (!Contains(value))
            data.push_back(value);
    }

    /// <summary>
    /// Удаляет элемент, если он существует.
    /// </summary>
    void Remove(const T& value)
    {
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (*it == value)
            {
                data.erase(it);
                return;
            }
        }
    }

    /// <summary>
    /// Возвращает список, являющийся объединением двух коллекций.
    /// </summary>
    UnorderedUniqueList<T> Union(const UnorderedUniqueList<T>& other) const
    {
        UnorderedUniqueList<T> result = *this;
        for (const T& x : other.data)
            result.Add(x);
        return result;
    }

    /// <summary>
    /// Возвращает список, в котором элементы this без элементов other.
    /// </summary>
    UnorderedUniqueList<T> Except(const UnorderedUniqueList<T>& other) const
    {
        UnorderedUniqueList<T> result;
        for (const T& x : data)
            if (!other.Contains(x))
                result.Add(x);
        return result;
    }

    /// <summary>
    /// Возвращает список общих элементов двух коллекций.
    /// </summary>
    UnorderedUniqueList<T> Intersect(const UnorderedUniqueList<T>& other) const
    {
        UnorderedUniqueList<T> result;
        for (const T& x : data)
            if (other.Contains(x))
                result.Add(x);
        return result;
    }

    /// <summary>
    /// Печать содержимого.
    /// </summary>
    void Print() const
    {
        for (const auto& x : data)
            std::cout << x << " ";
        std::cout << std::endl;
    }

    /// <summary>
    /// Возвращает внутренний вектор (для задач, где нужен перебор).
    /// </summary>
    const std::vector<T>& Items() const { return data; }
};

#endif
