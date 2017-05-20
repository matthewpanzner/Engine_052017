#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "../Entity/Entity.hpp"
#include <vector>

class System{
public:
    System() {}
    
    virtual void run(std::vector<Entity*> entities) = 0;
private:
};

#endif