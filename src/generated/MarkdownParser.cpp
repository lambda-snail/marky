
// Generated from .\Markdown.g4 by ANTLR 4.13.0


#include "MarkdownListener.h"
#include "MarkdownVisitor.h"

#include "MarkdownParser.h"


using namespace antlrcpp;
using namespace marky;

using namespace antlr4;

namespace {

struct MarkdownParserStaticData final {
  MarkdownParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MarkdownParserStaticData(const MarkdownParserStaticData&) = delete;
  MarkdownParserStaticData(MarkdownParserStaticData&&) = delete;
  MarkdownParserStaticData& operator=(const MarkdownParserStaticData&) = delete;
  MarkdownParserStaticData& operator=(MarkdownParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag markdownParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
MarkdownParserStaticData *markdownParserStaticData = nullptr;

void markdownParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (markdownParserStaticData != nullptr) {
    return;
  }
#else
  assert(markdownParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MarkdownParserStaticData>(
    std::vector<std::string>{
      "markdown", "block", "raw_stream", "italics_stream", "bold_stream", 
      "w_stream", "header"
    },
    std::vector<std::string>{
      "", "'#'", "", "", "", "", "'*'", "'_'"
    },
    std::vector<std::string>{
      "", "HEADER_START", "BLANK", "EOL", "WHITESPACE", "WORD", "BOLD_ENVELOPE", 
      "ITALICS_ENVELOPE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,7,109,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	5,0,16,8,0,10,0,12,0,19,9,0,1,0,5,0,22,8,0,10,0,12,0,25,9,0,1,1,1,1,3,
  	1,29,8,1,1,1,4,1,32,8,1,11,1,12,1,33,1,1,3,1,37,8,1,1,2,1,2,5,2,41,8,
  	2,10,2,12,2,44,9,2,4,2,46,8,2,11,2,12,2,47,1,3,1,3,5,3,52,8,3,10,3,12,
  	3,55,9,3,1,3,1,3,1,3,5,3,60,8,3,10,3,12,3,63,9,3,1,4,1,4,5,4,67,8,4,10,
  	4,12,4,70,9,4,1,4,1,4,1,4,5,4,75,8,4,10,4,12,4,78,9,4,1,5,1,5,1,5,1,5,
  	5,5,84,8,5,10,5,12,5,87,9,5,4,5,89,8,5,11,5,12,5,90,1,5,3,5,94,8,5,1,
  	6,4,6,97,8,6,11,6,12,6,98,1,6,5,6,102,8,6,10,6,12,6,105,9,6,1,6,1,6,1,
  	6,0,0,7,0,2,4,6,8,10,12,0,0,119,0,17,1,0,0,0,2,28,1,0,0,0,4,45,1,0,0,
  	0,6,49,1,0,0,0,8,64,1,0,0,0,10,93,1,0,0,0,12,96,1,0,0,0,14,16,5,3,0,0,
  	15,14,1,0,0,0,16,19,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,23,1,0,0,0,
  	19,17,1,0,0,0,20,22,3,2,1,0,21,20,1,0,0,0,22,25,1,0,0,0,23,21,1,0,0,0,
  	23,24,1,0,0,0,24,1,1,0,0,0,25,23,1,0,0,0,26,29,3,10,5,0,27,29,3,12,6,
  	0,28,26,1,0,0,0,28,27,1,0,0,0,29,36,1,0,0,0,30,32,5,3,0,0,31,30,1,0,0,
  	0,32,33,1,0,0,0,33,31,1,0,0,0,33,34,1,0,0,0,34,37,1,0,0,0,35,37,5,0,0,
  	1,36,31,1,0,0,0,36,35,1,0,0,0,37,3,1,0,0,0,38,42,5,5,0,0,39,41,5,2,0,
  	0,40,39,1,0,0,0,41,44,1,0,0,0,42,40,1,0,0,0,42,43,1,0,0,0,43,46,1,0,0,
  	0,44,42,1,0,0,0,45,38,1,0,0,0,46,47,1,0,0,0,47,45,1,0,0,0,47,48,1,0,0,
  	0,48,5,1,0,0,0,49,53,5,7,0,0,50,52,5,2,0,0,51,50,1,0,0,0,52,55,1,0,0,
  	0,53,51,1,0,0,0,53,54,1,0,0,0,54,56,1,0,0,0,55,53,1,0,0,0,56,57,3,10,
  	5,0,57,61,5,7,0,0,58,60,5,2,0,0,59,58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,
  	0,0,61,62,1,0,0,0,62,7,1,0,0,0,63,61,1,0,0,0,64,68,5,6,0,0,65,67,5,2,
  	0,0,66,65,1,0,0,0,67,70,1,0,0,0,68,66,1,0,0,0,68,69,1,0,0,0,69,71,1,0,
  	0,0,70,68,1,0,0,0,71,72,3,10,5,0,72,76,5,6,0,0,73,75,5,2,0,0,74,73,1,
  	0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,0,77,9,1,0,0,0,78,76,1,
  	0,0,0,79,89,3,6,3,0,80,89,3,8,4,0,81,85,5,5,0,0,82,84,5,2,0,0,83,82,1,
  	0,0,0,84,87,1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,89,1,0,0,0,87,85,1,
  	0,0,0,88,79,1,0,0,0,88,80,1,0,0,0,88,81,1,0,0,0,89,90,1,0,0,0,90,88,1,
  	0,0,0,90,91,1,0,0,0,91,94,1,0,0,0,92,94,5,5,0,0,93,88,1,0,0,0,93,92,1,
  	0,0,0,94,11,1,0,0,0,95,97,5,1,0,0,96,95,1,0,0,0,97,98,1,0,0,0,98,96,1,
  	0,0,0,98,99,1,0,0,0,99,103,1,0,0,0,100,102,5,2,0,0,101,100,1,0,0,0,102,
  	105,1,0,0,0,103,101,1,0,0,0,103,104,1,0,0,0,104,106,1,0,0,0,105,103,1,
  	0,0,0,106,107,3,4,2,0,107,13,1,0,0,0,17,17,23,28,33,36,42,47,53,61,68,
  	76,85,88,90,93,98,103
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  markdownParserStaticData = staticData.release();
}

}

MarkdownParser::MarkdownParser(TokenStream *input) : MarkdownParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MarkdownParser::MarkdownParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MarkdownParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *markdownParserStaticData->atn, markdownParserStaticData->decisionToDFA, markdownParserStaticData->sharedContextCache, options);
}

MarkdownParser::~MarkdownParser() {
  delete _interpreter;
}

const atn::ATN& MarkdownParser::getATN() const {
  return *markdownParserStaticData->atn;
}

std::string MarkdownParser::getGrammarFileName() const {
  return "Markdown.g4";
}

const std::vector<std::string>& MarkdownParser::getRuleNames() const {
  return markdownParserStaticData->ruleNames;
}

const dfa::Vocabulary& MarkdownParser::getVocabulary() const {
  return markdownParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MarkdownParser::getSerializedATN() const {
  return markdownParserStaticData->serializedATN;
}


//----------------- MarkdownContext ------------------------------------------------------------------

MarkdownParser::MarkdownContext::MarkdownContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MarkdownParser::MarkdownContext::EOL() {
  return getTokens(MarkdownParser::EOL);
}

tree::TerminalNode* MarkdownParser::MarkdownContext::EOL(size_t i) {
  return getToken(MarkdownParser::EOL, i);
}

std::vector<MarkdownParser::BlockContext *> MarkdownParser::MarkdownContext::block() {
  return getRuleContexts<MarkdownParser::BlockContext>();
}

MarkdownParser::BlockContext* MarkdownParser::MarkdownContext::block(size_t i) {
  return getRuleContext<MarkdownParser::BlockContext>(i);
}


size_t MarkdownParser::MarkdownContext::getRuleIndex() const {
  return MarkdownParser::RuleMarkdown;
}

void MarkdownParser::MarkdownContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMarkdown(this);
}

void MarkdownParser::MarkdownContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMarkdown(this);
}


std::any MarkdownParser::MarkdownContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MarkdownVisitor*>(visitor))
    return parserVisitor->visitMarkdown(this);
  else
    return visitor->visitChildren(this);
}

