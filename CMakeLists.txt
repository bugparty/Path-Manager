cmake_minimum_required(VERSION 3.3)
project(Path_Manager)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/actions.h
    include/dialogs.h
    include/document.h
    include/main.h
    include/resource.h
    include/stdafx.h
    include/targetver.h
    include/util.h
    src/actions.cpp
    src/dialogs.cpp
    src/document.cpp
    src/main.cpp
    src/stdafx.cpp
    src/util.cpp
    UnitTest/stdafx.cpp
    UnitTest/stdafx.h
    UnitTest/targetver.h
    UnitTest/unittest1.cpp)

add_executable(Path_Manager ${SOURCE_FILES})