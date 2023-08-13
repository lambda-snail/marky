#pragma once

#include "marky/parser/MarkdownListener.h"

#include <string>

namespace marky {
    class Marky {
    public:
        void process_markdown(marky::MarkdownListener &backend, std::string_view markdown) const;
    };
}