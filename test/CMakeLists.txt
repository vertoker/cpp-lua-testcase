project(CppLuaTest)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

find_package(GTest)

add_executable(CppLuaTest ${SOURCES})

target_include_directories(CppLuaTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(CppLuaTest CppLua GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

# HACK: copy res to test/ folder for fixing problem compatibility MultiConfig
# and non MultiConfig builds. Delete in future and use only root res folder Also
# this resolve problem with ctests, because it set cwd to
# CMAKE_CURRENT_BINARY_DIR
#add_custom_command(
#    TARGET ${PROJECT_NAME}
#    POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
#            ${CMAKE_SOURCE_DIR}/res ${CMAKE_CURRENT_BINARY_DIR}/res)

include(GoogleTest)
#gtest_discover_tests(${PROJECT_NAME})
add_test(NAME CppLuaTest COMMAND CppLuaTest)