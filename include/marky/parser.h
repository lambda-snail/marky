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
        int level = 1;
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
        std::vector<text_block> items;
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

    namespace parser
    {
        rule<class word_r, marky::word> word = "word";
        auto const word_def = *(~space - char_('#'));
        BOOST_SPIRIT_DEFINE(word);

        rule<class paragraph_r, marky::paragraph> paragraph = "paragraph";
        auto const paragraph_def = parser::word % blank;
        BOOST_SPIRIT_DEFINE(paragraph);

        rule<class header_r, marky::header> header = "header";
        auto const header_def = char_('#') >> parser::word % blank;
        BOOST_SPIRIT_DEFINE(header);

        //rule<class markdown_t, marky::markdown> markdown = "markdown";
        rule<class markdown_t, std::vector< x3::variant<marky::paragraph, marky::header>>> markdown = "markdown";
        auto const markdown_def = (parser::header | parser::paragraph) % +eol;
        BOOST_SPIRIT_DEFINE(markdown);
    }


    class my_visitor : public boost::static_visitor<void>
    {
    public:
        void operator()(marky::paragraph const& p) const
        {
            std::cout << p.items.size() << std::endl;;
        }

        void operator()(marky::header const& p) const
        {
            std::cout << p.items.size() << std::endl;;
        }
    };


    template <typename Iterator>
    bool parse_string(Iterator first, Iterator last, marky::markdown& md)
    {
        std::vector< x3::variant<marky::paragraph, marky::header>> parse_result;
        bool r = x3::parse(first, last, parser::markdown, parse_result);
        //bool r = x3::phrase_parse(first, last, parser::markdown, eol, md);

        // Post parse filter to remove blank lines - this is not optimized
        // TODO: Optimize or solve in grammar
        for (auto const& block : parse_result)
        {
            boost::apply_visitor( my_visitor(), block );


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
        }

        return r;
    }
}
