#include "catalog.h"
#include <string>
#include <iostream>

int main(){
    CyclistCatalog c;
    DirectorCatalog d;
    std::string path;
    path="../../data/cyclists.csv";
    c.Load(path);
    path="../../data/directors.csv";
    d.Load(path);
    //Funciones para comprobar CyclistCatalog
    int n=c.Size();
    std::cout<<"Objeto cyclist:"<<std::endl;
    std::cout<<"Hay "<<n<<" ciclistas en el vector."<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    c.Data();
    std::cout<<"Introduce un id de un ciclista a borrar: ";
    std::string id;
    std::getline(std::cin, id);
    c.Remove(id);
    std::cout<<"Numero de ciclistas tras el borrado: ";
    n=c.Size();
    std::cout<<n<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    c.Data();
    //Funciones para comprobar DirectorCatalog
    std::cout<<"Objeto director:"<<std::endl;
    n=d.Size();
    std::cout<<"Hay "<<n<<" directores en el vector"<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    d.Data();
    std::cout<<"Introduce un id de un director a borrar: ";
    std::getline(std::cin, id);
    d.Remove(id);
    std::cout<<"Numero de directores tras el borrado: ";
    n=d.Size();
    std::cout<<n<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    d.Data();
}