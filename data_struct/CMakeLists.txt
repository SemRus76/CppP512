cmake_minimum_required(VERSION 3.26) # минимальная версия Cmake


add_library(DataStruct OBJECT
                list.h  list.cpp
                stack.h stack.cpp
                queue.h queue.cpp
                vector.h vector.cpp
                set.h set.cpp
            )

target_include_directories(DataStruct PUBLIC .
                             ${data_struct_header})