MarkdownParser::MarkdownContext* MarkdownParser::markdown() {
  MarkdownContext *_localctx = _tracker.createInstance<MarkdownContext>(_ctx, getState());
  enterRule(_localctx, 0, MarkdownParser::RuleMarkdown);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MarkdownParser::EOL) {
      setState(14);
      match(MarkdownParser::EOL);
      setState(19);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 226) != 0)) {
      setState(20);
      block();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MarkdownParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MarkdownParser::W_streamContext* MarkdownParser::BlockContext::w_stream() {
  return getRuleContext<MarkdownParser::W_streamContext>(0);
}

MarkdownParser::HeaderContext* MarkdownParser::BlockContext::header() {
  return getRuleContext<MarkdownParser::HeaderContext>(0);
}

tree::TerminalNode* MarkdownParser::BlockContext::EOF() {
  return getToken(MarkdownParser::EOF, 0);
}

std::vector<tree::TerminalNode *> MarkdownParser::BlockContext::EOL() {
  return getTokens(MarkdownParser::EOL);
}

tree::TerminalNode* MarkdownParser::BlockContext::EOL(size_t i) {
  return getToken(MarkdownParser::EOL, i);
}


size_t MarkdownParser::BlockContext::getRuleIndex() const {
  return MarkdownParser::RuleBlock;
}

void MarkdownParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void MarkdownParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any MarkdownParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MarkdownVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MarkdownParser::BlockContext* MarkdownParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 2, MarkdownParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MarkdownParser::WORD:
      case MarkdownParser::BOLD_ENVELOPE:
      case MarkdownParser::ITALICS_ENVELOPE: {
        setState(26);
        w_stream();
        break;
      }

      case MarkdownParser::HEADER_START: {
        setState(27);
        header();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MarkdownParser::EOL: {
        setState(31); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(30);
          match(MarkdownParser::EOL);
          setState(33); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == MarkdownParser::EOL);
        break;
      }

      case MarkdownParser::EOF: {
        setState(35);
        match(MarkdownParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Raw_streamContext ------------------------------------------------------------------

MarkdownParser::Raw_streamContext::Raw_streamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MarkdownParser::Raw_streamContext::WORD() {
  return getTokens(MarkdownParser::WORD);
}

tree::TerminalNode* MarkdownParser::Raw_streamContext::WORD(size_t i) {
  return getToken(MarkdownParser::WORD, i);
}

std::vector<tree::TerminalNode *> MarkdownParser::Raw_streamContext::BLANK() {
  return getTokens(MarkdownParser::BLANK);
}

tree::TerminalNode* MarkdownParser::Raw_streamContext::BLANK(size_t i) {
  return getToken(MarkdownParser::BLANK, i);
}


size_t MarkdownParser::Raw_streamContext::getRuleIndex() const {
  return MarkdownParser::RuleRaw_stream;
}

void MarkdownParser::Raw_streamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRaw_stream(this);
}

void MarkdownParser::Raw_streamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRaw_stream(this);
}


std::any MarkdownParser::Raw_streamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MarkdownVisitor*>(visitor))
    return parserVisitor->visitRaw_stream(this);
  else
    return visitor->visitChildren(this);
}

