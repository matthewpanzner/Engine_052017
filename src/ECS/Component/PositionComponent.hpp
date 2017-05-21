#ifndef POSITION_COMPONENT_HPP
#define POSITION_COMPONENT_HPP

#include "Component.hpp"

#include <typeinfo>
 
class PositionComponent : public Component {
public:
    PositionComponent();
 
    inline void setX(const double x) {
        this->x = x;
    }
 
    inline void setY(const double y) {
        this->y = y;
    }
    
    inline double getX() const { return this->x; }
    inline double getY() const { return this->y; }

    inline virtual std::string dump() const { 
        std::stringstream ss;
        
        ss << "COMPONENT: " << typeid(this).name() << '\n';
        ss << "x: " << this->getX() << '\n';
        ss << "y: " << this->getY() << '\n';
        
        return ss.str();
    }
    
private:
    double x;
    double y;
};

#endif