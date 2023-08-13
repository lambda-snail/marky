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
protected:
    marky::backend::html::MarkdownToHtml m_html_backend;
    marky::Marky m_marky;
};

INSTANTIATE_TEST_SUITE_P(HtmlGenerationTests,
                         HtmlGenerationTests,
                         testing::Values(

TestParams { "", "<div></div>" },
TestParams { "This is one paragraph", R"(<div><p>[\s]*This[\s]*is[\s]*one[\s]*paragraph[\s]*</p></div>)" },
TestParams { "# This is one header", R"(<div><h1>[\s]*This[\s]*is[\s]*one[\s]*header[\s]*</h1></div>)" }

));

TEST_P(HtmlGenerationTests, EmptyMarkdown_ProducesEmptyDiv)
{
    auto [markdown, html_regex] = GetParam();
    m_marky.process_markdown(m_html_backend, markdown);
    auto html = m_html_backend.get_html();

    std::regex regex(html_regex, std::regex_constants::ECMAScript | std::regex_constants::icase);
    EXPECT_TRUE(std::regex_search(html, regex));
}

//
