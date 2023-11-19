
#include "lua/lua.hpp"

#include <iostream>

using namespace std;

static int add_op(lua_State *L)
{
    const int op1 = lua_tointeger(L, -2);
    const int op2 = lua_tointeger(L, -1);

    lua_pushinteger(L, op1 + op2);
    return 1;
}

int main()
{
    lua_State *L = luaL_newstate();
    lua_pushcfunction(L, &add_op);
    lua_pushinteger(L, 1);
    lua_pushinteger(L, 2);
    lua_call(L, 2, 1);

    const int result = lua_tointeger(L, -1);
    cout << result << endl;

    lua_pop(L, 1);

    lua_close(L);
    return 0;
}