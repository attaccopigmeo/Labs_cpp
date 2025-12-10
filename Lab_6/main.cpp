#include <iostream>
#include <string>
#include <fstream>

#include "UnorderedUniqueList.h"
#include "MyDictionary.h"
#include "Person.h"
#include "Utils.h"

using namespace std;

int main()
{
    cout << "=== ЗАДАНИЕ 1: Языки сотрудников ===\n";

    int workers = readInt("Введите количество сотрудников: ", 1, 100);

    UnorderedUniqueList<string> allLanguages;
    UnorderedUniqueList<string> languagesKnownByAll;
    UnorderedUniqueList<string> languagesKnownByAtLeastOne;

    vector< UnorderedUniqueList<string> > workerLangs(workers);

    for (int i = 0; i < workers; ++i)
    {
        int count = readInt("Сколько языков знает сотрудник #" + to_string(i+1) + ": ", 0, 50);

        cout << "Введите языки через пробел:\n";
        for (int j = 0; j < count; ++j)
        {
            string lang;
            cin >> lang;

            workerLangs[i].Add(lang);
            languagesKnownByAtLeastOne.Add(lang);
            allLanguages.Add(lang);
        }
    }

    languagesKnownByAll = workerLangs[0];
    for (int i = 1; i < workers; ++i)
        languagesKnownByAll = languagesKnownByAll.Intersect(workerLangs[i]);

    cout << "\nЯзыки, которые знают ВСЕ:\n";
    languagesKnownByAll.Print();

    cout << "Языки, которые знают ХОТЯ БЫ ОДИН:\n";
    languagesKnownByAtLeastOne.Print();

    UnorderedUniqueList<string> knownByNoOne =
        allLanguages.Except(languagesKnownByAtLeastOne);

    cout << "Языки, которые НЕ ЗНАЕТ НИКТО:\n";
    knownByNoOne.Print();

    // ------------------------------
    cout << "\n=== ЗАДАНИЕ 2: АЗС ===\n";

    ifstream fin("Lab_6/input.txt");
    if (!fin)
    {
        cout << "Файл input.txt не найден!\n";
    }
    else
    {
        MyDictionary<string, int> cheapest92;
        MyDictionary<string, int> cheapest95;
        MyDictionary<string, int> cheapest98;

        int n;
        fin >> n;

        int min92 = 10000, min95 = 10000, min98 = 10000;

        for (int i = 0; i < n; i++)
        {
            string company, street;
            int mark, price;
            fin >> company >> street >> mark >> price;

            string key = company + "_" + street;

            if (mark == 92)
            {
                if (price < min92)
                {
                    min92 = price;
                    cheapest92 = MyDictionary<string, int>();
                }
                if (price == min92)
                    cheapest92.Add(key, price);
            }
            else if (mark == 95)
            {
                if (price < min95)
                {
                    min95 = price;
                    cheapest95 = MyDictionary<string, int>();
                }
                if (price == min95)
                    cheapest95.Add(key, price);
            }
            else if (mark == 98)
            {
                if (price < min98)
                {
                    min98 = price;
                    cheapest98 = MyDictionary<string, int>();
                }
                if (price == min98)
                    cheapest98.Add(key, price);
            }
        }

        cout << "Минимум 92: " << cheapest92.GetItems().size() << "\n";
        cout << "Минимум 95: " << cheapest95.GetItems().size() << "\n";
        cout << "Минимум 98: " << cheapest98.GetItems().size() << "\n";
    }

    // ------------------------------
    cout << "\n=== ЗАДАНИЕ 3: Имена и наследование ===\n";

    Person cleopatra("", "Клеопатра", "", 1, 1, -30);
    Person pushkin("Пушкин", "Александр", "Сергеевич", 6, 6, 1799);
    Person mayakov("Маяковский", "Владимир", "", 19, 7, 1893);

    vector<Person> persons = { cleopatra, pushkin, mayakov };

    for (const auto& p : persons)
    {
        cout << "Имя: " << p.ToString() << "\n";
        cout << "Возраст: " << p.GetAge() << "\n";
        cout << "Знак зодиака: " << p.GetZodiac() << "\n\n";
    }

    return 0;
}