cmake_minimum_required(VERSION 3.22.1)
project(syde223_a4)

set(CMAKE_CXX_STANDARD 11)

# Add debugging symbols
set(CMAKE_BUILD_TYPE Debug)

# Include source and header files
add_executable(syde223_a4
    main.cpp
    Trie.cpp
)

# Add include directories
include_directories(src tests)
