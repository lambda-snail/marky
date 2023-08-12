
// Generated from .\Markdown.g4 by ANTLR 4.13.0


#include "MarkdownLexer.h"


using namespace antlr4;

using namespace marky;


using namespace antlr4;

namespace {

struct MarkdownLexerStaticData final {
  MarkdownLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MarkdownLexerStaticData(const MarkdownLexerStaticData&) = delete;
  MarkdownLexerStaticData(MarkdownLexerStaticData&&) = delete;
  MarkdownLexerStaticData& operator=(const MarkdownLexerStaticData&) = delete;
  MarkdownLexerStaticData& operator=(MarkdownLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag markdownlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
MarkdownLexerStaticData *markdownlexerLexerStaticData = nullptr;

void markdownlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (markdownlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(markdownlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MarkdownLexerStaticData>(
    std::vector<std::string>{
      "ALNUM", "HEADER_START", "BLANK", "LBREAK", "WHITESPACE", "WORD", 
      "BOLD_ENVELOPE", "ITALICS_ENVELOPE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'#'", "", "", "", "", "'*'", "'_'"
    },
    std::vector<std::string>{
      "", "HEADER_START", "BLANK", "LBREAK", "WHITESPACE", "WORD", "BOLD_ENVELOPE", 
      "ITALICS_ENVELOPE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,7,43,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,3,3,29,8,3,1,4,1,
  	4,3,4,33,8,4,1,5,4,5,36,8,5,11,5,12,5,37,1,6,1,6,1,7,1,7,0,0,8,1,0,3,
  	1,5,2,7,3,9,4,11,5,13,6,15,7,1,0,2,6,0,9,10,12,13,32,32,35,35,42,42,95,
  	95,2,0,9,9,32,32,44,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,
  	11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,1,17,1,0,0,0,3,19,1,0,0,0,5,21,1,
  	0,0,0,7,28,1,0,0,0,9,32,1,0,0,0,11,35,1,0,0,0,13,39,1,0,0,0,15,41,1,0,
  	0,0,17,18,8,0,0,0,18,2,1,0,0,0,19,20,5,35,0,0,20,4,1,0,0,0,21,22,7,1,
  	0,0,22,23,1,0,0,0,23,24,6,2,0,0,24,6,1,0,0,0,25,29,5,10,0,0,26,27,5,13,
  	0,0,27,29,5,12,0,0,28,25,1,0,0,0,28,26,1,0,0,0,29,8,1,0,0,0,30,33,3,7,
  	3,0,31,33,3,5,2,0,32,30,1,0,0,0,32,31,1,0,0,0,33,10,1,0,0,0,34,36,3,1,
  	0,0,35,34,1,0,0,0,36,37,1,0,0,0,37,35,1,0,0,0,37,38,1,0,0,0,38,12,1,0,
  	0,0,39,40,5,42,0,0,40,14,1,0,0,0,41,42,5,95,0,0,42,16,1,0,0,0,4,0,28,
  	32,37,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  markdownlexerLexerStaticData = staticData.release();
}

}

MarkdownLexer::MarkdownLexer(CharStream *input) : Lexer(input) {
  MarkdownLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *markdownlexerLexerStaticData->atn, markdownlexerLexerStaticData->decisionToDFA, markdownlexerLexerStaticData->sharedContextCache);
}

MarkdownLexer::~MarkdownLexer() {
  delete _interpreter;
}

std::string MarkdownLexer::getGrammarFileName() const {
  return "Markdown.g4";
}

const std::vector<std::string>& MarkdownLexer::getRuleNames() const {
  return markdownlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MarkdownLexer::getChannelNames() const {
  return markdownlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MarkdownLexer::getModeNames() const {
  return markdownlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MarkdownLexer::getVocabulary() const {
  return markdownlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MarkdownLexer::getSerializedATN() const {
  return markdownlexerLexerStaticData->serializedATN;
}

const atn::ATN& MarkdownLexer::getATN() const {
  return *markdownlexerLexerStaticData->atn;
}




void MarkdownLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  markdownlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(markdownlexerLexerOnceFlag, markdownlexerLexerInitialize);
#endif
}
