#include "../inc/store.hpp"

Store::Store(){};

Store& Store::getInstance()
{
    static Store instance;
    return instance;
}

int Store::count() const{
    return components.size();
}

void Store::insertComponent(Component component){
    components.push_back(component);
}

void Store::removeComponent(Component component){
    for (int i = 0; i < components.size(); i++) 
    {
        if (components[i] == component) {
            components.erase(components.begin() + i);
            return;
        }
    }
    std::cout << "Error: No such component.Nothing is deleted\n";
}

int Store::findComponent(Component component){
    for (int i = 0; i < components.size(); i++)
    {
        if (components[i] == component) {return i;}
    }

    std::cout << "Error: No such component.\n";
    return -1;
}