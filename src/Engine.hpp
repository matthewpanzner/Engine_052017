#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Include/Engine_052017.hpp"
#include <vector>

class Engine{
public:
    Engine(){}
    ~Engine(){}
    
    void run();
    
private:
    
    void initialize();
    void mainLoop();
    void processInput();
    void update();
    void render();
    
private:
    bool running = true;
    
    std::vector<System> systems;

};

#endif