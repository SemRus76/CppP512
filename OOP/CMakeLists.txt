cmake_minimum_required(VERSION 3.26) # минимальная версия Cmake

set (oop_header
     example.h
     template_class.h
     inheritance.h
     abastract_class.h
     common.h
)

set (oop_source
     example.cpp
     template_class.cpp
     abastract_class.cpp
     inheritance.cpp
)


add_library(oop_object OBJECT
            ${oop_header}
            ${oop_source}
            multiple_inheritce.h multiple_inheritce.cpp
            )

target_include_directories(oop_object PUBLIC .
                             ${oop_header})
