#pragma once

#include <boost/variant/static_visitor.hpp>

#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include <string>
#include <vector>

#include <marky/ast.h>
#include <stack>


namespace marky::parser {

    typedef char char_t;

    template<typename TReturn = void>
    class markdown_visitor : public boost::static_visitor<TReturn> {
    public:
        TReturn operator()(ast::word const &w) {
            visit_word(w);
        }

//        TReturn operator()(ast::paragraph const &p) {
//            visit_paragraph(p);
//        }

        TReturn operator()(ast::header const &h) {
            visit_header(h);
        }

//        virtual TReturn visit_paragraph(ast::paragraph const &p) = 0;
        virtual TReturn visit_header(ast::header const &h) = 0;
        virtual TReturn visit_word(ast::word const &w) = 0;
    };

    template<typename TVisitor>
    bool parse_string(std::string::iterator begin, std::string::iterator end, markdown_visitor<TVisitor> *visitor);
}
