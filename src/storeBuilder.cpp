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
        store->insertComponent(getComponent(rawFileData[i]));
    }
}

std::shared_ptr<Component> StoreBuilder::getComponent(std::string string) 
{
    string = stringTransformer(string);
    std::stringstream stream(string);
    //get object type of available type
    std::string type;
    stream >> type;
    std::shared_ptr<Component> component = createComponent(type);

    //creates properties for component
    while (stream.good())
    {
        std::string name;
        stream >> name;
        name = stringTransformerBack(name);

        int quantity;
        stream >> quantity;
        double price;
        stream >> price;
        Property property(name, quantity, price);
        component->addProperty(property);
    }
    return component;
}

std::string StoreBuilder::stringTransformer(std::string string)
{
    //this function transforms empty spaces in string to
    //~ to help read them as one string

    std::vector<int> quotePositions;

    for (int i = 0; i < string.length(); i++)
    {
        if (string[i] == '"') {quotePositions.push_back(i);}
    }

    if (quotePositions.size() % 2 == 0) {
        for (int i = 0; i < quotePositions.size(); i+=2) {
            for (int j = quotePositions[i]; j < quotePositions[i+1]; j++) {
                if (string[j] == ' ') {string[j] = '~';}
            }
        }
    }
    else {throw std::runtime_error("Error: number of quotation marks invalid.");}
    return string;
}

std::string StoreBuilder::stringTransformerBack(std::string string)
{
    //this function reverses the effect of stringTransformer

    if (string.at(0) == '"')
    {
        string = string.substr(1, string.length()-2);
        for (int i = 0; i < string.length(); i++)
        {
            if (string[i] == '~') {string[i] = ' ';}
        }
    }
    return string;
}

std::shared_ptr<Component> StoreBuilder::createComponent(std::string type)
{
    if (type.compare("CPU") == 0) {return std::shared_ptr<Component>(new Cpu());}
    else if (type.compare("RAM") == 0) {return std::shared_ptr<Component>(new Ram());}
    else if (type.compare("HDD") == 0){return std::shared_ptr<Component>(new Hdd());}
    else{throw std::runtime_error("Error: Cannot recognise component.");}
}