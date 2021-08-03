#include "../inc/componentKeeper.hpp"

ComponentKeeper::ComponentKeeper(){};

int ComponentKeeper::count() const{
    return components.size();
}

void ComponentKeeper::insertComponent(Component component){
    components.push_back(component);
}

void ComponentKeeper::removeComponent(Component component){
    for (int i = 0; i < components.size(); i++) 
    {
        if (components[i] == component) {
            components.erase(components.begin() + i);
            return;
        }
    }
    std::cout << "Error: No such component.Nothing is deleted\n";
}

int ComponentKeeper::findComponent(Component component){
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i] == component) {return i;}
    }

    std::cout << "Error: No such component.\n";
    return -1;
}