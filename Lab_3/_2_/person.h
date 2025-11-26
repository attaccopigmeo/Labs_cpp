#ifndef PERSON_H
#define PERSON_H

#include "fullname.h"

class Person {
private:
    FullName fullname;
    int height;
public:
    Person(FullName n, int h);
    void print() const;
    static Person createFromInput();
};

#endif