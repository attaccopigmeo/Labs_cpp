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
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Введите элемент массива: ";
        std::cin >> arr[i];
    }
    deleteNegative(arr);
    std::cout << "Результат: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}