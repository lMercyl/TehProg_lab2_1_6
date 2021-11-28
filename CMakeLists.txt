cmake_minimum_required(VERSION 3.20)
project(laba2)

set(CMAKE_CXX_STANDARD 23)

add_executable(laba2 main.cpp Worker.cpp Worker.h Keeper.cpp Keeper.h Item.h)
