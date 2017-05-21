#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <sstream> //for dumps

class Component{
    public:
        Component() {}
        virtual ~Component() {}
        virtual std::string dump() const = 0;
};

#endif