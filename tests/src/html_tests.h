#pragma once

#include "marky/Marky.h"
#include "marky/backend/html_backend.h"

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
