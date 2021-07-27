#ifndef COMPONENT
#define COMPONENT

#include "libraries.hpp"
#include "property.hpp"

class Component {
    std::vector<Property> properties = {};
    double price = 0.0;

    void calculatePrice();

    public:
    void addProperty(Property property);
    void removeProperty(Property property);
    int getPropertyQuantity(std::string propertyName) const;
    double getPrice() const;
};

#endif 