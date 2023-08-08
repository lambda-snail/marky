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


class my_visitor : public marky::markdown_visitor<>
{
public:
    void visit_paragraph(marky::paragraph const& p) const override
    {
        std::cout << p.items.size() << std::endl;
    }

    void visit_header(marky::header const& h) const override
    {
        std::cout << h.items.size() << std::endl;
    }
};


TEST(ParserTests, Paragraphs_ShouldIgnoreBlankLines)
{
    marky::markdown md;
    my_visitor v;
    bool r = marky::parse_string(two_paragraphs.begin(), two_paragraphs.end(), md.items, &v);

    EXPECT_TRUE(r);
    EXPECT_EQ(2, md.items.size());
}

TEST(ParserTests, Headers_LevelOneShouldParse)
{
    testing::internal::CaptureStdout();

    marky::markdown md;
    my_visitor v;
    bool r = marky::parse_string(header_one_level.begin(), header_one_level.end(), md.items, &v);

    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output << std::endl;

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