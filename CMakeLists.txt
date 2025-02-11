#--------------------------------------------------------------------------------
# Init
#--------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.20)
project(CppLua)

option(CPPLUA_BUILD_APPDIR "" OFF)
option(CPPLUA_BUILD_TESTS "" OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#--------------------------------------------------------------------------------
# Src & Include
#--------------------------------------------------------------------------------

# Variables
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Recurse collect every file in include/ and src/ folders
file(GLOB_RECURSE INCLUDES CONFIGURE_DEPENDS "${INCLUDE_DIR}/*.h" "${INCLUDE_DIR}/*.hpp")
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${SOURCE_DIR}/*.c" "${SOURCE_DIR}/*.cpp")

# add include/ folder as root for all header files
include_directories("${INCLUDE_DIR}")

# finally add all founded include/ and src/ files into compiler as a program
add_executable("${CMAKE_PROJECT_NAME}" "${INCLUDES}" "${SOURCES}")

#file(GLOB_RECURSE SOURCES CMAKE_CONFIGURE_DEPENDS "src/*.h" "src/*.c" "src/*.hpp" "src/*.cpp")
#add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
