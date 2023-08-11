#pragma once

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

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
//
//        TReturn operator()(ast::header const &h) {
//            visit_header(h);
//        }
//
//        virtual TReturn visit_paragraph(ast::paragraph const &p) = 0;
//
//        virtual TReturn visit_header(ast::header const &h) = 0;
        virtual TReturn visit_word(ast::word const &w) = 0;
    };

    template<typename TVisitor>
    bool parse_string(std::string::iterator begin,
                      std::string::iterator end,
                      markdown_visitor<TVisitor> *visitor)
    {
        using marky::ast::word;

        bool success = true;
        std::vector<boost::variant<word>> markdown;//( std::distance(begin, end) / 10 );

        std::stack<char_t> tmp_s;
        std::vector<char_t> tmp_v;
        while(begin != end)
        {
            char_t c = *begin;
            switch(c)
            {
                case ' ':
                case '\t':
                case '\n':
                case '\r':
                case 'f':
                    tmp_v.clear();
                    while(not tmp_s.empty())
                    {
                        tmp_v.push_back(tmp_s.top());
                        tmp_s.pop();
                    }

                    if(not tmp_v.empty())
                    {
                        markdown.emplace_back(word
                        {
                           std::string(tmp_v.rbegin(), tmp_v.rend())
                       });
                    }
                    break;
                default:
                    tmp_s.push(c);
            };

            ++begin;
        }

        for (auto const &block: markdown) {
            boost::apply_visitor(*visitor, block);
        }

        return success;
    }
}
