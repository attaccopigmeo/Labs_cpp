#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

inline int readInt(const std::string& prompt, int minVal, int maxVal)
{
    while (true)
    {
        std::cout << prompt;
        long long x;
        if (!(std::cin >> x))
        {
            std::cin.clear();
            std::string junk;
            std::getline(std::cin, junk);
            std::cout << "Ошибка: введите целое число.\n";
            continue;
        }
        if (x < minVal || x > maxVal)
        {
            std::cout << "Диапазон: [" << minVal << ", " << maxVal << "]\n";
            continue;
        }
        return (int)x;
    }
}

#endif
