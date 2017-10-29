cmake_minimum_required(VERSION 3.8)
project(ADTList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Adt_List_Sequence.h Adt_List_L.h)
add_executable(ADTList ${SOURCE_FILES})