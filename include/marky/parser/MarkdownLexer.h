
// Generated from .\Markdown.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"


namespace marky {


class  MarkdownLexer : public antlr4::Lexer {
public:
  enum {
    HEADER_START = 1, BLANK = 2, EOL = 3, WHITESPACE = 4, WORD = 5, BOLD_ENVELOPE = 6, 
    ITALICS_ENVELOPE = 7
  };

  explicit MarkdownLexer(antlr4::CharStream *input);

  ~MarkdownLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace marky