MarkdownParser::Raw_streamContext* MarkdownParser::raw_stream() {
  Raw_streamContext *_localctx = _tracker.createInstance<Raw_streamContext>(_ctx, getState());
  enterRule(_localctx, 4, MarkdownParser::RuleRaw_stream);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(38);
      match(MarkdownParser::WORD);
      setState(42);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MarkdownParser::BLANK) {
        setState(39);
        match(MarkdownParser::BLANK);
        setState(44);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(47); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == MarkdownParser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Italics_streamContext ------------------------------------------------------------------

MarkdownParser::Italics_streamContext::Italics_streamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MarkdownParser::Italics_streamContext::ITALICS_ENVELOPE() {
  return getTokens(MarkdownParser::ITALICS_ENVELOPE);
}

tree::TerminalNode* MarkdownParser::Italics_streamContext::ITALICS_ENVELOPE(size_t i) {
  return getToken(MarkdownParser::ITALICS_ENVELOPE, i);
}

MarkdownParser::W_streamContext* MarkdownParser::Italics_streamContext::w_stream() {
  return getRuleContext<MarkdownParser::W_streamContext>(0);
}

std::vector<tree::TerminalNode *> MarkdownParser::Italics_streamContext::BLANK() {
  return getTokens(MarkdownParser::BLANK);
}

tree::TerminalNode* MarkdownParser::Italics_streamContext::BLANK(size_t i) {
  return getToken(MarkdownParser::BLANK, i);
}


size_t MarkdownParser::Italics_streamContext::getRuleIndex() const {
  return MarkdownParser::RuleItalics_stream;
}

void MarkdownParser::Italics_streamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItalics_stream(this);
}

