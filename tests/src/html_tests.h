#pragma once

#include <gtest/gtest.h>

#include "marky/backend/html_backend.h"

class HtmlTests : public ::testing::Test
{
protected:
    std::unique_ptr<marky::compiler::html::MarkdownToHtml> mp_html;

    void init(std::string const& markdown)
    {
        mp_html = std::make_unique<marky::compiler::html::MarkdownToHtml>(new marky::compiler::html::MarkdownToHtml(markdown));
    }

    ~HtmlTests() override = default;
};