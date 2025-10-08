#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int safe_read(std::string prompt) {
    int x;
    bool success = false;
    while (!success) {
        std::cout << prompt << ": ";
        std::cin >> x;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    return x;
}

int main() {
    size_t v0_size = safe_read("Введите размер вектора V0");
    std::vector<int> v0;
    for (int i = 0; i < v0_size; i++) {
        v0.push_back(safe_read("Введите элемент"));
    }
    std::sort(v0.begin(), v0.end());

    size_t n = safe_read("Введите количество векторов в наборе");
    std::vector<int> v;
    size_t ans = 0;
    for (int i = 0; i < n; ++i) {
        v.clear();
        size_t v_size = safe_read("Введите размер вектора V" + std::to_string(i + 1));
        for (int j = 0; j < v_size; ++j) {
            v.push_back(safe_read("Введите элемент"));
        }
        std::sort(v.begin(), v.end());
        if (std::includes(v.begin(), v.end(), v0.begin(), v0.end())) {
            ans++;
        }
    }

    std::cout << "Количество искомых векторов: " << ans << std::endl;
}