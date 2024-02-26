set(LIB_SOURCES ShuntingYard.cpp)

add_library(mycalc_lib ${LIB_SOURCES})

target_include_directories(mycalc_lib  PUBLIC ${CMAKE_SOURCE_DIR}/lib)
