cmake_minimum_required(VERSION 3.16.3)
project(tests)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)


enable_testing()

add_executable(${PROJECT_NAME} hello_test.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE mycalc_lib  gtest)

include(GoogleTest)
gtest_discover_tests(tests)
