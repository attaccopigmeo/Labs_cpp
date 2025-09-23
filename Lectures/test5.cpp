#include <iostream>
#include <iomanip>

int main() {
    int x = 18;
    float y = 13.578;
    std::cout << std::fixed << std::setprecision(2) << y << std::endl;
    std::cout << std::setw(5) << std::hex << x;
}