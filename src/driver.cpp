#include <iostream>
#include "Engine.hpp"

int main(){
    Engine* engine = new Engine();
    
    try{
        engine->run();
    }
    catch(const char* e){
        std::cout << e << std::endl;
    }
    
    return 0;
}