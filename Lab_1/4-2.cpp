/*Дана сигнатура функции: int findLast (int arr[], int x);
Необходимо реализовать функцию таким образом, чтобы она возвращала индекс
последнего вхождения числа x в массив arr. Если число не входит в массив –
возвращается -1.
Пример:
arr=[1,2,3,4,2,2,5]
x=2
результат: 5*/
#include <iostream>
#include <vector>
#include <algorithm>

int findLast(std::vector<int>& arr, int x) {
    std::vector<int> sought_for = {x};
    auto it = std::find_end(arr.begin(), arr.end(), sought_for.begin(), sought_for.end());
    if (it != arr.end()) {
        return it - arr.begin();
    } else {
        return -1;
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
    std::cout << "Последнее вхождение " << x << " в массив: " << findLast(arr, x) + 1 << std::endl;
    //тк у людей принято считать элементы не с 0, а с 1, прибавляется 1 к позиции
}