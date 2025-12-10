#include "tasks.h"
#include <fstream>
#include <random>
#include <chrono>
#include <iostream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <cctype>

static std::mt19937& rng() {
    static std::mt19937 gen((unsigned)std::chrono::high_resolution_clock::now().time_since_epoch().count());
    return gen;
}

int Tasks::readInt(const std::string &prompt, int minVal, int maxVal) {
    while (true) {
        std::cout << prompt;
        long long x;
        if (!(std::cin >> x)) {
            std::cin.clear();
            std::string junk;
            std::getline(std::cin, junk);
            std::cout << "Неверный ввод. Пожалуйста, введите целое число.\n";
            continue;
        }
        if (x < minVal || x > maxVal) {
            std::cout << "Значение должно быть в диапазоне [" << minVal << ", " << maxVal << "]\n";
            continue;
        }
        return (int)x;
    }
}

void Tasks::fillBinaryInts(const std::string &filename, size_t count, int minVal, int maxVal) {
    std::ofstream ofs(filename, std::ios::binary);
    std::uniform_int_distribution<int> dist(minVal, maxVal);
    for (size_t i = 0; i < count; i++) {
        int v = dist(rng());
        ofs.write(reinterpret_cast<char*>(&v), sizeof(v));
    }
}

size_t Tasks::countDoubledOddInBinary(const std::string &filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) return 0;
    size_t count = 0;
    int v;
    while (ifs.read(reinterpret_cast<char*>(&v), sizeof(v))) {
    // "удвоенные нечетные числа среди компонент файла" — числа, которые являются удвоением нечётного числа,
    // т.е. v == 2 * k, где k - нечетное. Эквивалентно: v % 2 == 0 and (v/2) % 2 != 0
        if (v % 2 == 0) {
            int half = v / 2;
            if (std::abs(half) % 2 == 1) ++count;
        }
    }
    return count;
}

void Tasks::fillBinaryIntsForMatrix(const std::string &filename, size_t count, int minVal, int maxVal) {
    fillBinaryInts(filename, count, minVal, maxVal);
}

std::vector<std::vector<int>> Tasks::fileToSquareMatrix(const std::string &filename, size_t m, size_t n) {
    std::ifstream ifs(filename, std::ios::binary);
    std::vector<int> data;
    int v;
    while (ifs.read(reinterpret_cast<char*>(&v), sizeof(v))) data.push_back(v);

    size_t needed = m * n;
    data.resize(needed, 0);

    std::vector<std::vector<int>> mat(m, std::vector<int>(n, 0));
    size_t idx = 0;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            mat[i][j] = data[idx++];
        }
    }
    size_t s = std::max(m, n);
    if (m < s) mat.resize(s, std::vector<int>(n, 0));
    for (size_t i = 0; i < s; ++i) {
        if (mat[i].size() < s) mat[i].resize(s, 1);
    }
    for (size_t i = m; i < s; ++i) for (size_t j = 0; j < s; ++j) mat[i][j] = 1;

    for (size_t i = 0; i < m; ++i) for (size_t j = n; j < s; ++j) mat[i][j] = 1;

    return mat;
}

void Tasks::fillBinaryToys(const std::string &filename, size_t count) {
    std::ofstream ofs(filename, std::ios::binary);
    std::uniform_real_distribution<double> distPrice(100.0, 5000.0);
    std::uniform_int_distribution<int> distAge(0, 12);
    std::vector<std::string> sampleNames = {"Teddy Bear", "Car", "Doll", "Puzzle", "Blocks", "Robot", "Ball", "Train"};
    std::uniform_int_distribution<int> nameIdx(0, (int)sampleNames.size()-1);

    for (size_t i = 0; i < count; ++i) {
        Toy t{};
        std::string nm = sampleNames[nameIdx(rng())] + std::to_string(i);
        strncpy(t.name, nm.c_str(), sizeof(t.name)-1);
        t.price = std::round(distPrice(rng())*100.0)/100.0;
        int a = distAge(rng());
        int b = distAge(rng());
        if (a <= b) { t.age_from = a; t.age_to = b; } else { t.age_from = b; t.age_to = a; }
        ofs.write(reinterpret_cast<char*>(&t), sizeof(t));
    }
}

std::string Tasks::findCheapestToyName(const std::string &filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) return std::string();
    Toy t;
    bool first = true;
    Toy best{};
    while (ifs.read(reinterpret_cast<char*>(&t), sizeof(t))) {
        if (first || t.price < best.price) { best = t; first = false; }
    }
    if (first) return std::string();
    best.name[sizeof(best.name)-1] = '\0';
    return std::string(best.name);
}

void Tasks::fillTextOneIntPerLine(const std::string &filename, size_t count, int minVal, int maxVal) {
    std::ofstream ofs(filename);
    std::uniform_int_distribution<int> dist(minVal, maxVal);
    for (size_t i = 0; i < count; ++i) ofs << dist(rng()) << '\n';
}

long long Tasks::squareDiffMaxMin(const std::string &filename) {
    std::ifstream ifs(filename);
    if (!ifs) return 0;
    long long x;
    bool first = true;
    long long mn = 0, mx = 0;
    while (ifs >> x) {
        if (first) { mn = mx = x; first = false; }
        else { mn = std::min(mn, x); mx = std::max(mx, x); }
    }
    long long d = mx - mn;
    return d * d;
}

void Tasks::fillTextMultipleIntsPerLine(const std::string &filename, size_t lines, size_t perLine, int minVal, int maxVal) {
    std::ofstream ofs(filename);
    std::uniform_int_distribution<int> dist(minVal, maxVal);
    for (size_t i = 0; i < perLine; ++i) {
        for (size_t j = 0; j < perLine; ++j) {
            ofs << dist(rng());
            if (j+1 < perLine) ofs << ' ';
        }
        ofs << '\n';
    }
}

long long Tasks::sumOddElementsInText(const std::string &filename) {
    std::ifstream ifs(filename);
    if (!ifs) return 0;
    long long sum = 0;
    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        long long x;
        while (iss >> x) if (std::llabs(x) % 2 == 1) sum += x;
    }
    return sum;
}

void Tasks::fillTextWithRandomLines(const std::string &filename, size_t lines) {
    std::ofstream ofs(filename);
    std::uniform_int_distribution<int> lenDist(0, 60);
    std::uniform_int_distribution<int> chDist(32, 126);
    for (size_t i = 0; i < lines; ++i) {
        int len = lenDist(rng());
        for (int j = 0; j < len; ++j) ofs << static_cast<char>(chDist(rng()));
        ofs << '\n';
    }
}

void Tasks::extractLastCharsToFile(const std::string &srcFilename, const std::string &dstFilename) {
    std::ifstream ifs(srcFilename);
    std::ofstream ofs(dstFilename);
    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) ofs << '\n';
        else ofs << line.back() << '\n';
    }
}