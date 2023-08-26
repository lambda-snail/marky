#include "marky/Marky.h"

#include "marky/parser/MarkdownListener.h"
#include "marky/parser/MarkdownLexer.h"

void marky::Marky::process_markdown(marky::MarkdownListener* backend, std::string_view markdown) const {
    antlr4::ANTLRInputStream input(markdown);
    marky::MarkdownLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);
    marky::MarkdownParser parser(&tokens);

    auto* tree = parser.markdown();
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(backend, tree);
}
