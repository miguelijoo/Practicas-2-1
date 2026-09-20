#include "person.h"
#include <string>

Person::Person(std::string name, int birth_year){
        if(name==""){
            name_="UNKNOWN";
        }
        else{
            name_=name;
        }
        if(birth_year<1990){
            birth_year_=-1;
        }
        else{
            birth_year_=birth_year;
        }
    }

std::string Person::GetName(){return name_;}
int Person::GetYear(){return birth_year_;}
bool Person::SetName(std::string name){
    if(name==""){
        return false;
    }
    else{
        name_=name;
        return true;
    }
}

bool Person::SetBirthYear(int birth_year){
    if(birth_year<1990){
        return false;
    }
    else{
        birth_year_=birth_year;
        return true;
    }
}