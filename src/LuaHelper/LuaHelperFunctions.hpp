#ifndef LUA_HELPER_FUNCTIONS_HPP
#define LUA_HELPER_FUNCTIONS_HPP

#include <lua.hpp>

extern "C" {
  #include <lua.h>
}

#include <vector>
#include <string>
#include <iostream>

struct lua_State;
 
namespace luah {
    void stackdump_g(lua_State* l);
    bool loadScript(lua_State* L, const std::string& filename);
    void lua_gettostack(lua_State* L, const std::string& variableName);
    void loadGetKeysFunction(lua_State* L); 
    std::vector<std::string> getTableKeys(lua_State* L, const std::string& name);
}

#endif