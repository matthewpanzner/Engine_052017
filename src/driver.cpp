#include "ECS/Entity/Entity.hpp"
#include "ECS/Component/PositionComponent.hpp"
#include <iostream>

int main(){
    Entity* ent = new Entity();
    Entity* ent2 = new Entity();
    ent->setName("ent1");
    ent->addComponent(std::type_index(typeid(PositionComponent)), new PositionComponent());
    
    ent->dump();



    std::cout << "Cleaning..." << std::endl;
    
    delete ent;
    delete ent2;
    
    std::cout << "Cleanup complete" << std::endl;
    
    return 0;
}