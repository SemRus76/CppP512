cmake_minimum_required(VERSION 3.26) # минимальная версия Cmake

set (data_struct_header
        list.h
        stack.h
        queue.h
        vector.h
        set.h
)

set (data_struct_source
        list.cpp
        stack.cpp
        queue.cpp
        vector.cpp
        set.cpp
)


add_library(DataStruct_object OBJECT
                ${data_struct_header}
                ${data_struct_source}
            )

target_include_directories(DataStruct_object PUBLIC .
                             ${data_struct_header})
