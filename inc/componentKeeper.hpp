#ifndef COMPONENTK
#define COMPONENTK

#include "libraries.hpp"
#include "property.hpp"
#include "availableComponents.hpp"

class ComponentKeeper
{
    ComponentKeeper();

    std::vector<Component> components = {};

    int count() const;
    void insertComponent(Component component);
    void removeComponent(Component component);
    int findComponent(Component component);

    friend class Store;
    friend class Configuration;
    friend class Requirement;
};

#endif