#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
    size_t deque_size;
    bool success = false;
    while (!success) {
        std::cout << "Введите размер дека (четное число): ";
        std::cin >> deque_size;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else if (deque_size < 2 || deque_size % 2 != 0) {
            std::cout << "Размер должен быть более >= 2, требуется вводить четное число." << std::endl;
        } else {
            success = true;
        }
    }
    std::deque<int> arr(deque_size);
    for (int i = 0; i < deque_size; i++) {
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
    std::swap(arr[deque_size / 2 - 1], arr[deque_size / 2]);

    size_t list_size;
    success = false;
    std::cout << "Введите размер списка (четное число): ";
    std::cin >> list_size;
    if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else if (list_size < 2 || list_size % 2 != 0) {
            std::cout << "Размер должен быть более >= 2, требуется вводить четное число." << std::endl;
        } else {
            success = true;
        }
    std::list<int> glist;
    for (int i = 0; i < list_size; i++) {
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
    auto iter = glist.begin();
    for (int i = 0; i < list_size / 2 - 1; i++) {
        iter++;
    }
    auto iter_2 = iter;
    iter_2++;
    glist.insert(iter, *iter_2); //* - возвр значение, на которе указывает итератор
    glist.erase(iter_2);

    int vector_size;
    success = false;
    std::cout << "Введите размер массива (четное число): ";
    std::cin >> vector_size;
    if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Неверный ввод" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else if (vector_size < 2 || vector_size % 2 != 0) {
            std::cout << "Размер должен быть более >= 2, требуется вводить четное число." << std::endl;
        } else {
            success = true;
        }
    std::vector<int> vector(vector_size);
    for (int i = 0; i < vector_size; i++) {
        success = false;
        while (!success) {
            std::cout << "Введите элемент: ";
            std::cin >> vector[i];
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else {
                success = true;
            }
        }
    }
    std::swap(vector[vector_size / 2 - 1], vector[vector_size / 2]);

    std::cout << "Элементы дека: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Элементы списка: ";
    for (int x : glist) {
        std::cout << x << " "; 
    }
    std::cout << std::endl;

    std::cout << "Элементы массива: ";
    for (int x : vector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}