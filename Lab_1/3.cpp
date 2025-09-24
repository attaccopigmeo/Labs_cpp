#include <iostream>
#include <random>

void guessGame() {
    int count = 0;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, 9);
    int x = uniform_dist(e1);
    while (true) {
        int y;
        bool success = false;
        while (!success) {
            std::cout << "Введите число от 0 до 9: ";
            std::cin >> y;
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            } else {
                success = true;
            }
        }
        ++count;
        if (x == y) {
            std::cout << "Вы угадали!" << std::endl;
            std::cout << "Количество попыток:  " << count << std::endl;
            break;
        }
        else {
            std::cout << "Вы не угадали!" << std::endl;
        }
    }
}


int main() {
    guessGame();
}