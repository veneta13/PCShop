#include "../inc/requirement.hpp"

Requirement::Requirement(){};

bool Requirement::validRequirement(std::shared_ptr<Component> component)
{
    for (int i = 0; i < components.count(); i++)
    {
        if (typeid(*component) == typeid(*components.component(i)))
        {
            std::cout << "Error: Component of such type is already registered.\n";
            return false;
        }
    }
    return true;
}

int Requirement::count() const{
    return components.count();
}

void Requirement::insertComponent(std::shared_ptr<Component> component){
    if (validRequirement(component)) { components.insertComponent(component); }
}

void Requirement::removeComponent(std::shared_ptr<Component> component){
    components.removeComponent(component);
}

std::shared_ptr<Component> Requirement::getComponent(Component component){
    int index = components.findComponent(component);
    if (index == -1) return nullptr;
    return components.component(index);
}