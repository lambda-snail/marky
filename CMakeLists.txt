cmake_minimum_required(VERSION 3.26)

set(INCLUDE_TESTS 1)
set(MARKY_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 20)

include(CImportDependencies.txt)

find_package(Boost 1.82 COMPONENTS spirit fusion REQUIRED)

project(marky)

include_directories(marky PUBLIC include)

add_library(marky
        src/library.cpp
        include/marky/parser.h)

enable_testing()
add_subdirectory(tests)

target_link_libraries(marky PUBLIC Boost::spirit Boost::fusion)

#include_directories(marky PRIVATE ${boost_SOURCE_DIR}/)