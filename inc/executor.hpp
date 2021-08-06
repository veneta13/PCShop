#ifndef EXECUTOR
#define EXECUTOR

#include "libraries.hpp"
#include "executor.hpp"
#include "storeBuilder.hpp"
#include "requirementBuilder.hpp"
#include "configurator.hpp"

class Executor
{
    void printCommands();
    void request();
    void saveInFile(std::string file);
    void exit();
    void log(int status);

    public:
    Executor(std::string file);
    void commandInterpreter(int command);
};

#endif