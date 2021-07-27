#include "../inc/component.hpp"

    void Component::calculatePrice(){
        double tempPrice = 0.0;

        for (int i = 0; i < properties.size(); i++) {
            Property currentProperty = properties.at(i);
            tempPrice += (currentProperty.getPrice() * currentProperty.getQuantity());
        }

        price = tempPrice;
    }

    void Component::addProperty(Property property){

        for (int i = 0; i < properties.size(); i++) {
            //if there is a property with the same name, replace it
            if (properties.at(i).getName() == property.getName()) {
                //delete instead of changing to keep immutable
                properties.erase(properties.begin() + i);
            }
        }

        //if the property is not in the list, add it
        properties.push_back(property);
        //recalculate the price with the new properties
        calculatePrice();
    }

    void Component::removeProperty(Property property){
            for (int i = 0; i < properties.size(); i++) {
            //if the property is found, remove it
            if (properties.at(i).getName() == property.getName()) {

                properties.erase(properties.begin() + i);

                //recalculate the price with the new properties
                calculatePrice();

                return;
            }
        }

        std::cout << "Error: Property " << property.getName() << " is not found. Nothing is deleted\nTip: Check name spelling.";
    }

    int Component::getPropertyQuantity(std::string propertyName) const{
        for (int i = 0; i < properties.size(); i++) {
            if (properties.at(i).getName() == propertyName) {
                return properties.at(i).getQuantity();
            }
        }

        std::cout << "Error: Property " << propertyName << " is not found.\nTip: Check name spelling.";
        return -1;
    }

    double Component::getPrice() const{
        return price;
    }