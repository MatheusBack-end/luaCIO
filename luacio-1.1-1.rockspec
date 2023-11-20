package = "luacio"
version = "1.1-1"
source = {
   url = "git://github.com/MatheusBack-end/luaCIO.git",
   tag = "v1.0"
}
description = {
   summary = "my first lib lua",
   detailed = [[
      a lib of io non-blocking.
   ]],
}
dependencies = {
   "lua >= 5.1, < 5.5"
}
build = {
   type = "builtin",
   modules = {}
}
