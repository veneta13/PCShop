
// Име: Венета Славчева Кирева
// ФН: 82184
// Използван компилатор: GCC 9.2.0

#include "../inc/libraries.hpp"
#include "../inc/executor.hpp"
 
int main(int argc, char *argv[])
{
    try{
        if (argc < 2) {throw std::runtime_error("Error: Please enter file name.");}
        std::string filename(argv[1]);
        Executor executor(filename);
        return 0;
    }
    catch(std::exception const & e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}