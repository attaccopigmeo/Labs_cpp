/*Дана сигнатура функции: void reverse (int arr[]);
Необходимо реализовать функцию таким образом, чтобы он изменял массив arr. После
проведенных изменений массив должен быть записан задом-наперед.
Пример:
arr=[1,2,3,4,5]
результат: arr=[5,4,3,2,1]*/
#include <iostream>
#include <vector>

void reverse(std::vector<int>& arr) {
    std::vector<int> reversed;
    reversed.reserve(arr.size());
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        reversed.push_back(*it);
    }
    arr = reversed;
}
/*rbegin() - указывает на последний эл. массива
rend() - указывает на эл. перед первым*/

int main() {
    int n;
    bool success = false;
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
    std::cout << std::endl;
    std::cout << "Массив: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl << std::endl;
    reverse(arr);
    std::cout << "Перевернутый массив: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}