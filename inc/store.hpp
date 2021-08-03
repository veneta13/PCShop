#ifndef STORE
#define STORE

#include "libraries.hpp"
#include "componentKeeper.hpp"

class Store {
    //Singleton
    Store();
    Store(Store const&);
    ComponentKeeper components;

    public:
    Store(Store &other) = delete;
    void operator=(const Store&) = delete;
    static Store& getInstance();

    int count() const;
    void insertComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);
    int findComponent(std::shared_ptr<Component> component);
};

#endif