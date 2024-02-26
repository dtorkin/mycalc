cmake_minimum_required(VERSION 3.16.3)

project(mycalc)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE mycalc_lib)

install(TARGETS mycalc RUNTIME DESTINATION bin)


SET(CPACK_PACKAGE_DESCRIPTION_FILE ${CMAKE_SOURCE_DIR}/README.md)
SET(CPACK_PACKAGE_VENDOR "MIREA")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "dtorkin")
SET(CPACK_CMAKE_GENERATOR Ninja)
set(CPACK_RPM_SPEC_MORE_DEFINE "%define _build_id_links none")


include(CPack)