void MarkdownParser::Italics_streamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItalics_stream(this);
}


std::any MarkdownParser::Italics_streamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MarkdownVisitor*>(visitor))
    return parserVisitor->visitItalics_stream(this);
  else
    return visitor->visitChildren(this);
}

MarkdownParser::Italics_streamContext* MarkdownParser::italics_stream() {
  Italics_streamContext *_localctx = _tracker.createInstance<Italics_streamContext>(_ctx, getState());
  enterRule(_localctx, 6, MarkdownParser::RuleItalics_stream);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(MarkdownParser::ITALICS_ENVELOPE);
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MarkdownParser::BLANK) {
      setState(50);
      match(MarkdownParser::BLANK);
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(56);
    w_stream();
    setState(57);
    match(MarkdownParser::ITALICS_ENVELOPE);
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MarkdownParser::BLANK) {
      setState(58);
      match(MarkdownParser::BLANK);
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bold_streamContext ------------------------------------------------------------------

MarkdownParser::Bold_streamContext::Bold_streamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MarkdownParser::Bold_streamContext::BOLD_ENVELOPE() {
  return getTokens(MarkdownParser::BOLD_ENVELOPE);
}

tree::TerminalNode* MarkdownParser::Bold_streamContext::BOLD_ENVELOPE(size_t i) {
  return getToken(MarkdownParser::BOLD_ENVELOPE, i);
}

MarkdownParser::W_streamContext* MarkdownParser::Bold_streamContext::w_stream() {
  return getRuleContext<MarkdownParser::W_streamContext>(0);
}

std::vector<tree::TerminalNode *> MarkdownParser::Bold_streamContext::BLANK() {
  return getTokens(MarkdownParser::BLANK);
}

tree::TerminalNode* MarkdownParser::Bold_streamContext::BLANK(size_t i) {
  return getToken(MarkdownParser::BLANK, i);
}


size_t MarkdownParser::Bold_streamContext::getRuleIndex() const {
  return MarkdownParser::RuleBold_stream;
}

void MarkdownParser::Bold_streamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBold_stream(this);
}

void MarkdownParser::Bold_streamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBold_stream(this);
}


std::any MarkdownParser::Bold_streamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MarkdownVisitor*>(visitor))
    return parserVisitor->visitBold_stream(this);
  else
    return visitor->visitChildren(this);
}

MarkdownParser::Bold_streamContext* MarkdownParser::bold_stream() {
  Bold_streamContext *_localctx = _tracker.createInstance<Bold_streamContext>(_ctx, getState());
  enterRule(_localctx, 8, MarkdownParser::RuleBold_stream);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(MarkdownParser::BOLD_ENVELOPE);
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MarkdownParser::BLANK) {
      setState(65);
      match(MarkdownParser::BLANK);
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(71);
    w_stream();
    setState(72);
    match(MarkdownParser::BOLD_ENVELOPE);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MarkdownParser::BLANK) {
      setState(73);
      match(MarkdownParser::BLANK);
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- W_streamContext ------------------------------------------------------------------

MarkdownParser::W_streamContext::W_streamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MarkdownParser::Italics_streamContext *> MarkdownParser::W_streamContext::italics_stream() {
  return getRuleContexts<MarkdownParser::Italics_streamContext>();
}

MarkdownParser::Italics_streamContext* MarkdownParser::W_streamContext::italics_stream(size_t i) {
  return getRuleContext<MarkdownParser::Italics_streamContext>(i);
}

std::vector<MarkdownParser::Bold_streamContext *> MarkdownParser::W_streamContext::bold_stream() {
  return getRuleContexts<MarkdownParser::Bold_streamContext>();
}

MarkdownParser::Bold_streamContext* MarkdownParser::W_streamContext::bold_stream(size_t i) {
  return getRuleContext<MarkdownParser::Bold_streamContext>(i);
}

std::vector<tree::TerminalNode *> MarkdownParser::W_streamContext::WORD() {
  return getTokens(MarkdownParser::WORD);
}

tree::TerminalNode* MarkdownParser::W_streamContext::WORD(size_t i) {
  return getToken(MarkdownParser::WORD, i);
}

std::vector<tree::TerminalNode *> MarkdownParser::W_streamContext::BLANK() {
  return getTokens(MarkdownParser::BLANK);
}

tree::TerminalNode* MarkdownParser::W_streamContext::BLANK(size_t i) {
  return getToken(MarkdownParser::BLANK, i);
}


size_t MarkdownParser::W_streamContext::getRuleIndex() const {
  return MarkdownParser::RuleW_stream;
}

void MarkdownParser::W_streamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterW_stream(this);
}

