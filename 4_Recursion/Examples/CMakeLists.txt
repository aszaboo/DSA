cmake_minimum_required(VERSION 3.22)
project(fibonacci)

# enable c++11 support
set (CMAKE_CXX_FLAGS "-std=c++14 -Wall ${CMAKE_CXX_FLAGS}")

# create the main executable
## add additional .cpp files if needed
add_executable(fibonacci
        fibonacci.cpp)

add_executable(factorial
        factorial.cpp)

add_executable(hanoi
        hanoi-tower.cpp)