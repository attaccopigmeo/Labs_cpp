#include "person.h"
#include <iostream>

int main(){
    Person person_1(FullName("", "Клеопатра", ""), 152);
    Person person_2(FullName("Пушкин", "Александр", "Сергеевич"), 167);
    Person person_3(FullName("Маяковский", "Владимир", ""), 189);
    std::cout << "Список людей:\n";
    person_1.print();
    person_2.print();
    person_3.print();
    std::cout << "\nСоздайте нового человека:\n";
    Person person_user = Person::createFromInput();
    std::cout << "Вы создали:\n";
    person_user.print();

    return 0;
}
