cmake_minimum_required(VERSION 3.26)
project(drone)

set(CMAKE_CXX_STANDARD 17)

add_executable(drone main.cpp
        dato.cpp
        dato.h
)
