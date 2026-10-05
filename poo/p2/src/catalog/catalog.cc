#include "catalog.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "poo/p2/src/person/person.h"


//Funciones CyclistCatalog

bool Load(){


    return true;
}

int CyclistCatalog::Size(std::vector<Cyclist> v_cyclists){ //Errores varios, como el acceder al vector de private que como tal no puedo hacerlo
    if(v_cyclists.empty()==true){
        return -1;
    }
    else{
        int n;
        n=v_cyclists.size();
        return n;
    }
}

void CyclistCatalog:: Data(std::vector<Cyclist> v_cyclists){
    if(v_cyclists.empty()==true){
        std::cout<<"El vector está vacío, no hay datos."<<std::endl;
    }
    else{
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
}

void CyclistCatalog:: Remove(std::vector<Cyclist> v_cyclists, std::string id){
    if(v_cyclists.empty()==true){
        std::cout<<"El vector está vacío, no hay datos para borrar."<<std::endl;
    }
    else{
        std::string idcopia;
        for(auto it = v_cyclists.begin(); it != v_cyclists.end();){
            idcopia=it->Getcyclist_id();
            if(idcopia==id){
                it=v_cyclists.erase(it);
            }
            else{
                it++;
            }
        }
    }
}