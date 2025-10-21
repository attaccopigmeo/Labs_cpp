/*Дана сигнатура функции: int * add (int arr[], int x, int pos);
Необходимо реализовать функцию таким образом, чтобы она возвращала новый
массив, который будет содержать все элементы массива arr, однако в позицию pos
будет вставлено значение x.
Пример:
arr=[1,2,3,4,5]
x=9
pos=3
результат: [1,2,3,9,4,5]*/
#include <iostream>
#include <vector>

void add(std::vector<int>& arr, int x, int pos) {
    if (pos >= 0 && pos < arr.size()) {
        arr[pos] = x;
    }
}

int main() {
    int x;
    bool success = false;
    while (!success) {
        std::cout << "Введите число: ";
        std::cin >> x;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    int n;
    success = false;
    while (!success) {
        std::cout << "Введите размер массива: ";
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != '\n' || n <= 0) {
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
    int pos;
    success = false;
    while (!success) {
        std::cout << "Введите позицию для замены: ";
        std::cin >> pos;
        if (std::cin.fail() || std::cin.peek() != '\n' || pos < 0 || pos >= arr.size()) {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            success = true;
        }
    }
    std::cout << std::endl;
    std::cout << "Массив до замены: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl << std::endl;
    add(arr, x, pos);
    std::cout << "Массив после замены: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}