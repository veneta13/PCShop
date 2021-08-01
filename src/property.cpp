//define EPSILON for double comparison
#define EPSILON 0.000001

#include "../inc/property.hpp"

    Property::Property(std::string name, int quantity, double price){
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }

    bool operator==(const Property p1, const Property p2)
    {
        if (p1.name == p2.name 
        &&  p1.quantity == p2.quantity 
        &&  abs(p1.price-p2.price) < EPSILON) {return true;}
        else {return false;}
    }

    std::string Property::getName() const{
        return name;
    }

    int Property::getQuantity() const{
        return quantity;
    }

    double Property::getPrice() const{
        return price;
    }