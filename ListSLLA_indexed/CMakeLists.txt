cmake_minimum_required(VERSION 3.17)
project(ListSLLA_indexed)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ListSLLA_indexed
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IteratedList.cpp
        IteratedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
