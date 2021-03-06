#ifndef COMPONENTK
#define COMPONENTK

#include "libraries.hpp"
#include "property.hpp"
#include "availableComponents.hpp"

class ComponentKeeper
{
    std::vector<std::shared_ptr<Component>> components = {};

    int count() const;
    void insertComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    int findComponent(Component component);
    std::shared_ptr<Component> component(int index);

    friend class Store;
    friend class Configuration;
    friend class Requirement;

    public:
    ComponentKeeper();
};

#endif