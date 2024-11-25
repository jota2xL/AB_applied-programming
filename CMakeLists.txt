# CMakeList.txt: proyecto de CMake para AB_Programming, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

# Habilite Recarga activa para los compiladores de MSVC si se admiten.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AB_Programming")
include_directories(model util)
# Agregue un origen al ejecutable de este proyecto.
add_executable (AB_Programming "AB_Programming.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AB_Programming PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
# Incluir directorios de encabezados
