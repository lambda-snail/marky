#pragma once

#include <boost/spirit/home/x3.hpp>

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

    struct markdown
    {
        std::vector<paragraph> items;
    };
}

BOOST_FUSION_ADAPT_STRUCT(
        marky::word,
        text
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
        auto const word_def = *(~space);
        BOOST_SPIRIT_DEFINE(word);

        rule<class paragraph_r, marky::paragraph> paragraph = "paragraph";
        auto const paragraph_def = parser::word % blank;
        BOOST_SPIRIT_DEFINE(paragraph);

        rule<class markdown_t, marky::markdown> markdown = "markdown";
        auto const markdown_def = parser::paragraph % +eol;
        BOOST_SPIRIT_DEFINE(markdown);
    }

    template <typename Iterator>
    bool parse_string(Iterator first, Iterator last)
    {
        std::vector<marky::paragraph> paragraphs;
        marky::markdown md;
        bool r = x3::parse(first, last, parser::markdown, md);

        std::cout << md.items.size() << std::endl;

        for(auto p : md.items)
        {
            for(auto w : p.items)
            {
                std::cout << w.text << " ";
            }

            std::cout << std::endl << std::endl;
        }

        return r;
    }
}

//int
//main()
//{
//    std::ifstream file("../markdown.md");
//    std::string markdown;
//    {
//        char c;
//        while ( file.get(c) )
//        {
//            markdown += c;
//        }
//        file.close();
//    }
//
//    marky::parse_string(markdown.begin(), markdown.end());
//
//    return 0;
//}