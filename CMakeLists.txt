cmake_minimum_required(VERSION 3.26)

option(INCLUDE_TESTS "marky building with tests" ON)

set(MARKY_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include(CImportDependencies.txt)

project(marky VERSION 0.3.4)

set(marky_ANTLR_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include ${antlr_SOURCE_DIR}/runtime/Cpp/runtime/src)

include_directories(marky
        PUBLIC
        include
        ${antlr_SOURCE_DIR}/runtime/Cpp/runtime/src
        PRIVATE
        include/marky/parser
)

add_library(marky STATIC
        include/marky/parser/MarkdownBaseListener.h
        include/marky/parser/MarkdownBaseVisitor.h
        include/marky/parser/MarkdownLexer.h
        include/marky/parser/MarkdownListener.h
        include/marky/parser/MarkdownParser.h
        include/marky/parser/MarkdownVisitor.h

        src/generated/MarkdownBaseListener.cpp
        src/generated/MarkdownBaseVisitor.cpp
        src/generated/MarkdownLexer.cpp
        src/generated/MarkdownListener.cpp
        src/generated/MarkdownParser.cpp
        src/generated/MarkdownVisitor.cpp
        include/marky/backend/html_backend.h
        src/backend/html_backend.cpp
        include/marky/Marky.h
        src/Marky.cpp
)

enable_testing()
add_subdirectory(tests)

target_link_libraries(marky PUBLIC antlr4_static)

#include_directories(marky PRIVATE ${boost_SOURCE_DIR}/)