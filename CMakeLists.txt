cmake_minimum_required(VERSION 3.27)
project(SomeStuff C)

set(CMAKE_C_STANDARD 11)

add_executable(SomeStuff main.c
        arena.c
        arena.h
)
