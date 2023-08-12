
// Generated from .\Markdown.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"


namespace marky {


class  MarkdownParser : public antlr4::Parser {
public:
  enum {
    HEADER_START = 1, BLANK = 2, EOL = 3, WHITESPACE = 4, WORD = 5, BOLD_ENVELOPE = 6, 
    ITALICS_ENVELOPE = 7
  };

  enum {
    RuleMarkdown = 0, RuleBlock = 1, RuleRaw_stream = 2, RuleItalics_stream = 3, 
    RuleBold_stream = 4, RuleW_stream = 5, RuleHeader = 6
  };

  explicit MarkdownParser(antlr4::TokenStream *input);

  MarkdownParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MarkdownParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MarkdownContext;
  class BlockContext;
  class Raw_streamContext;
  class Italics_streamContext;
  class Bold_streamContext;
  class W_streamContext;
  class HeaderContext; 

  class  MarkdownContext : public antlr4::ParserRuleContext {
  public:
    MarkdownContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MarkdownContext* markdown();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    W_streamContext *w_stream();
    HeaderContext *header();
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  Raw_streamContext : public antlr4::ParserRuleContext {
  public:
    Raw_streamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BLANK();
    antlr4::tree::TerminalNode* BLANK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Raw_streamContext* raw_stream();

  class  Italics_streamContext : public antlr4::ParserRuleContext {
  public:
    Italics_streamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ITALICS_ENVELOPE();
    antlr4::tree::TerminalNode* ITALICS_ENVELOPE(size_t i);
    W_streamContext *w_stream();
    std::vector<antlr4::tree::TerminalNode *> BLANK();
    antlr4::tree::TerminalNode* BLANK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Italics_streamContext* italics_stream();

  class  Bold_streamContext : public antlr4::ParserRuleContext {
  public:
    Bold_streamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> BOLD_ENVELOPE();
    antlr4::tree::TerminalNode* BOLD_ENVELOPE(size_t i);
    W_streamContext *w_stream();
    std::vector<antlr4::tree::TerminalNode *> BLANK();
    antlr4::tree::TerminalNode* BLANK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bold_streamContext* bold_stream();

  class  W_streamContext : public antlr4::ParserRuleContext {
  public:
    W_streamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Italics_streamContext *> italics_stream();
    Italics_streamContext* italics_stream(size_t i);
    std::vector<Bold_streamContext *> bold_stream();
    Bold_streamContext* bold_stream(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BLANK();
    antlr4::tree::TerminalNode* BLANK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  W_streamContext* w_stream();

  class  HeaderContext : public antlr4::ParserRuleContext {
  public:
    HeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Raw_streamContext *raw_stream();
    std::vector<antlr4::tree::TerminalNode *> HEADER_START();
    antlr4::tree::TerminalNode* HEADER_START(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BLANK();
    antlr4::tree::TerminalNode* BLANK(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HeaderContext* header();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace marky
