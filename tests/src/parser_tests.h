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

std::string header_three_level =
R"(
### This is a level one header
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

std::string code_block_string =
R"(
# This is a level one header
This is a single paragraph. It contains `one code segment`

`This is a code block. It should not count as an inline code segment`
)";

class GrammarTests : public ::testing::Test {
protected:
    void runWithListener(std::string const& markdown, marky::MarkdownBaseListener* listener)
    {
        antlr4::ANTLRInputStream input(markdown);
        marky::MarkdownLexer lexer(&input);

        antlr4::CommonTokenStream tokens(&lexer);
        marky::MarkdownParser parser(&tokens);

        auto* tree = parser.markdown();
        antlr4::tree::ParseTreeWalker::DEFAULT.walk((antlr4::tree::ParseTreeListener *)listener, tree);
    }
};

TEST_F(GrammarTests, Paragraphs_ShouldParseParagraphs)
{
    class TestListener : public marky::MarkdownBaseListener {
        public:
        int num = 0;
        void enterParagraph(marky::MarkdownParser::ParagraphContext *) override
        {
            ++num;
        }
    } listener;

    runWithListener(two_paragraphs, &listener);

    EXPECT_EQ(2, listener.num);
}

TEST_F(GrammarTests, Headers_LevelOneShouldParse)
{
    class TestListener : public marky::MarkdownBaseListener {
    public:
        int num = 0;
        int level = 0;
        void enterHeader(marky::MarkdownParser::HeaderContext* ctx) override
        {
            ++num;
            level = static_cast<int>(ctx->HEADER_START().size());
        }
    } listener;

    runWithListener(header_one_level, &listener);

    EXPECT_EQ(1, listener.num);
    EXPECT_EQ(1, listener.level);
}

TEST_F(GrammarTests, Headers_ShouldCountLevelsCorrectly)
{
    class TestListener : public marky::MarkdownBaseListener {
    public:
        int levels = 0;
        void enterHeader(marky::MarkdownParser::HeaderContext* ctx) override
        {
            levels = static_cast<int>(ctx->HEADER_START().size());
        }
    } listener;

    runWithListener(header_three_level, &listener);

    EXPECT_EQ(3, listener.levels);
}

TEST_F(GrammarTests, General_ShouldParseMixedHeadersAndParagraphs)
{
    class TestListener : public marky::MarkdownBaseListener {
    public:
        int headers = 0;
        void enterHeader(marky::MarkdownParser::HeaderContext* ctx) override
        {
            ++headers;
        }

        int num = 0;

        void enterParagraph(marky::MarkdownParser::ParagraphContext *) override
        {
            ++num;
        }
    } listener;

    runWithListener(two_headers_two_paragraphs, &listener);

    EXPECT_EQ(2, listener.num);
    EXPECT_EQ(2, listener.headers);
}

TEST_F(GrammarTests, General_ShouldParseInlineCode)
{
    class TestListener : public marky::MarkdownBaseListener {
    public:
        int code_segments = 0;
        void enterCode_stream_inl(marky::MarkdownParser::Code_stream_inlContext* ctx) override
        {
            ++code_segments;
        }
    } listener;

    runWithListener(code_block_string, &listener);

    EXPECT_EQ(1, listener.code_segments);
}

TEST_F(GrammarTests, General_ShouldParseCodeBlock)
{
    class TestListener : public marky::MarkdownBaseListener {
    public:
        int code_blocks = 0;
        void enterCode_stream_blk(marky::MarkdownParser::Code_stream_blkContext* ctx) override
        {
            ++code_blocks;
        }
    } listener;

    runWithListener(code_block_string, &listener);

    EXPECT_EQ(1, listener.code_blocks);
}