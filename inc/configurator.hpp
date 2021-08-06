#ifndef CONFIGURATOR
#define CONFIGURATOR 

#include "libraries.hpp"
#include "configuration.hpp"
#include "requirement.hpp"
#include "store.hpp"

class Configurator {

    Store* store;
    void removeSoldComponents();
    std::shared_ptr<Configuration> configuration;

    public:
    Configurator(Store* store);
    std::shared_ptr<Configuration> createConfiguration(Requirement requirement);
};

#endif