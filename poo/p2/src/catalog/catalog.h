#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include "/home/miguelijo/Escritorio/UCO/Practicas-2-1/poo/p2/src/person/person.h"
#include <vector>
#include <string>

class CyclistCatalog{
    private:
        std::vector<Cyclist>v_cyclists_;
    public:
        bool Load();
        int Size(std::vector<Cyclist> v_cyclists);
        void Data(std::vector<Cyclist> v_cyclists);
        void remove(std::vector<Cyclist> v_cyclists, std::string id);
};

class DirectorCatalog{
    private:
        std::vector<Director>v_directors_;
    public:
        bool Load();
        int Size(std::vector<Director> v_directors);
        void Data(std::vector<Director> v_directors);
        void remove(std::vector<Director> v_directors, std::string id);
};

#endif