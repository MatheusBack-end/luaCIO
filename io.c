#include <unistd.h>
#include <fcntl.h>
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>

int read_non_blocking(lua_State *L)
{
  int buffer_size = luaL_checkint(L, 1);
  char buffer[buffer_size];

  memset(buffer, 0, sizeof(buffer));

  fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
  int ready = read(0, buffer, buffer_size);

  if(ready > 0)
  {
    lua_pushstring(L, buffer);
  }

  else
  {
    lua_pushnil(L);
  }

  return 1;
}

static const struct luaL_Reg functions [] =
{
  {"read_nb", read_non_blocking},
  {NULL, NULL}
};

int luaopen_luacio(lua_State *L)
{
  luaL_register(L, "luacio", functions);
  return 1;
}
