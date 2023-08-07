#pragma once

#include <marky/parser.h>

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



TEST(ParserTests, Paragraphs_ShouldIgnoreBlankLines)
{
    marky::markdown md;
    bool r = marky::parse_string(two_paragraphs.begin(), two_paragraphs.end(), md.items);

    EXPECT_TRUE(r);
    EXPECT_EQ(2, md.items.size());
}

TEST(ParserTests, Headers_LevelOneShouldParse)
{
    marky::markdown md;
    bool r = marky::parse_string(header_one_level.begin(), header_one_level.end(), md.items);

    EXPECT_TRUE(r);
    EXPECT_EQ(1, md.items.size());
}

//std::cout << md.items.size() << std::endl;
//
//for(auto const& p : md.items)
//{
//    for(auto const& w : p.items)
//    {
//        std::cout << w.text << " ";
//    }
//
//    std::cout << std::endl << std::endl;
//}