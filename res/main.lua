function add(a, b)
    return a + b
end

function onInitialize()
    log.info("onInitialize - loglib")
    script.load("test.lua")
end

function onDispose()
    log.info("onDispose - loglib")
end

print('Hi from Lua')
