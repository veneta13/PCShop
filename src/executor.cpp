#include "../inc/executor.hpp"

Executor::Executor(std::string file)
{
    Store& store = Store::getInstance();
    StoreBuilder(&store, file);

    printCommands();
}

void Executor::printCommands()
{
    log(1);
    int index;
    std::cin >> index;
    commandInterpreter(index);
}

void Executor::commandInterpreter(int command)
{
    if (command == 1) {request();}
    else {exit();}
}

void Executor::request()
{
    Store& store = Store::getInstance();
    RequirementBuilder requirementBuilder;
    Configurator configurator(&store);

    configurator.createConfiguration(*requirementBuilder.createRequirement());
    //print 

    printCommands();
}

void Executor::exit()
{
    log(0);
    //save store
}

void Executor::saveInFile(std::string file)
{
    //file writer object
    //to save store
    //and configurations
}

void Executor::log(int status)
{
    if (status == 0) {std::cout << "Exiting the program..." << std::endl;}
    if (status == 1) {std::cout << "Enter the index of the command you want to execute.\n"
                                << "The program has the following commands available:\n"
                                << "#1 Build a requirement;\n"
                                << "#Other - exit.";}
    if (status == 2) {std::cout << "Configuration created successfully. Saving in file..." << std::endl;}
}