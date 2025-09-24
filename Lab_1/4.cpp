#include <iostream>
#include <vector>

void deleteNegative(std::vector<int>& arr) {
    for (auto number = arr.begin(); number != arr.end(); ) {
        if (*number < 0) {
            number = arr.erase(number); //erase удаляет элемент и возвр. итератор на следующий  
        }
        else {
            ++number;
        }
    }
}


int main() {
    int n = 0;
    bool success = false;
    while (!success) {
        std::cout << "Введите размер массива: ";
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        success = false;
        while (!success) {
            std::cout << "Введите элемент массива: ";
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
    deleteNegative(arr);
    std::cout << "Результат: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}