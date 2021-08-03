#ifndef STORE
#define STORE

#include "libraries.hpp"
#include "property.hpp"
#include "availableComponents.hpp"

class Store {
    //Singleton
    Store();
    Store(Store const&);

    std::vector<Component> components = {};

    public:
    Store(Store &other) = delete;
    void operator=(const Store&) = delete;
    static Store& getInstance();

    int count() const;
    void insertComponent(Component component);
    void removeComponent(Component component);
    int findComponent(Component component);
};

#endif