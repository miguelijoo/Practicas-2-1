#include "person.h"
#include <string>
#include <iostream>

void print_person(Person p){
    std::cout<<"Name: " << p.GetName()<<'\n';
    std::cout<<"BirthYear: " << p.GetYear()<<'\n';
}

int main(){
    Person p1;
    Person p2("Luis", 1992);
    std::string name;
    int year;
    print_person(p1);
    print_person(p2);

    std::cout<<"Introduce el nombre de p1: ";
    std::getline(std::cin, name);
    std::cout<<"Introduce el año de nacimiento de p1: ";
    std::cin>>year;
    std::cin.ignore();
    p1.SetName(name);
    p1.SetBirthYear(year);
    print_person(p1);

    std::cout<<"Introduce el nombre de p2: ";
    std::getline(std::cin, name);
    std::cout<<"Introduce el año de nacimiento de p2: ";
    std::cin>>year;
    std::cin.ignore();
    p2.SetName(name);
    p2.SetBirthYear(year);
    print_person(p2);
}