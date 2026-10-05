#include "catalog.h"
#include <iostream>
#include <string>
#include <fstream>
#include "/home/miguelijo/Escritorio/UCO/Practicas-2-1/poo/p2/src/person/person.h"


//Funciones CyclistCatalog

bool Load(){


    return true;
}

int CyclistCatalog::Size(std::vector<Cyclist> v_cyclists){
    int n;
    for(Cyclist i: v_cyclists){
        n++;
    }
    return n;
}

void CyclistCatalog:: Data(std::vector<Cyclist> v_cyclists){
    std::string cad;
    int x, z=1;
    for(Cyclist i: v_cyclists){
        std::cout<<"Ciclista número ";
        std::cout<<z<<std::endl;
        std::cout<<"Nombre: ";
        cad=i.GetName();
        std::cout<<cad<<std::endl;
        std::cout<<"Año nacimiento: ";
        x=i.GetYear();
        std::cout<<x<<std::endl;
        std::cout<<"Id ciclista: ";
        cad=i.Getcyclist_id();
        std::cout<<cad<<std::endl;
        std::cout<<"Equipo: ";
        cad=i.Getteam();
        std::cout<<cad<<std::endl;
    }
}