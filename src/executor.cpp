#include "../inc/executor.hpp"

Executor::Executor(std::string file)
{
    Store& store = Store::getInstance();
    StoreBuilder(&store, file);
    fileSaver = std::shared_ptr<FileSaver>(new FileSaver(&store, file));
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
    Requirement requirement = *requirementBuilder.createRequirement();

    Configurator configurator(&store);
    std::shared_ptr<Configuration> configuration = configurator.createConfiguration(requirement);

    if (configuration == nullptr) {exit();}
    log(2);
    fileSaver->saveConfigurationInFile(configuration);
    printCommands();
}

void Executor::exit()
{
    log(0);
    fileSaver->saveStore(storeFile);
}

void Executor::log(int status)
{
    if (status == 0) {std::cout << "Exiting the program...\n" << std::endl;}
    if (status == 1) {std::cout << "Enter the index of the command you want to execute.\n"
                                << "The program has the following commands available:\n"
                                << "#1 Build a requirement;\n"
                                << "#Other - exit.\n";}
    if (status == 2) {std::cout << "Configuration created successfully. Saving in file...\n";}
}