#include "../inc/configurator.hpp"

Configurator::Configurator(Store* store)
{
    this->store = store;
    configuration = std::shared_ptr<Configuration>(new Configuration);
}

void Configurator::removeSoldComponents()
{
    if (configuration == nullptr) {return;}

    for(int i = 0; i < configuration->count(); i++)
    {
        store->removeComponent(configuration->getComponentById(i));
    }
}

std::shared_ptr<Configuration> Configurator::createConfiguration(Requirement requirement)
{
    if(requirement.count() == 0) {return nullptr;}

    for (int idRequired = 0; idRequired < requirement.count(); idRequired++)
    {
        int bestComponentIndex = -1; //keeps the components that fits the criteria best
        for (int idStore = 0; idStore < store->count(); idStore++)
        {
            //if the component fits the requirements, add it to bestComponentIndex

            if (typeid(*requirement.getComponentById(idRequired)) == typeid(*store->getComponentById(idStore))
            && (*store->getComponentById(idStore) >= *requirement.getComponentById(idRequired)))
            {
                //if there is already a component that fits the requirements, check which one less expensive
                if (bestComponentIndex == -1) {
                    bestComponentIndex = idStore;
                }
                else if ((*store->getComponentById(idStore)).getPrice() < (*store->getComponentById(bestComponentIndex)).getPrice()) {
                    bestComponentIndex = idStore;
                }
            }
        }

        // if there is not component that fits the requirement 
        // such configuration does not exist
        if (bestComponentIndex == -1) {
            configuration = nullptr; 
            std::cout << "Warning: No component fits the requirement.\n";
            break;}
        else {configuration->insertComponent(store->getComponentById(bestComponentIndex));}
    }
    
    removeSoldComponents();
    return configuration;
}

