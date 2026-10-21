#include "catalog.h"
#include <string>
#include <iostream>

int main(){
    CyclistCatalog c;
    DirectorCatalog d;
    std::string path, name, team, id;
    int birthyear, dirsince;
    std::vector <Cyclist> cyclists;
    std::vector <Director> directors;
    path="";
    c.Load(path);
    path="";
    d.Load(path);
    //Funciones para comprobar CyclistCatalog
    int n=c.Size();
    std::cout<<"Objeto cyclist:"<<std::endl;
    std::cout<<"Hay "<<n<<" ciclistas en el vector."<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    cyclists=c.Data();
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].Getteam();
        birthyear=cyclists[i].GetYear();
        id=cyclists[i].Getcyclist_id();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }
    std::cout<<"Introduce un id de un ciclista a borrar: ";
    std::getline(std::cin, id);
    c.Remove(id);
    std::cout<<"Numero de ciclistas tras el borrado: ";
    n=c.Size();
    std::cout<<n<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    cyclists=c.Data();
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].Getteam();
        birthyear=cyclists[i].GetYear();
        id=cyclists[i].Getcyclist_id();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }

    //Funciones para comprobar DirectorCatalog

    std::cout<<"Objeto director:"<<std::endl;
    n=d.Size();
    std::cout<<"Hay "<<n<<" directores en el vector"<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    directors=d.Data();
    int i=1;
    for(Director &d: directors){
            name=d.GetName();
            birthyear=d.GetYear();
            team=d.Getteam();
            id=d.Getid();
            dirsince=d.Getdirsince();
            std::cout<<"Director numero "<<i<<std::endl;
            i++;
            std::cout<<"Nombre: "<<name<<std::endl;
            std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
            std::cout<<"Equipo: "<<team<<std::endl;
            std::cout<<"Id: "<<id<<std::endl;
            std::cout<<"Director desde: "<<dirsince<<std::endl;
    }
    std::cout<<"Introduce un id de un director a borrar: ";
    std::getline(std::cin, id);
    d.Remove(id);
    std::cout<<"Numero de directores tras el borrado: ";
    n=d.Size();
    std::cout<<n<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    directors=d.Data();
    i=1;
    for(Director &d: directors){
        name=d.GetName();
        birthyear=d.GetYear();
        team=d.Getteam();
        id=d.Getid();
        dirsince=d.Getdirsince();
        std::cout<<"Director numero "<<i<<std::endl;
        i++;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
        std::cout<<"Director desde: "<<dirsince<<std::endl;
    }
}