cmake_minimum_required(VERSION 3.26) # минимальная версия Cmake

#set(CMAKE_BUILD_TYPE Relase)
project(Les LANGUAGES C CXX)

# find_package(Qt6 REQUIRED COMPONENTS Core)

# Настройка стандартов
set(CMAKE_CXX_STANDARD 17)

# Поиск библиотеки libnl
# find_package(PkgConfig REQUIRED)
# pkg_check_modules(LIBNL REQUIRED libnl-3.0 libnl-route-3.0)

add_subdirectory(data_struct)

# Добавление исполняемого файла
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE DataStruct)
target_include_directories(${PROJECT_NAME} PRIVATE DataStruct)

# target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_FLAGS "-Wall -Wextra -Wpedantic")

# Подключение библиотек

