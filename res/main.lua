print('Hi from Lua')

function add(a, b)
    return a + b
end

function onInitialize()
    print("initialize")
end

function onDispose()
    print("dispose")
end
