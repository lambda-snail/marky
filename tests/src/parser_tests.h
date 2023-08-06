#pragma once

#include <marky/parser.h>

#include <gtest/gtest.h>

TEST(ParserTests, TestParse)
{
    std::string str =
R"(
This is a single paragraph. It should not count as 0 or 2 paragraphs.

This is another paragraph!
)";

    testing::internal::CaptureStdout();
    marky::parse_string(str.begin(), str.end());
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("2", output);
}
