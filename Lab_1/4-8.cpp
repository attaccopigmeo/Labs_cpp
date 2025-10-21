/*Дана сигнатура функции: int * concat (int arr1[],int arr2[]);
Необходимо реализовать функцию таким образом, чтобы она возвращала новый
массив, в котором сначала идут элементы первого массива (arr1), а затем второго (arr2).
Пример:
arr1=[1,2,3]
arr2=[7,8,9]
результат: [1,2,3,7,8,9]*/
#include <iostream>
#include <vector>
void concat(std::vector<int>& arr1, std::vector<int>& arr2) {
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
}

int main() {
    int n1;
    bool success = false;
    while (!success) {
        std::cout << "Введите размер массива: ";
        std::cin >> n1;
        if (std::cin.fail() || std::cin.peek() != '\n' || n1 <= 0) {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        success = false;
        while (!success) {
            std::cout << "Введите элемент массива: ";
            std::cin >> arr1[i];
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else {
                success = true;
            }
        }
    }
    int n2;
    success = false;
    while (!success) {
        std::cout << "Введите размер массива: ";
        std::cin >> n2;
        if (std::cin.fail() || std::cin.peek() != '\n' || n2 <= 0) {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        success = false;
        while (!success) {
            std::cout << "Введите элемент массива: ";
            std::cin >> arr2[i];
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else {
                success = true;
            }
        }
    }
    std::cout << std::endl;
    concat(arr1, arr2);
    std::cout << "Объединенный массив: ";
    for (int x : arr1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}