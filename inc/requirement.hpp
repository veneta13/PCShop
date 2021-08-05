#ifndef REQUIREMENT
#define REQUIREMENT

#include "libraries.hpp"
#include "componentKeeper.hpp"

class Requirement {

    ComponentKeeper components;
    bool validRequirement(std::shared_ptr<Component> component);

    private: //for unit testing
    Requirement();
    int count() const;
    void insertComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    std::shared_ptr<Component> getComponent(Component component);
    std::shared_ptr<Component> getComponentById (int index);

    friend class Configurator;
};

#endif