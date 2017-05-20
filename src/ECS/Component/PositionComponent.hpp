#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "Component.hpp"
 
class PositionComponent : public Component {
public:
    PositionComponent() { this->x = 0; this->y = 0; }
 
    inline void setX(const int x) {
        this->x = x;
    }
 
    inline void setY(const int y) {
        this->y = y;
    }
    
    inline int getX() const { return this->x; }
    inline int getY() const { return this->y; }

    inline virtual std::string dump() const { 
        std::stringstream ss;
        
        ss << "COMPONENT: " << typeid(this).name() << '\n';
        ss << "x: " << this->getX() << '\n';
        ss << "y: " << this->getY() << '\n';
        
        return ss.str();
    }
    
private:
    int x;
    int y;
};

#endif