#ifndef REQUIREMENTB
#define REQUIREMENTB 

#include "libraries.hpp"
#include "requirement.hpp"

class RequirementBuilder{

    std::shared_ptr<Requirement> requirement;

    private: //for unit testing

    struct PropertyStruct{
        std::string name;
        int quantity;
        double price;
    };

    private: //for unit testing
    std::string promptComponentType();
    std::shared_ptr<Component> createComponent(std::string name);
    PropertyStruct promptPropertyFields();
    Property buildProperty(PropertyStruct properties);
    void createComponent();

    public:
    RequirementBuilder();
    std::shared_ptr<Requirement> createRequirement();
};

#endif