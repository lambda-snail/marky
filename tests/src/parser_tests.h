#pragma once

#include <antlr4-runtime.h>
#include "marky/parser/"

#include <gtest/gtest.h>

std::string header_one_level =
R"(
# This is a level one header
)";

std::string two_paragraphs =
R"(
This is a single paragraph. It should not count as 0 or 2 paragraphs.

This is another paragraph!
)";

std::string two_headers_two_paragraphs =
R"(
# This is a level one header
This is a single paragraph. It should not count as 0 or 2 paragraphs.
## This is a level two header
This is another paragraph!
)";


class GrammarTests : public ::testing::Test {
protected:

};

TEST_F(GrammarTests, Paragraphs_ShouldIgnoreBlankLines)
{
//    bool r = marky::parser::parse_string(two_paragraphs.begin(), two_paragraphs.end(), &v);
//
//    EXPECT_TRUE(r);
//    EXPECT_EQ(18, v.words);
}

//TEST_F(GrammarTests, Headers_LevelOneShouldParse)
//{
//    bool r = marky::parser::parse_string(header_one_level.begin(), header_one_level.end(), &v);
//
//    EXPECT_TRUE(r);
//    EXPECT_EQ(1, v.headers);
//    EXPECT_EQ(6, v.words);
//}
//
//TEST_F(GrammarTests, MixedHeadersParagraphs_ShouldParse)
//{
//    bool r = marky::parse_string(two_headers_two_paragraphs.begin(),
//                                 two_headers_two_paragraphs.end(),
//                                 &v);
//
//    EXPECT_TRUE(r);
//    EXPECT_EQ(2, v.paragraphs);
//    EXPECT_EQ(2, v.headers);
//    EXPECT_EQ(3, v.level);
//}
//
//TEST_F(GrammarTests, MixedHeadersParagraphs_WordsShouldNotDisappear)
//{
//    bool r = marky::parse_string(two_headers_two_paragraphs.begin(),
//                                 two_headers_two_paragraphs.end(),
//                                 &v);
//
//    EXPECT_TRUE(r);
//    EXPECT_EQ(30, v.words);
//}