#pragma once

#include "marky/Marky.h"
#include "marky/backend/html_backend.h"

#include <regex>
#include <gtest/gtest.h>

class HtmlGenerationTests : public ::testing::Test
{
protected:
    marky::backend::html::MarkdownToHtml m_html_backend;
    marky::Marky m_marky;
};

std::string empty_md = "";
TEST_F(HtmlGenerationTests, EmptyMarkdown_ProducesEmptyDiv)
{
    m_marky.process_markdown(m_html_backend, empty_md);
    auto html = m_html_backend.get_html();
    EXPECT_STREQ("<div></div>", html.c_str());
}

std::string one_p_md = "This is one paragraph";
TEST_F(HtmlGenerationTests, OneParagraphMarkdown_ProducesPElement)
{
    m_marky.process_markdown(m_html_backend, one_p_md);
    auto html = m_html_backend.get_html();

    std::regex regex(R"(<div><p>[\s]*This[\s]*is[\s]*one[\s]*paragraph[\s]*</p></div>)",
                          std::regex_constants::ECMAScript | std::regex_constants::icase);

    //EXPECT_STREQ("<div><p>This is one paragraph</p></div>", html.c_str());
    EXPECT_TRUE(std::regex_search(html, regex));
}