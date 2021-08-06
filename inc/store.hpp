#ifndef STORE
#define STORE

#include "libraries.hpp"
#include "componentKeeper.hpp"

class Store {
    //Singleton
    Store();
    Store(Store const&);
    ComponentKeeper components;

    private: //for unit testing
    Store(Store &other) = delete;
    void operator=(const Store&) = delete;

    int count() const;
    void insertComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    int findComponent(Component component);
    std::shared_ptr<Component> getComponentById(int index);

    public:
    static Store& getInstance();

    friend class Configurator;
};

#endif