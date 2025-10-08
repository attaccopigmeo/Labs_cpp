#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    size_t n;
    bool success = false;
    while (!success) {
        std::cout << "Введите размер вектора: ";
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::vector<std::string> words;
    for (int i = 0; i < n; i++) {
        std::string x;
        success = false;
        while (!success) {
            std::cout << "Введите элемент: ";
            std::cin >> x;
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else {
                success = true;
            }
        }
        words.push_back(x);
    }

    std::map<char, size_t> lens;
    for (std::string word : words) {
        lens[word[0]] += word.size();
    }

    std::cout << "Суммарные длины слов по буквам:" << std::endl;
    for (auto pair : lens) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}