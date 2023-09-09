#pragma once

#include "marky/Marky.h"
#include "marky/backend/html_backend.h"

#include <regex>
#include <gtest/gtest.h>

struct TestParams
{
    std::string input;
    std::string expected_regex;
};

class HtmlGenerationTests : public ::testing::TestWithParam<TestParams>
{
public:
    HtmlGenerationTests()
    {
        m_html_backend = std::make_unique<marky::backend::html::MarkdownToHtml>();
    }
protected:
    std::unique_ptr<marky::backend::html::MarkdownToHtml> m_html_backend;
    marky::Marky m_marky;
};

INSTANTIATE_TEST_SUITE_P(HtmlGenerationTests,
                         HtmlGenerationTests,
                         testing::Values(

TestParams { "", "<div></div>" },
TestParams { "This is one paragraph", R"(<div><p>[\s]*This[\s]*is[\s]*one[\s]*paragraph[\s]*</p></div>)" }, // Test single paragraph
TestParams { "Paragraph 1\nParagraph 2", R"(<div><p>[\s]*Paragraph[\s]*1[\s]*</p><p>[\s]*Paragraph[\s]*2[\s]*</p></div>)" }, // Test multiple paragraphs

TestParams { "# This is one header", R"(<div><h1>[\s]*This[\s]*is[\s]*one[\s]*header[\s]*</h1></div>)" },
TestParams { "## This is one header", R"(<div><h2>[\s]*This[\s]*is[\s]*one[\s]*header[\s]*</h2></div>)" },
TestParams { "###### This is one header", R"(<div><h6>[\s]*This[\s]*is[\s]*one[\s]*header[\s]*</h6></div>)" }, // Max header level works
TestParams { "####### This is one header", R"(<div><p>[\s]*This[\s]*is[\s]*one[\s]*header[\s]*</p></div>)" }, // Levels higher than max become paragraphs

TestParams { "This is one _italic_ paragraph", R"(<div><p>[\s]*This[\s]*is[\s]*one[\s]*<i>[\s]*italic[\s]*</i>paragraph[\s]*</p></div>)" },
TestParams { "This is one *bold* paragraph", R"(<div><p>[\s]*This[\s]*is[\s]*one[\s]*<b>[\s]*bold[\s]*</b>paragraph[\s]*</p></div>)" }
));

TEST_P(HtmlGenerationTests, GeneratedHtml_ShouldMatchMarkdown)
{
    auto [markdown, html_regex] = GetParam();
    m_marky.process_markdown(m_html_backend.get(), markdown);
    auto html = m_html_backend->get_html();

    std::regex regex(html_regex, std::regex_constants::ECMAScript | std::regex_constants::icase);
    EXPECT_TRUE(std::regex_search(html, regex));
}

TEST_P(HtmlGenerationTests, ParsingOperation_ShouldBeIdempotent)
{
    auto [markdown, html_regex] = GetParam();
    m_marky.process_markdown(m_html_backend.get(), markdown);

    auto html1 = m_html_backend->get_html();
    auto html2 = m_html_backend->get_html();

    EXPECT_TRUE(std::equal(html1.begin(), html1.end(), html2.begin()));
}
