#ifndef REQUIREMENT
#define REQUIREMENT

#include "libraries.hpp"
#include "componentKeeper.hpp"

class Requirement {

    ComponentKeeper components;
    bool validRequirement(std::shared_ptr<Component> component);

    public:
    Requirement();
    int count() const;
    void insertComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    std::shared_ptr<Component> getComponent(Component component);
};

#endif