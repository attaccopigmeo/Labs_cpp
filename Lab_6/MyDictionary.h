#pragma once
#ifndef MY_DICTIONARY_H
#define MY_DICTIONARY_H

#include <vector>
#include <iostream>

/// <summary>
/// Простейший шаблонный словарь (ключ-значение), реализованный вручную.
/// </summary>
template <typename K, typename V>
class MyDictionary
{
private:
    struct Pair { K key; V value; };
    std::vector<Pair> items;

public:

    /// <summary>Добавляет пару ключ-значение, если ключ уникален.</summary>
    void Add(const K& key, const V& value)
    {
        for (const auto& p : items)
            if (p.key == key)
                return; // ключ уже есть, игнорируем
        items.push_back({ key, value });
    }

    /// <summary>Удаляет элемент по ключу.</summary>
    void Remove(const K& key)
    {
        for (auto it = items.begin(); it != items.end(); ++it)
            if (it->key == key)
            {
                items.erase(it);
                return;
            }
    }

    /// <summary>Пытается получить значение по ключу.</summary>
    bool TryGet(const K& key, V& value) const
    {
        for (const auto& p : items)
            if (p.key == key)
            {
                value = p.value;
                return true;
            }
        return false;
    }

    /// <summary>Возвращает внутренние элементы.</summary>
    const std::vector<Pair>& GetItems() const
    {
        return items;
    }
};

#endif
