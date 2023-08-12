cmake_minimum_required(VERSION 3.26)

set(INCLUDE_TESTS 1)
set(MARKY_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 20)

include(CImportDependencies.txt)


project(marky)

include_directories(marky
        PUBLIC
        include
        ${antlr_SOURCE_DIR}/runtime/Cpp/runtime/src
        PRIVATE
        include/marky/parser
)


add_library(marky
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
        src/generated/MarkdownVisitor.cpp)

enable_testing()
add_subdirectory(tests)

target_link_libraries(marky PUBLIC antlr4_static)

#include_directories(marky PRIVATE ${boost_SOURCE_DIR}/)