## C++ Lua Testcase

Study project for understanding, how to implement other language into C++.
Lua by many reasons is a best choice for me. This project provides next features

- Program can load and execute Lua scripts through `res/`, entry point - `main.lua`
- C++ backend provides some libraries (`luaL_Reg`) for Lua
    - `log.print(text)` - print string in console
    - `log.info(text)` - print `[I]` string in console
    - `log.warning(text)` - print `[W]` string in console
    - `log.error(text)` - print `[E]` string in console
    - `log.debug(text)` - print `[D]` string in console (works only in `NDEBUG`)
    - `script.load(filepath)` - load and execute `.lua` content, `filepath` must be relative to the `res/`.
Example: `script.load("test.lua")`
- C++ backend calls some functions (only in `main.lua`)
    - `function initialize()` - program started
    - `function dispose()` - program ends
    - `function add(a, b) ` - just for lulz

This is not a real app for any production in any case, just study how to use it

Useful links
- [5.4 Manual](https://www.lua.org/manual/5.4/manual.html)
- [Lua Case #1](https://www.aloneguid.uk/posts/2024/08/cpp-lua/)
- [Lua Case #2](https://github.com/MihailRis/VoxelEngine-Cpp)
