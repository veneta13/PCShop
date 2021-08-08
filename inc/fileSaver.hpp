#ifndef FILESAVER
#define FILESAVER

#include "libraries.hpp"
#include "store.hpp"
#include "property.hpp"
#include "component.hpp"
#include "configuration.hpp"

class FileSaver{

    Store* store;
    std::string storeFile;
    std::string timeNowFileName();

    public:
    FileSaver(Store* store, std::string storeFile);
    void saveStore(std::string filename);
    void saveConfigurationInFile(std::shared_ptr<Configuration> configuration);
};

#endif