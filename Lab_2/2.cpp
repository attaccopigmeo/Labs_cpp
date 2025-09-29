#include <deque>
#include <iostream>

int main() {
    size_t n;
    bool success = false;
    while (!success) {
        std::cout << "Введите размер дека (нечетное число): ";
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else if (n % 2 == 0) {
            std::cout << "Требуется вводить нечетное число." << std::endl;
        } else {
            success = true;
        }
    }
    std::deque<int> arr(n);
    for (int i = 0; i < n; i++) {
        success = false;
        while (!success) {
            std::cout << "Введите элемент: ";
            std::cin >> arr[i];
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else {
                success = true;
            }
        }
    }
    arr.insert(arr.begin(), arr.begin() + n / 2 - 2, arr.begin() + n / 2 + 3);
    std::cout << "Получившийся дек: ";
    for (int i = 0; i < n + 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}