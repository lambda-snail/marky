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

std::string two_headers_two_paragraphs =
R"(
# This is a level one header
This is a single paragraph. It should not count as 0 or 2 paragraphs.
## This is a level two header
This is another paragraph!
)";

class test_visitor : public marky::markdown_visitor<>
{
public:
    int headers = 0;
    int paragraphs = 0;
    void visit_paragraph(marky::ast::paragraph const& p) override
    {
        ++paragraphs;
    }

    void visit_header(marky::ast::header const& h) override
    {
        ++headers;
    }
};

class ParserTests : public ::testing::Test {
public:

protected:
    test_visitor v;
};

TEST_F(ParserTests, Paragraphs_ShouldIgnoreBlankLines)
{
    bool r = marky::parse_string(two_paragraphs.begin(), two_paragraphs.end(), &v);

    EXPECT_TRUE(r);
    EXPECT_EQ(2, v.paragraphs);
}

TEST_F(ParserTests, Headers_LevelOneShouldParse)
{
    bool r = marky::parse_string(header_one_level.begin(), header_one_level.end(), &v);

    EXPECT_TRUE(r);
    EXPECT_EQ(1, v.headers);
}

TEST_F(ParserTests, MixedHeadersParagraphs_ShouldParse)
{
    bool r = marky::parse_string(two_headers_two_paragraphs.begin(),
                                 two_headers_two_paragraphs.end(),
                                 &v);

    EXPECT_TRUE(r);
    EXPECT_EQ(2, v.paragraphs);
    EXPECT_EQ(2, v.headers);
}