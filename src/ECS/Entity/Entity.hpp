#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <map>
#include <string>
#include <typeindex>
#include <iostream>

class Component;

class Entity{
  public:
    Entity(){ static unsigned int id = 0; this->id = id++;}
    ~Entity();
    
    inline unsigned int getId() const { return this->id; }
    
    inline std::string getName() const { return this->name; }
    inline void setName(std::string name) { this->name = name; }
    
    inline void addComponent(std::type_index type, Component* c){ this->components[type] = c; }
    
    template<typename T>
    inline T* get(){
        auto iterator = components.find(std::type_index(typeid(T)));
        if(iterator != components.end()){
            return dynamic_cast<T*>(iterator->second);
        }

        return nullptr;
    }
    
    void dump();
    
  private:
    unsigned int id;
    std::string name;
    std::map<std::type_index, Component*> components;
};

#endif