#include <iostream>

void printDays(int x) {
    switch (x) {
        case 1:
            std::cout << "Понедельник" << std::endl;
        case 2:
            std::cout << "Вторник" << std::endl;
        case 3:
            std::cout << "Среда" << std::endl;
        case 4:
            std::cout << "Четверг" << std::endl;
        case 5:
            std::cout << "Пятница" << std::endl;
        case 6:
            std::cout << "Суббота" << std::endl;
        case 7:
            std::cout << "Воскресенье" << std::endl;
            break;
        default:
            std::cout << "Это не день недели" << std::endl;
    }
}


int main() {
    int x = 0;
    std::cout << "Введите номер дня недели: ";
    std::cin >> x;
    printDays(x);
}