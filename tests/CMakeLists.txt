
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(marky_tests
        src/main.cpp
        src/parser_tests.h
        src/html_tests.h)

include_directories(marky_tests PRIVATE src)

target_link_libraries(marky_tests
        PRIVATE
        GTest::GTest
        marky)

add_test(marky_gtests multiply_test)