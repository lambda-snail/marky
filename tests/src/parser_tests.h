#pragma once

#include <marky/parser.h>

#include <gtest/gtest.h>

std::string two_paragraphs =
R"(
This is a single paragraph. It should not count as 0 or 2 paragraphs.

This is another paragraph!
)";



TEST(ParserTests, Paragraphs_ShouldIgnoreBlankLines)
{
    marky::markdown md;
    bool r = marky::parse_string(two_paragraphs.begin(), two_paragraphs.end(), md);

    EXPECT_TRUE(r);
    EXPECT_EQ(2, md.items.size());
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