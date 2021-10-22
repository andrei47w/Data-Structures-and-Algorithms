cmake_minimum_required(VERSION 3.17.5)
project(DSA_lab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DSA_lab2
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h
        SortedIndexedList.h
        SortedIndexeList.cpp Node.h)
