cmake_minimum_required(VERSION 3.7)

project(testcpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# NOTE: The following would add library with absolute path
#       Which is bad for your projects cross-platform capabilities
#       Just let the linker search for it
#add_library(stdc++fs UNKNOWN IMPORTED)
#set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/gcc/x86_64-linux-gnu/7/libstdc++fs.a")

set(SOURCE_FILES test.cpp)
add_executable(testcpp ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} stdc++fs)