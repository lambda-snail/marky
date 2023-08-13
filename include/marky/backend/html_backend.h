#pragma once

#include "marky/parser/MarkdownBaseListener.h"

#include <string>

namespace marky::backend::html
{
    class MarkdownToHtml : public marky::MarkdownBaseListener
    {
    public:
        std::string get_html();

        void enterMarkdown(MarkdownParser::MarkdownContext * /*ctx*/) override;
        void exitMarkdown(MarkdownParser::MarkdownContext *  /*ctx*/) override;

        //void enterBlock(MarkdownParser::BlockContext * /*ctx*/) override;
        //void enterRaw_stream(MarkdownParser::Raw_streamContext * /*ctx*/) override;
        //void enterItalics_stream(MarkdownParser::Italics_streamContext * /*ctx*/) override;
        //void enterBold_stream(MarkdownParser::Bold_streamContext * /*ctx*/) override;
        //void enterW_stream(MarkdownParser::W_streamContext * /*ctx*/) override;

        void enterHeader(MarkdownParser::HeaderContext * /*ctx*/) override;
        void exitHeader(MarkdownParser::HeaderContext *  /*ctx*/) override;

        void enterParagraph(MarkdownParser::ParagraphContext * /*ctx*/) override;
        void exitParagraph(MarkdownParser::ParagraphContext *  /*ctx*/) override;

        void visitTerminal(antlr4::tree::TerminalNode *) override;

        static constexpr int HTML_MaxHeaderLevel { 6 };
    private:
        std::vector<std::string> m_elements;
    };
}