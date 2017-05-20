#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <sstream> //for dumps
#include <lua.hpp>
#include "/home/ubuntu/LuaBridge/LuaBridge.h"
   
extern "C" {
  #include <lua.h>
}

class Component{
    public:
        Component() {}
        virtual ~Component() {}
        virtual std::string dump() const = 0;
};

#endif