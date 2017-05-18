#include "LuaHelperFunctions.hpp"


void luah::stackdump_g(lua_State* l)
{
    int i;
    int top = lua_gettop(l);
 
    printf("total in stack %d\n",top);
 
    for (i = 1; i <= top; i++)
    {  /* repeat for each level */
        int t = lua_type(l, i);
        switch (t) {
            case LUA_TSTRING:  /* strings */
                printf("string: '%s'\n", lua_tostring(l, i));
                break;
            case LUA_TBOOLEAN:  /* booleans */
                printf("boolean %s\n",lua_toboolean(l, i) ? "true" : "false");
                break;
            case LUA_TNUMBER:  /* numbers */
                printf("number: %g\n", lua_tonumber(l, i));
                break;
            default:  /* other values */
                printf("%s\n", lua_typename(l, t));
                break;
        }
        printf("  ");  /* put a separator */
    }
    printf("\n");  /* end the listing */
}

bool luah::loadScript(lua_State* L, const std::string& filename){
  int result = luaL_dofile(L, filename.c_str()); //If you do loadfile, you will have to prime it with an empty pcall

  if (result != LUA_OK ) {
    std::cout << "Could not open file " << filename << std::endl;
    lua_pop(L,1);
    return false;
  }
  
  return true;
}

void luah::loadGetKeysFunction(lua_State* L) {
    std::string code =
        R"(function getKeys(t)
        if t == nil then return nil end
        s = {}
        for k, v in pairs(t) do
            table.insert(s, k)
            end 
        return s 
        end)";
    luaL_dostring(L, code.c_str());
}

std::vector<std::string> luah::getTableKeys(lua_State* L, const std::string& name) {
    lua_getglobal(L, "getKeys"); // get function
    if (lua_isnil(L, -1)) {
        std::cout << "Get keys function is not loaded. Loading..." << std::endl;
        loadGetKeysFunction(L);
        lua_getglobal(L, "getKeys");
    }
    
    lua_gettostack(L, name.c_str());
    
    lua_pcall(L, 1, 1, 0); // execute getKeys function.
    lua_pushnil(L);
    
    // One parameter, one return
    std::vector<std::string> keys;

    while (lua_next(L, -2)) { // get values one by one
        if (lua_type(L, -1) == LUA_TSTRING) { // check if key is a string
            keys.push_back(lua_tostring(L, -1));
        }
        
        lua_pop(L, 1);
    }
    lua_settop(L, 0); // remove s table from stack 
    return keys;
}

void luah::lua_gettostack(lua_State* L, const std::string& variableName) {
    int level = 0;
    std::string var = "";
    
    for (unsigned int i = 0; i < variableName.size(); i++) {
        
        if (variableName.at(i) == '.') {
            if (level == 0) {
                lua_getglobal(L, var.c_str());
            } else {
                lua_getfield(L, -1, var.c_str());
            }
 
            if (lua_isnil(L, -1)) {
                std::cout << "Error, can't get " << variableName << std::endl;
                return;
            } else {
                var = "";
                level++;
            }
        } else {
            var += variableName.at(i);
        }
    }

    if (level == 0) {
        lua_getglobal(L, var.c_str());
    } else {
        lua_getfield(L, -1, var.c_str());
    }


    if (level == 0) { return; } // no need to remove anything

    int tableIndex = lua_gettop(L) - level;
    lua_replace(L, tableIndex);
    lua_settop(L, tableIndex);
}