#include "../inc/fileSaver.hpp"

FileSaver::FileSaver(Store* store, std::string storeFile){
    this->store = store;
    this->storeFile = storeFile;
}

void FileSaver::saveStore(std::string filename)
{
    std::ofstream file;
    std::string line = "";

    file.open (storeFile, std::ios_base::out | std::ios_base::trunc);
    for (int i = 0; i < store->count(); i++)
    {
        file << store->getComponentById(i)->stringify();
        file << "\n";
    }
    file.close();
}

void FileSaver::saveConfigurationInFile(std::shared_ptr<Configuration> configuration)
{
    std::ofstream file;
    std::string fileName = timeNowFileName();
    std::string line = "";
    file.open (fileName, std::ios_base::out | std::ios_base::trunc);
    for (int i = 0; i < configuration->count(); i++)
    {
        file << configuration->getComponentById(i)->stringify();
        file << "\n";

        //print the status of the save on the console window
        std::cout << configuration->getComponentById(i)->stringify()<< "\n";
    }
    file.close();
}

std::string FileSaver::timeNowFileName()
{
    time_t currentTime = time(0);
    char* dateTimeChar = ctime(&currentTime);
    std::string filename(dateTimeChar); 
    filename = filename.substr(0, filename.length()-1);
    filename.append(".txt");
    
    return filename;
}