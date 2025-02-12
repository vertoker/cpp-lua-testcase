
#project(CppLuaAppRes)

# Clean previous build
file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Set CMake build directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build) # /lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build) # /lib
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build) # /bin

# Try to separate .exe from .dll
#set(CMAKE_  ${CMAKE_CURRENT_SOURCE_DIR}/build FORCE)
#add_library(CppLua STATIC IMPORTED)
#install(TARGETS "${CMAKE_CURRENT_SOURCE_DIR}/build/bin/${CMAKE_PROJECT_NAME}.exe" DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)
#install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)
#set_property(TARGET CppLua PROPERTY IMPORTED_LOCATION c${CMAKE_CURRENT_SOURCE_DIR}/build)

# Make necessary directories
#file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
#file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
#file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/res)

# Copy resources
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)
