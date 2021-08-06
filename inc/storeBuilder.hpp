#ifndef STOREBUILDER
#define STOREBUILDER

#include "libraries.hpp"
#include "store.hpp"

class StoreBuilder
{
    Store* store;
    std::vector<std::string> rawFileData;

    StoreBuilder(Store* store);
    void read(std::string filename);
    void rawToObjects();
    std::shared_ptr<Component> createComponent(std::string type);

    public:
    StoreBuilder(Store* store, std::string filename);
};

#endif