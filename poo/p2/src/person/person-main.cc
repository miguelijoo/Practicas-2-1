#include "person.h"
#include <string>
#include <iostream>

int main(){
    Person p;
    Cyclist c;
    Director d;
    std::string name, team, cyclist_id, uci_license_id;
    int birthyear, director_since;

    //Recogida datos de Person
    std::cout<<"Introduzca los atributos de la clase person"<<std::endl;
    std::cout<<"Nombre: ";
    std::getline(std::cin, name);
    p.SetName(name);
    std::cout<<"Fecha nacimiento: ";
    std::cin>>birthyear;
    std::cin.ignore();
    p.SetBirthYear(birthyear);

    //Muestra de datos de Person

    std::cout<<"Nombre de Person: ";
    std::cout<<p.GetName()<<std::endl;
    std::cout<<"Fecha de nacimiento de Person: ";
    std::cout<<p.GetYear()<<std::endl;

    //Recogida de datos de Cyclist
    
    std::cout<<"Introduzca los atributos de la clase Cyclist"<<std::endl;
    std::cout<<"Nombre: ";
    std::getline(std::cin, name);
    c.SetName(name);
    std::cout<<"Fecha nacimiento: ";
    std::cin>>birthyear;
    std::cin.ignore();
    c.SetBirthYear(birthyear);
    std::cout<<"Equipo: ";
    std::getline(std::cin, team);
    c.Setteam(team);
    std::cout<<"Id: ";
    std::getline(std::cin, cyclist_id);
    c.Setcyclist_id(cyclist_id);

    //Muestra de datos de Cyclist

    std::cout<<"Nombre de Cyclist: ";
    std::cout<<c.GetName()<<std::endl;
    std::cout<<"Fecha de nacimiento de Cyclist: ";
    std::cout<<c.GetYear()<<std::endl;
    std::cout<<"Team de Cyclist: ";
    std::cout<<c.Getteam()<<std::endl;
    std::cout<<"Id de Cyclist: ";
    std::cout<<c.Getcyclist_id()<<std::endl;

    //Recogida de datos de Director

    std::cout<<"Introduzca los atributos de la clase Director"<<std::endl;
    std::cout<<"Nombre: ";
    std::getline(std::cin, name);
    d.SetName(name);
    std::cout<<"Fecha nacimiento: ";
    std::cin>>birthyear;
    std::cin.ignore();
    d.SetBirthYear(birthyear);
    std::cout<<"Equipo: ";
    std::getline(std::cin, team);
    d.Setteam(team);
    std::cout<<"Id: ";
    std::getline(std::cin, uci_license_id);
    d.Setid(uci_license_id);
    std::cout<<"Director desde: ";
    std::cin>>director_since;
    d.Setdirsince(director_since);

    //Muestra de datos de Director

    std::cout<<"Nombre de Director: ";
    std::cout<<d.GetName()<<std::endl;
    std::cout<<"Fecha de nacimiento de Director: ";
    std::cout<<d.GetYear()<<std::endl;
    std::cout<<"Team de Director: ";
    std::cout<<d.Getteam()<<std::endl;
    std::cout<<"Id de Director: ";
    std::cout<<d.Getid()<<std::endl;
    std::cout<<"Director since: ";
    std::cout<<d.Getdirsince()<<std::endl;
    exit(EXIT_SUCCESS);
}