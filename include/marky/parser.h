#pragma once

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include <string>
#include <vector>

#include <marky/ast.h>

namespace marky
{
    namespace x3 = boost::spirit::x3;
    namespace ascii = boost::spirit::x3::ascii;

    using x3::char_;
    using x3::_attr;
    using x3::phrase_parse;
    using x3::ascii::blank;
    using x3::ascii::space;
    using x3::eol;
    using x3::rule;
    using x3::repeat;
    using x3::lexeme;

    namespace parser
    {
        using namespace marky;

        rule<class word_r, ast::word> word = "word";
        auto const word_def = +(~space - char_('#'));
        BOOST_SPIRIT_DEFINE(word);

        rule<class paragraph_r, ast::paragraph> paragraph = "paragraph";
        auto const paragraph_def = lexeme[parser::word % +blank];
        BOOST_SPIRIT_DEFINE(paragraph);

        rule<class header_r, ast::header> header = "header";
        auto const header_def = repeat(1,5)[char_('#')] >> lexeme[parser::word % +blank];
        BOOST_SPIRIT_DEFINE(header);

        rule<class markdown_t, std::vector< x3::variant<ast::paragraph, ast::header>>> markdown = "markdown";
        auto const markdown_def = x3::omit[*space] >> (parser::header | parser::paragraph) % +eol;
        BOOST_SPIRIT_DEFINE(markdown);
    }

    template <typename TReturn = void>
    class markdown_visitor : public boost::static_visitor<TReturn>
    {
    public:
        TReturn operator()(ast::paragraph const& p) const
        {
            visit_paragraph(p);
        }

        TReturn operator()(ast::header const& h) const
        {
            visit_header(h);
        }

        virtual TReturn visit_paragraph(ast::paragraph const& p) const = 0;
        virtual TReturn visit_header(ast::header const& h) const = 0;
    };

    // https://www.boost.org/doc/libs/develop/libs/spirit/doc/x3/html/spirit_x3/tutorials/rexpr.html
    template <typename TVisitor>
    bool parse_string(std::string::iterator first, std::string::iterator last, std::vector<x3::variant<ast::paragraph, ast::header>>& md, markdown_visitor<TVisitor>* visitor = nullptr)
    {
        bool r = x3::phrase_parse(first, last, parser::markdown, blank, md);

        if(visitor)
        {
            for (auto const& block : md)
            {
                boost::apply_visitor(*visitor, block);
            }
        }

        return r;
    }
}
