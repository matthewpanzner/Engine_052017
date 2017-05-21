#include "Engine.hpp"

#include <iostream>

void Engine::run(){
    this->initialize();
    
    while(running){
        this->mainLoop();
        this->running = false;
    }
}

void Engine::initialize(){
    std::cout << "Initializing" << std::endl;
}

void Engine::mainLoop(){
    this->processInput();
    this->update();
    this->render();
}

void Engine::processInput(){
    std::cout << "Processing Input" << std::endl;
}

void Engine::update(){
    std::cout << "Updating" << std::endl;   
}

void Engine::render(){
    std::cout << "Rendering" << std::endl;
}