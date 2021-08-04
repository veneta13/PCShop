#include "../inc/store.hpp"

Store::Store(){};

Store& Store::getInstance()
{
    static Store instance;
    return instance;
}

int Store::count() const{
    return components.count();
}

void Store::insertComponent(std::shared_ptr<Component> component){
    components.insertComponent(component);
}

void Store::removeComponent(std::shared_ptr<Component> component){
    components.removeComponent(component);
}

int Store::findComponent(Component component){
    return components.findComponent(component);
}