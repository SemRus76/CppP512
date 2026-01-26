cmake_minimum_required(VERSION 3.26) # минимальная версия Cmake

set (oop_header
     example.h
)

set (oop_source
     example.cpp
)


add_library(oop_object OBJECT
            ${oop_header}
            ${oop_source}
            )

target_include_directories(oop_object PUBLIC .
                             ${oop_header})
