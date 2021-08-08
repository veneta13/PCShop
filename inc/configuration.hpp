#ifndef CONFIGURATION
#define CONFIGURATION

#include "libraries.hpp"
#include "componentKeeper.hpp"

class Configuration {

    std::shared_ptr<ComponentKeeper> components;
    double innerPrice = 0;
    bool validConfiguration(std::shared_ptr<Component> component);

    private: //for unit testing
    Configuration();
    int count() const;
    void insertComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    std::shared_ptr<Component> getComponent(Component component);
    std::shared_ptr<Component> getComponentById(int index);
    double price();

    friend class Configurator;
    friend class FileSaver;
};

#endif