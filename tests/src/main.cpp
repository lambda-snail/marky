#include <gtest/gtest.h>

#include "parser_tests.h"
#include "html_tests.h"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}