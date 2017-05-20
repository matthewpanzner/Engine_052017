#include "Entity.hpp"
#include "../Component/Component.hpp"
#include <typeinfo>
#include <sstream>

Entity::~Entity(){
    for(auto& c : this->components){
        delete c.second;
    }
}

void Entity::dump(){
    std::cout << "ID: " << this->getId() << "   TYPE: " << this->getName() << std::endl;
    
    for(auto& c : this->components){
        std::cout << c.second->dump() << std::endl;
    }
}