#include <iostream>

int main() {
    int a = 1;
    std::cout << "Your number: ";
    std::cin >> a;
    if(a % 2 == 0) {
        std::cout << "even" << std::endl;
    } else {
        std::cout << "odd" << std::endl;
    }
}