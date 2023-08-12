#pragma once

#include <string>

namespace marky::compiler::html
{
    class MarkdownToHtml
    {
    public:
        explicit MarkdownToHtml(std::string_view markdown);
        //MarkdownToHtml(MarkdownToHtml const & rhs) = default;
        //MarkdownToHtml(MarkdownToHtml && rhs) = default;
    };
}