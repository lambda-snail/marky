#pragma once

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace marky
{
    struct word
    {
        std::string text;
    };

    struct paragraph
    {
        std::vector<word> items;
    };

    struct header
    {
        //int level = 1;
        std::string level;
        std::vector<word> items;
    };

    struct text_block : public boost::spirit::x3::variant<header, paragraph>
    {
    public:
        text_block() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct markdown
    {
        std::vector< boost::spirit::x3::variant<marky::paragraph, marky::header> > items;
    };
}

BOOST_FUSION_ADAPT_STRUCT(
        marky::word,
        text
)

BOOST_FUSION_ADAPT_STRUCT(
        marky::header,
        level,
        items
)

BOOST_FUSION_ADAPT_STRUCT(
        marky::paragraph,
        items
)

BOOST_FUSION_ADAPT_STRUCT(
        marky::markdown,
        items
)

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

    namespace parser
    {
        rule<class word_r, marky::word> word = "word";
        auto const word_def = *(~space - char_('#'));
        BOOST_SPIRIT_DEFINE(word);

        rule<class paragraph_r, marky::paragraph> paragraph = "paragraph";
        auto const paragraph_def = parser::word % blank;
        BOOST_SPIRIT_DEFINE(paragraph);

        rule<class header_r, marky::header> header = "header";
        auto const header_def = repeat(1,5)[char_('#')] >> parser::word % blank;
        BOOST_SPIRIT_DEFINE(header);

        //rule<class markdown_t, marky::markdown> markdown = "markdown";
        rule<class markdown_t, std::vector< x3::variant<marky::paragraph, marky::header>>> markdown = "markdown";
        auto const markdown_def = (parser::header | parser::paragraph) % +eol;
        BOOST_SPIRIT_DEFINE(markdown);
    }

    template <typename TReturn = void>
    class markdown_visitor : public boost::static_visitor<TReturn>
    {
    public:
        virtual TReturn operator()(marky::paragraph const& p) const { }

        virtual TReturn operator()(marky::header const& p) const { }
    };

    // https://www.boost.org/doc/libs/develop/libs/spirit/doc/x3/html/spirit_x3/tutorials/rexpr.html
    template <typename TVisitor>
    bool parse_string(std::string::iterator first, std::string::iterator last, std::vector<boost::spirit::x3::variant<marky::paragraph, marky::header>>& md, markdown_visitor<TVisitor>* visitor = nullptr)
    {
        std::vector< x3::variant<marky::paragraph, marky::header>> parse_result;
        bool r = x3::parse(first, last, parser::markdown, md);

        if(visitor)
        {
            for (auto const& block : md)
            {
                boost::apply_visitor(*visitor, block);
            }
        }

//        for (auto const& block : md)
//        {
//            boost::apply_visitor( my_visitor(), block );


            //if (not p.items.empty() && not p.items.at(0).text.empty())
            //{
            //    md.items.push_back(p);
            //}

            //boost::get<paragraph>(&block) ? boost::get<paragraph>(&block) boost::get<header>(&block)
            //
//
            //    boost::get<paragraph>(item);
            //else
            //    std::cout << boost::get<std::string>(attr) << std::endl;
        //}

        return r;
    }
}
