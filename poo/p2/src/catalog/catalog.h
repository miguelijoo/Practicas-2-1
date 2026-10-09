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
        const int Size(){return cyclists_.size();}
        const std::vector<Cyclist> Data(){return cyclists_;}
        void Remove(std::string id);
};

class DirectorCatalog{
    private:
        std::vector<Director>directors_;
    public:
        bool Load(const std::string& path);
        const int Size(){return directors_.size();}
        const std::vector <Director> Data(){return directors_;}
        void Remove(std::string id);
};

#endif