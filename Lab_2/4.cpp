#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

int main() {
    std::ifstream fin("Lab_2/name.txt"); // Открываем входной файл
    if (!fin) {
        std::cerr << "Не удалось открыть файл 'name.txt'\n";
        return 1;
    }
    std::vector<int> numbers;
    int num;
    while (!fin.eof()) {
        fin >> num;
        if (fin.fail()) {
            std::cout << "Неверное содержимое файла" << std::endl;
            return 1;
        }
        numbers.push_back(num);
    }
    fin.close();
    std::vector<int> result;
    // Лямбда-функция для выбора элементов для копирования
    std::remove_copy_if(
        numbers.begin(), numbers.end(),
        std::back_inserter(result),
        [index = 1](int) mutable { return (index++ % 2 == 0); } // пропускаем чётные индексы
    );
    for (int x : result)
        std::cout << x << " ";

    std::cout << std::endl;
}