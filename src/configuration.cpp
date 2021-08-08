#include "../inc/configuration.hpp"

Configuration::Configuration()
{
    components = std::shared_ptr<ComponentKeeper>(new ComponentKeeper);
};

bool Configuration::validConfiguration(std::shared_ptr<Component> component)
{
    for (int i = 0; i < components->count(); i++)
    {
        if (typeid(*component) == typeid(*components->component(i)))
        {
            std::cout << "Error: Component of such type is already registered.\n";
            return false;
        }
    }
    return true;
}

int Configuration::count() const{
    std::cout << "COMPK add:" << components << std::endl;
    return components->count();
}

void Configuration::insertComponent(std::shared_ptr<Component> component){
    if (validConfiguration(component)) { 
        components->insertComponent(component); 
        innerPrice += component->getPrice();
    }
}

void Configuration::removeComponent(std::shared_ptr<Component> component){
    components->removeComponent(component);
    innerPrice -= component->getPrice();
}

std::shared_ptr<Component> Configuration::getComponent(Component component){
    int index = components->findComponent(component);
    if (index == -1) return nullptr;
    return components->component(index);
}

std::shared_ptr<Component> Configuration::getComponentById(int index)
{
    if (index >= 0 && index < components->count()) {
        return components->component(index);
    }
    else return nullptr;
}

double Configuration::price(){
    return (innerPrice * 1.07);
}