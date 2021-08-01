#ifndef COMPONENT
#define COMPONENT

#include "libraries.hpp"
#include "property.hpp"

class Component {
    protected:
    std::vector<Property> properties = {};
    double price = 0.0;

    void calculatePrice();

    public:
    virtual ~Component();
    friend bool operator==(const Component c1, const Component c2);

    virtual std::string tellType() const;
    void addProperty(Property property);
    void removeProperty(Property property);
    int getPropertyQuantity(std::string propertyName) const;
    double getPrice() const;
};

#endif 