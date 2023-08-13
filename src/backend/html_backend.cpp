#include "marky/backend/html_backend.h"

#include <antlr4-runtime.h>
#include <numeric>

#include "marky/parser/MarkdownLexer.h"
#include "marky/parser/MarkdownParser.h"
#include "marky/parser/MarkdownBaseListener.h"


void marky::backend::html::MarkdownToHtml::enterParagraph(marky::MarkdownParser::ParagraphContext* context) {
    m_elements.emplace_back("<p>");
}

void marky::backend::html::MarkdownToHtml::exitParagraph(marky::MarkdownParser::ParagraphContext *) {
    m_elements.emplace_back("</p>");
}

void marky::backend::html::MarkdownToHtml::enterMarkdown(marky::MarkdownParser::MarkdownContext *) {
    m_elements.emplace_back("<div>");
}

void marky::backend::html::MarkdownToHtml::exitMarkdown(marky::MarkdownParser::MarkdownContext *) {
    m_elements.emplace_back("</div>");
}

std::string marky::backend::html::MarkdownToHtml::get_html() {
    std::string html;
    const int reserve_length = std::accumulate(
            m_elements.begin(),
            m_elements.end(),
            0,
            [](int a, std::string const& w) { return a + w.length(); });
    html.reserve(reserve_length);

    for(auto const& elm : m_elements)
    {
        html += elm;
    }

    return html;
}

void marky::backend::html::MarkdownToHtml::visitTerminal(antlr4::tree::TerminalNode* node) {
    auto token = node->getSymbol();
    switch(token->getType())
    {
        case MarkdownLexer::WORD:
            m_elements.emplace_back(node->getText());
            m_elements.emplace_back(" ");
    };
}
