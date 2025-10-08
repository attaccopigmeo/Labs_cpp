#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main() {
    size_t n;
    bool success = false;
    while (!success) {
        std::cout << "Введите размер списка: ";
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::list<int> glist;
    for (int i = 0; i < n; i++) {
        int x;
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
        glist.push_back(x);
    }

    std::vector<double> arr(n);
    std::adjacent_difference(
        glist.begin(),
        glist.end(),
        arr.begin(),
        [] (int a, int b) { return (a + b) / 2.0; }
    );
    arr.erase(arr.begin());

    std::cout << "Получившийся вектор: ";
    for (auto x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}