#include "../inc/requirementBuilder.hpp"

RequirementBuilder::RequirementBuilder(){};

std::string RequirementBuilder::promptComponentType()
{
    std::string type;
    std::cout << "Enter the exact name of the component:\n"
              << "CPU\n" 
              << "RAM\n"
              << "HDD\n";

    std::cin >> type;
    return type;
}

std::shared_ptr<Component> RequirementBuilder::createComponent(std::string type)
{
    if (type.compare("CPU") == 0) {return std::shared_ptr<Component>(new Cpu());}
    else if (type.compare("RAM") == 0) {return std::shared_ptr<Component>(new Ram());}
    else if (type.compare("HDD") == 0){return std::shared_ptr<Component>(new Hdd());}
    else{
        std::cout << "Error: Component not recognized.\nTip: Check spelling.";
        return nullptr;
    }
}

RequirementBuilder::PropertyStruct RequirementBuilder::promptPropertyFields()
{
    RequirementBuilder::PropertyStruct property;

    std::string propertyName;
    std::cout << "Enter the name of the property:\n";
    std::getline (std::cin,propertyName);
    property.name = propertyName;

    int propertyQuantity;
    do {
        std::cout << "Enter the quantity of the property:\n";
        std::cin >> propertyQuantity;
    } while (propertyQuantity < 1);
    property.quantity = propertyQuantity;

    double propertyPrice;
    do {
        std::cout << "Enter the price of the property:\n";
        std::cin >> propertyPrice;
    } while (propertyPrice < 0);
    property.price = propertyPrice;

    return property;
}

Property RequirementBuilder::buildProperty(RequirementBuilder::PropertyStruct properties)
{
    Property property(properties.name, properties.quantity, properties.price);
    return property;
}

void RequirementBuilder::createComponent()
{
    //create component of available type
    std::string type = promptComponentType();
    std::shared_ptr<Component> component = createComponent(type);
    if (component == nullptr) {
        std::cout << "Component not created.\n"; 
        return;
    }

    char choice;

    do {
        //add properties
        RequirementBuilder::PropertyStruct propertyFields = promptPropertyFields();
        Property property = buildProperty(propertyFields);
        component->addProperty(property);

        std::cout << "Would you like to add another property? y/n\n";
        std::cin >> choice; 

    } while (choice == 'y');

    //save component to requirement list
    requirement->insertComponent(component);
}

std::shared_ptr<Requirement> RequirementBuilder::createRequirement()
{
    std::cout << "Creating component in the requirement...\n";

    char choice;

    do {
        //create component
        createComponent();

        std::cout << "Would you like to add another component? y/n\n";
        std::cin >> choice; 
    } while (choice == 'y');

    return requirement;
}