cmake_minimum_required(VERSION 3.26)
project(Bookshelf_v01_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bookshelf_v01_cpp main.cpp
        Menu.cpp
        Menu.h
        LibraryManagement.cpp
        LibraryManagement.h
)
