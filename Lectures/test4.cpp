#include <iostream>

int main() {
    int z, x, y;
    std::cout << "Масса щенка: ";
    std::cin >> z;
    std::cout << "Процент, на сколько котенок меньше щенка: ";
    std::cin >> x;
    std::cout << "Во сколько раз кошка больше котенка и щенка вместе взятых: ";
    std::cin >> y;
    int M = ((z + z * (1 - x / 100)) * y) / 100;
    std::cout << "Масса кошки (в кг): " << M << std::endl;
}