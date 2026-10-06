#ifndef CATALOG_H
#define CATALOG_H

#include "../person/person.h"
#include <iostream>
#include <vector>
#include <string>

class CyclistCatalog{
    private:
        std::vector<Cyclist>cyclists_;
    public:
        bool Load(const std::string& path);
        int Size(std::vector<Cyclist> v_cyclists);
        void Data(std::vector<Cyclist> v_cyclists);
        void Remove(std::vector<Cyclist> v_cyclists, std::string id);
};

class DirectorCatalog{
    private:
        std::vector<Director>v_directors_;
    public:
        bool Load();
        int Size(std::vector<Director> v_directors);
        void Data(std::vector<Director> v_directors);
        void Remove(std::vector<Director> v_directors, std::string id);
};

#endif