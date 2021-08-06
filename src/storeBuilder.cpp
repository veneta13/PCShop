#include "../inc/storeBuilder.hpp"

StoreBuilder::StoreBuilder(Store* store, std::string fileName)
{
    this->store = store;
    read(fileName);
    rawToObjects();
}

void StoreBuilder::read(std::string fileName)
{
    std::fstream fileStream;

    fileStream.open(fileName.c_str(), std::ios::in);

    if (!fileStream.good()) {throw std::runtime_error("Error: Cannot open shop file.");}
    
    //save each file line as a string in vector
    std::string line;
    while (std::getline(fileStream, line)) {
        rawFileData.push_back(line);
    }
    fileStream.close();
}

void StoreBuilder::rawToObjects()
{
    for (int i = 0; i < rawFileData.size(); i++) {
        std::string type;
        std::string propertyName;
        int propertyQuantity;
        double propertyPrice;

        //convert the file line information into stream
        std::stringstream stream(rawFileData[i]);

        //get object type of available types
        stream >> type;
        std::shared_ptr<Component> component = createComponent(type);

        //read line and save to object Property
        //each property save in component
        while (stream >> propertyName) {
            //check if the line doesn't end after the name
            if (stream.str().empty()) {
                throw std::runtime_error("Error: Invalid property at file line " + std::to_string(i));
            }

            stream >> propertyQuantity;
            //check if the line doesn't end after the quantity
            //and validate quantity at least 1
            if (stream.str().empty() || propertyQuantity < 1) {
                throw std::runtime_error("Error: Invalid property at file line " + std::to_string(i));
            }

            stream >> propertyPrice;
            //validate positive price
            if (stream.str().empty() || propertyPrice > 0) {
                throw std::runtime_error("Error: Invalid property at file line " + std::to_string(i));
            }

            Property property(propertyName, propertyQuantity, propertyPrice);
            component->addProperty(property);
        }
        store->insertComponent(component);
    }
}

std::shared_ptr<Component> StoreBuilder::createComponent(std::string type)
{
    if (type.compare("CPU") == 0) {return std::shared_ptr<Component>(new Cpu());}
    else if (type.compare("RAM") == 0) {return std::shared_ptr<Component>(new Ram());}
    else if (type.compare("HDD") == 0){return std::shared_ptr<Component>(new Hdd());}
    else{throw std::runtime_error("Error: Cannot recognise component.");}
}