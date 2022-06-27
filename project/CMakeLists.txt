cmake_minimum_required(VERSION 3.21)
project(Calc)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/doctest)
add_executable(calc_test main.cpp tests.cpp funcs.cpp)
target_link_libraries(calc_test doctest)
add_test(NAME test COMMAND test --force-colors -d)
add_custom_target(cloud-test COMMAND test --force-colors -d)

add_executable(CalcApp main.cpp funcs.cpp funcs.h)
target_link_libraries(CalcApp)
