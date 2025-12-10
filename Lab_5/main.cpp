#include "tasks.h"
#include <iostream>

int main() {
    // Задание 1
    const std::string binIntsFile = "Lab_5/bin_ints.dat";
    Tasks::fillBinaryInts(binIntsFile, 100);
    size_t doubledOddCount = Tasks::countDoubledOddInBinary(binIntsFile);
    std::cout << "Задание 1: Количество удвоенных нечетных чисел: " << doubledOddCount << "\n";

    // Задание 2
    const std::string binMatrixFile = "Lab_5/bin_matrix.dat";
    Tasks::fillBinaryIntsForMatrix(binMatrixFile, 20);
    size_t m = 4, n = 6;
    auto squareMat = Tasks::fileToSquareMatrix(binMatrixFile, m, n);
    std::cout << "Задание 2: Полученная квадратная матрица (размер " << squareMat.size() << "):\n";
    for (auto &row : squareMat) {
        for (auto val : row) std::cout << val << '\t';
        std::cout << '\n';
    }

    // Задание 3
    const std::string binToysFile = "Lab_5/toys.dat";
    Tasks::fillBinaryToys(binToysFile, 15);
    std::string cheapest = Tasks::findCheapestToyName(binToysFile);
    std::cout << "Задание 3: Самая дешевая игрушка: " << (cheapest.empty() ? "(файл пуст)" : cheapest) << "\n";

    // Задание 4
    const std::string textOnePerLine = "Lab_5/one_per_line.txt";
    Tasks::fillTextOneIntPerLine(textOnePerLine, 50);
    long long sq = Tasks::squareDiffMaxMin(textOnePerLine);
    std::cout << "Задание 4: Квадрат разности max и min: " << sq << "\n";

    // Задание 5
    const std::string textMultiLine = "Lab_5/multiple_per_line.txt";
    Tasks::fillTextMultipleIntsPerLine(textMultiLine, 10, 8);
    long long sumOdd = Tasks::sumOddElementsInText(textMultiLine);
    std::cout << "Задание 5: Сумма нечетных элементов: " << sumOdd << "\n";

    // Задание 6
    const std::string srcText = "Lab_5/text_source.txt";
    const std::string dstText = "Lab_5/text_last_chars.txt";
    Tasks::fillTextWithRandomLines(srcText, 12);
    Tasks::extractLastCharsToFile(srcText, dstText);
    std::cout << "Задание 6: Создан файл с последними символами: " << dstText << "\n";

    return 0;
}