void MarkdownParser::W_streamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitW_stream(this);
}


std::any MarkdownParser::W_streamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MarkdownVisitor*>(visitor))
    return parserVisitor->visitW_stream(this);
  else
    return visitor->visitChildren(this);
}

MarkdownParser::W_streamContext* MarkdownParser::w_stream() {
  W_streamContext *_localctx = _tracker.createInstance<W_streamContext>(_ctx, getState());
  enterRule(_localctx, 10, MarkdownParser::RuleW_stream);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(93);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(88); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(88);
                _errHandler->sync(this);
                switch (_input->LA(1)) {
                  case MarkdownParser::ITALICS_ENVELOPE: {
                    setState(79);
                    italics_stream();
                    break;
                  }

                  case MarkdownParser::BOLD_ENVELOPE: {
                    setState(80);
                    bold_stream();
                    break;
                  }

                  case MarkdownParser::WORD: {
                    setState(81);
                    match(MarkdownParser::WORD);
                    setState(85);
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    while (_la == MarkdownParser::BLANK) {
                      setState(82);
                      match(MarkdownParser::BLANK);
                      setState(87);
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    }
                    break;
                  }

                default:
                  throw NoViableAltException(this);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(90); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(92);
      match(MarkdownParser::WORD);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderContext ------------------------------------------------------------------

MarkdownParser::HeaderContext::HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MarkdownParser::Raw_streamContext* MarkdownParser::HeaderContext::raw_stream() {
  return getRuleContext<MarkdownParser::Raw_streamContext>(0);
}

std::vector<tree::TerminalNode *> MarkdownParser::HeaderContext::HEADER_START() {
  return getTokens(MarkdownParser::HEADER_START);
}

tree::TerminalNode* MarkdownParser::HeaderContext::HEADER_START(size_t i) {
  return getToken(MarkdownParser::HEADER_START, i);
}

std::vector<tree::TerminalNode *> MarkdownParser::HeaderContext::BLANK() {
  return getTokens(MarkdownParser::BLANK);
}

tree::TerminalNode* MarkdownParser::HeaderContext::BLANK(size_t i) {
  return getToken(MarkdownParser::BLANK, i);
}


size_t MarkdownParser::HeaderContext::getRuleIndex() const {
  return MarkdownParser::RuleHeader;
}

void MarkdownParser::HeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHeader(this);
}

void MarkdownParser::HeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MarkdownListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHeader(this);
}


std::any MarkdownParser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MarkdownVisitor*>(visitor))
    return parserVisitor->visitHeader(this);
  else
    return visitor->visitChildren(this);
}

MarkdownParser::HeaderContext* MarkdownParser::header() {
  HeaderContext *_localctx = _tracker.createInstance<HeaderContext>(_ctx, getState());
  enterRule(_localctx, 12, MarkdownParser::RuleHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(95);
      match(MarkdownParser::HEADER_START);
      setState(98); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == MarkdownParser::HEADER_START);
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MarkdownParser::BLANK) {
      setState(100);
      match(MarkdownParser::BLANK);
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(106);
    raw_stream();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void MarkdownParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  markdownParserInitialize();
#else
  ::antlr4::internal::call_once(markdownParserOnceFlag, markdownParserInitialize);
#endif
}
