cmake_minimum_required(VERSION 3.26)

set(INCLUDE_TESTS 1)
set(MARKY_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 20)

include(CImportDependencies.txt)

#find_package(Boost 1.82 COMPONENTS spirit fusion REQUIRED)

project(marky)

include_directories(marky
        PUBLIC
        include
        ${antlr_SOURCE_DIR}/runtime/Cpp/runtime/src
)


add_library(marky
        include/marky/parser.h
        src/parser.cpp)

enable_testing()
add_subdirectory(tests)

target_link_libraries(marky PUBLIC antlr4_static)

#include_directories(marky PRIVATE ${boost_SOURCE_DIR}/)