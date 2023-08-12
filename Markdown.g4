grammar Markdown;

markdown        : block*;

block           : (w_stream | header) (LBREAK+ | EOF);

raw_stream      : (WORD BLANK*)+ ;
italics_stream  : ITALICS_ENVELOPE BLANK* w_stream ITALICS_ENVELOPE BLANK*;
bold_stream     : BOLD_ENVELOPE BLANK* w_stream BOLD_ENVELOPE BLANK*;

w_stream        : (italics_stream | bold_stream | WORD BLANK*)+ | WORD;
header          : HEADER_START+ BLANK* raw_stream;


//fragment ALNUM          : [a-zA-Z0-9] ;
fragment ALNUM          : ~[_*#\n\r\f\t ] ; // 'alnum' here means any char not white space or reserved by markdown
HEADER_START            : '#' ;

BLANK                   : ' ' | '\t' ;
LBREAK                  : '\n' | '\r\f' ;
WHITESPACE              : LBREAK | BLANK ;

WORD                    : (ALNUM)+ ;
BOLD_ENVELOPE           : '*' ;
ITALICS_ENVELOPE        : '_' ;