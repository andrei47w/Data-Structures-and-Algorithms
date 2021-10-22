cmake_minimum_required(VERSION 3.17)
project(SDA_Set)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SDA_Set
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h)
