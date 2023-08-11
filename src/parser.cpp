#include <boost/variant.hpp>

#include <marky/parser.h>

template<typename TVisitor>
bool marky::parser::parse_string(std::string::iterator begin,
                  std::string::iterator end,
                  markdown_visitor<TVisitor> *visitor)
{
    using marky::ast::word;

    bool success = true;
    std::vector<boost::variant<word>> markdown;//( std::distance(begin, end) / 10 );

    bool isParsingHeader = false;
    std::vector<word> word_v;
    int level = 0;

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
                    auto w = std::string(tmp_v.rbegin(), tmp_v.rend());
                    if(isParsingHeader)
                    {
                        markdown.emplace_back(word { w });
                    }
                    else
                    {
                        markdown.emplace_back(word { w });
                    }
                }
                break;
            case '#':
                if(isParsingHeader)
                {
                    ++level;
                }

                isParsingHeader = true;


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