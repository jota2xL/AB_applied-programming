cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(AB_applied programming)

# Incluir directorios de encabezados
include_directories(model util)

# Archivos fuente del proyecto
file(GLOB SOURCES 
    main.cpp 
    impl/*.cpp
)

# Crear el ejecutable
add_executable(AB ${SOURCES})
