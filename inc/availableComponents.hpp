#ifndef CPU
#define CPU

#include "libraries.hpp"
#include "property.hpp"
#include "component.hpp"

class Cpu : public Component {
    public:
    virtual ~Cpu();
    std::string tellType() const override;
};

class Ram : public Component {
    public:
    virtual ~Ram();
    std::string tellType() const override;
};

class Hdd : public Component {
    public:
    virtual ~Hdd();
    std::string tellType() const override;
};

#endif