#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
    private:
    std::string name_;
    int birth_year_;

    public:
    Person(){
        name_="UNKNOWN";
        birth_year_=-1;
    }

    Person(std::string name, int birth_year);

    std::string GetName();
    int GetYear();

    bool SetName(std::string name);

    bool SetBirthYear(int birth_year);

};
#endif