#pragma once

#include <antlr4-runtime.h>
#include "marky/parser/MarkdownLexer.h"
#include "marky/parser/MarkdownParser.h"
#include "marky/parser/MarkdownBaseListener.h"

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
    void runWithListener(std::string markdown, marky::MarkdownBaseListener const* listener)
    {
        antlr4::ANTLRInputStream input(markdown);
        marky::MarkdownLexer lexer(&input);

        antlr4::CommonTokenStream tokens(&lexer);
        marky::MarkdownParser parser(&tokens);

        auto* tree = parser.markdown();
        //antlr4::tree::ParseTreeWalker::DEFAULT.walk(const_cast<antlr4::tree::ParseTreeListener *>(listener), tree);
        antlr4::tree::ParseTreeWalker::DEFAULT.walk((antlr4::tree::ParseTreeListener *)listener, tree);
    }
};

TEST_F(GrammarTests, Paragraphs_ShouldIgnoreBlankLines)
{
    class TestListener : public marky::MarkdownBaseListener {
        public:
        int num = 0;
        void enterHeader(marky::MarkdownParser::HeaderContext* ctx) override
        {
            ++num;
        }

        void visitTerminal(antlr4::tree::TerminalNode *node) override { };
        void visitErrorNode(antlr4::tree::ErrorNode *node) override { };
        void enterEveryRule(antlr4::ParserRuleContext *ctx) override { };
        void exitEveryRule(antlr4::ParserRuleContext *ctx) override { };

    } listener;

    runWithListener(two_paragraphs, &listener);

    EXPECT_EQ(2, listener.num);
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