function add(a, b)
    return a + b
end

function onInitialize()
    log.info("onInitialize - loglib")
end

function onDispose()
    log.info("onDispose - loglib")
end

print('Hi from Lua')
