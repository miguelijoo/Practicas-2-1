#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
    private:
    std::string name_; //variable nombre
    int birth_year_; //variable 

    public:
    Person(){ //Constructor por defecto
        name_="UNKNOWN";
        birth_year_=-1;
    }

    Person(std::string name, int birth_year); //Constructor con parámetros personalizados

    std::string GetName(); //Getters, permiten coger datos de la zona private
    int GetYear();

    bool SetName(std::string name); //Setters, permiten meter datos en la zona private

    bool SetBirthYear(int birth_year);

};
#endif