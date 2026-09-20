cmake_minimum_required(VERSION 3.20)
project(gradebook LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(library
    src/utilities.cpp
    src/grading.cpp
    src/printing.cpp
    )
target_include_directories(library PUBLIC include)

add_executable(gradebook app/main.cpp)
target_link_libraries(gradebook PRIVATE library)
