#include "name.cpp"

int main() {
    Name cleopatra("", "Клеопатра", "");
    Name pushkin("Пушкин", "Александр", "Сергеевич");
    Name mayakovsky("Маяковский", "Владимир", "");

    std::cout << cleopatra.toString() << "\n";
    std::cout << pushkin.toString() << "\n";
    std::cout << mayakovsky.toString() << "\n\n";

    Name user = Name::createFromInput();
    std::cout << "Вы ввели: " << user.toString() << "\n";
}