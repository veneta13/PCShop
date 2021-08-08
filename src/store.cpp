#include "../inc/store.hpp"

Store::Store()
{
    components = std::shared_ptr<ComponentKeeper>(new ComponentKeeper);
};

Store& Store::getInstance()
{
    static Store instance;
    return instance;
}

int Store::count() const{
    return components->count();
}

void Store::insertComponent(std::shared_ptr<Component> component){
    components->insertComponent(component);
}

void Store::removeComponent(std::shared_ptr<Component> component){
    components->removeComponent(component);
}

int Store::findComponent(Component component){
    return components->findComponent(component);
}

std::shared_ptr<Component> Store::getComponentById(int index)
{
    if (index >= 0 && index < components->count()) {
        return components->component(index);
    }
    else return nullptr;
}