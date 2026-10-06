#ifndef CATALOG_H
#define CATALOG_H

#include "../person/person.h"
#include <vector>
#include <string>

class CyclistCatalog{
    private:
        std::vector<Cyclist>cyclists_;
    public:
        bool Load(const std::string& path);
        int Size();
        void Data();
        void Remove(std::string id);
};

class DirectorCatalog{
    private:
        std::vector<Director>directors_;
    public:
        bool Load(const std::string& path);
        int Size();
        void Data();
        void Remove(std::string id);
};

#endif