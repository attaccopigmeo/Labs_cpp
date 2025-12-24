#pragma once

#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <vector>

struct Toy {
    char name[64];
    double price;
    int age_from;
    int age_to;
};

class Tasks {
public:
    static int readInt(const std::string &prompt, int minVal, int maxVal);

    // Задание 1
    /*Заполнить бинарный файл числами типа int (random) 
    и подсчитать количество удвоенных нечётных чисел среди компонент*/
    static void fillBinaryInts(const std::string &filename, size_t count, int minVal = -100, int maxVal = 100);
    static size_t countDoubledOddInBinary(const std::string &filename);

    // Задание 2
    /*Скопировать элементы бинарного файла в матрицу m x n, при недостатке заполнить нулями;
    затем превратить в квадратную,добавив строки/столбцы со значением 1*/
    static void fillBinaryIntsForMatrix(const std::string &filename, size_t count, int minVal = -1000, int maxVal = 1000);
    static std::vector<std::vector<int>>  fileToSquareMatrix(const std::string &filename, size_t m, size_t n);

    // Задание 3
    /*Заполнить бинарный файл структурами Toy и найти название самой дешёвой игрушки*/
    static void fillBinaryToys(const std::string &filename, size_t count);
    static std::string findCheapestToyName(const std::string &filename);

    // Задание 4
    /*Текстовый файл: целые числа по одному в строке; заполнить случайно и найти квадрат разности max и min*/
    static void fillTextOneIntPerLine(const std::string &filename, size_t count, int minVal = -1000, int maxVal = 1000);
    static long long squareDiffMaxMin(const std::string &filename);

    // Задание 5
    /*Текстовый файл: несколько целых чисел в строке; заполнить случайно и вычислить сумму нечётных элементов*/
    static void fillTextMultipleIntsPerLine(const std::string &filename, size_t lines, size_t maxPerLine, int minVal = -100, int maxVal = 100);
    static long long sumOddElementsInText(const std::string &filename);

    // Задание 6
    /*В текстовом файле хранится текст. Создать новый текстовый файл, каждая строка которого
    содержит последний символ соответствующей строки исходного файла*/
    static void fillTextWithRandomLines(const std::string &filename, size_t lines);
    static void extractLastCharsToFile(const std::string &srcFilename, const std::string &dstFilename);
};

#endif