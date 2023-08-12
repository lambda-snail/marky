#include "marky/backend/html_backend.h"

#include <antlr4-runtime.h>

#include "marky/parser/MarkdownLexer.h"
#include "marky/parser/MarkdownParser.h"
#include "marky/parser/MarkdownBaseListener.h"





marky::compiler::html::MarkdownToHtml::MarkdownToHtml(std::string_view markdown)
{
    antlr4::ANTLRInputStream input(markdown);
    marky::MarkdownLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);
    marky::MarkdownParser parser(&tokens);

    auto* tree = parser.markdown();
   // antlr4::tree::ParseTreeWalker::DEFAULT.walk((antlr4::tree::ParseTreeListener *)listener, tree);
}
