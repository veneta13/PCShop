#ifndef CONFIGURATION
#define CONFIGURATION

#include "libraries.hpp"
#include "componentKeeper.hpp"

class Configuration {

    ComponentKeeper components;
    bool validConfiguration(std::shared_ptr<Component> component);

    public:
    Configuration();
    int count() const;
    void insertComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    std::shared_ptr<Component> getComponent(Component component);
};

#endif