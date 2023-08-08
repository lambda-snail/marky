#pragma once

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include <string>
#include <vector>

namespace marky::ast {
    struct word {
        std::string text;
    };

    struct paragraph {
        std::vector<word> items;
    };

    struct header {
        std::string level;
        std::vector<word> items;
    };

    struct text_block : public boost::spirit::x3::variant<header, paragraph> {
    public:
        text_block() = default;

        using base_type::base_type;
        using base_type::operator=;
    };

    struct markdown {
        std::vector<boost::spirit::x3::variant<paragraph, header> > items;
    };
}

// Boost fusion declarations need to go into global namespace

BOOST_FUSION_ADAPT_STRUCT(
        marky::ast::word,
        text
)

BOOST_FUSION_ADAPT_STRUCT(
        marky::ast::header,
        level,
        items
)

BOOST_FUSION_ADAPT_STRUCT(
        marky::ast::paragraph,
        items
)

BOOST_FUSION_ADAPT_STRUCT(
        marky::ast::markdown,
        items
)