#include "../inc/availableComponents.hpp"

Cpu::~Cpu(){

}

Ram::~Ram(){
    
}

Hdd::~Hdd(){
    
}

std::string Cpu::tellType() const{
    return "CPU";
}

std::string Ram::tellType() const{
    return "RAM";
}

std::string Hdd::tellType() const{
    return "HDD";
}