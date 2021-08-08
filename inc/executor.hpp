#ifndef EXECUTOR
#define EXECUTOR

#include "libraries.hpp"
#include "executor.hpp"
#include "storeBuilder.hpp"
#include "requirementBuilder.hpp"
#include "configurator.hpp"
#include "fileSaver.hpp"

class FileSaver;

class Executor
{
    std::string storeFile;
    std::shared_ptr<FileSaver> fileSaver;
    
    void printCommands();
    void request();
    void exit();
    void log(int status);

    public:
    Executor(std::string file);
    void commandInterpreter(int command);
};

#endif