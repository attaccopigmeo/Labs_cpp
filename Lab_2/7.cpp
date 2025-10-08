#include <algorithm>
#include <iostream>
#include <list>

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

    std::stable_partition(glist.begin(), glist.end(), [] (int x) { return x < 0; });
    std::stable_partition(glist.begin(), glist.end(), [] (int x) { return x <= 0; });

    std::cout << "Получившийся список: ";
    for (auto x : glist) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}