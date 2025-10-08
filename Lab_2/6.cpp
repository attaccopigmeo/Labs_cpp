#include <algorithm>
#include <iostream>
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
        } else if (n % 2 != 0) {
            std::cout << "Количество элементов должно быть чётное." << std::endl;
        } else {
            success = true;
        }
    }
    std::vector<int> arr;
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
        arr.push_back(x);
    }

    auto mid = arr.begin() + n / 2;
    std::replace_if(arr.begin(), mid, [](int x) { return x < 0; }, -1);
    std::replace_if(mid, arr.end(), [](int x) { return x > 0; }, 1);

    std::cout << "Получившийся вектор: ";
    for (auto x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}