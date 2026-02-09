cmake_minimum_required(VERSION 3.26) # минимальная версия Cmake

set (oop_header
     example.h
     template_class.h
)

set (oop_source
     example.cpp
     template_class.cpp
)


add_library(oop_object OBJECT
            ${oop_header}
            ${oop_source}
            inheritance.h inheritance.cpp
            common.h
            )

target_include_directories(oop_object PUBLIC .
                             ${oop_header})
