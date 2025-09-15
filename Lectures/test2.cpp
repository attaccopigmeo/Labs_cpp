#include <iostream>

int main() {
    int n = 0, sum = 0, count_plus = 0, a_max = -1200;
    std::cout << "Enter size: ";
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int x = 0;
        std::cout << "Enter number: ";
        std::cin >> x;
        if(x > a_max) {
            a_max = x;
        }
        sum += x;
        if(x >= 0) {
            count_plus++;
        }
    }
    std::cout << "Summ: " << sum << std::endl;
    std::cout << "Positive numbers: " << count_plus << std::endl;
    std::cout << "Largest number: " << a_max << std::endl;
}