#include "../inc/component.hpp"
    Component::~Component(){}

    bool operator==(const Component c1, const Component c2){
        if (c1.properties.size() != c2.properties.size()){return false;}
        bool found = false;
        for (int i = 0; i < c1.properties.size(); i++)
        {
            Property c1Property = c1.properties[i];
            for (int j = 0; j < c2.properties.size(); j++)
            {
                Property c2Property = c2.properties[j];
                if (c1Property == c2Property) {found = true;}
            }
            if (!found) {return false;}
            found = false;
        }
        return true;
    }

    bool operator>=(const Component c1, const Component c2){
        if (c1.properties.size() == 0 || c2.properties.size() == 0){return false;}
        
        if (c1.properties.size() != c2.properties.size()) {return false;}
        
        bool found = false;
        
        for (int i = 0; i < c1.properties.size(); i++)
        {
            Property c1Property = c1.properties[i];
            for (int j = 0; j < c2.properties.size(); j++)
            {
                Property c2Property = c2.properties[j];
                if (c1Property > c2Property || c1Property == c2Property) {found = true;}
            }
            if (!found) {return false;}
            found = false;
        }
        return true;
    }

    std::string Component::tellType() const{
        return "BASE";
    }

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

    std::string Component::stringify()
    {
        std::string entry = "";
        entry.append(tellType());
        for (int i = 0; i < properties.size(); i++)
        {
            entry.append(" ");
            //the the name is more than 1 word
            //add quotation marks
            if (properties.at(i).getName().find_first_of(" ") != std::string::npos)
            {
                entry.append("\"");
                entry.append(properties.at(i).getName());
                entry.append("\"");
            }
            else {entry.append(properties.at(i).getName());}

            entry.append(" ");
            entry.append(std::to_string(properties.at(i).getQuantity()));
            entry.append(" ");

            //to ensure precision of 2 digits after the decimal point
            //save the whole number part and the fractional part separately
            double temp = properties.at(i).getPrice() * 100;
            int wholeNum = (int)temp / 100;
            int fractionNum = (int)temp % 100;

            entry.append(std::to_string(wholeNum));
            entry.append(".");
            if (fractionNum < 10) {entry.append("0");}
            entry.append(std::to_string(fractionNum));
        }

        return entry;
    }