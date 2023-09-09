# Marky

A simple parser for markdown based on Antlr4. It converts markdown to html based on a set of simple rules.

## Features

The parser can currently produce html for the following markdown elements:

- Headers (level 1 - 6)
- Paragraphs
- Italics
- Bold text

The grammar handles nested bold and italics, so it is possible to italicize text within a bold block and vice versa. The grammar also accepts italics withing italics, however there are currently no rules for how to translate these to html.

This guide is used as a reference for markdown syntax and semantics.

https://www.markdownguide.org/basic-syntax

## Roadmap

- Code and block code
- Quotes and block quotes
- Ordered and unordered Lists
- Links
- Tables

# Usage

## CMake

Currently, the easiest way to get started is to use ```FetchContent``` with CMake.

```cmake
FetchContent_Declare(
        marky
        GIT_REPOSITORY "https://github.com/lambda-snail/marky.git"
        GIT_TAG v0.3.5
)

FetchContent_MakeAvailable(marky)
```

Then in the projects CMake you will need to add ```${marky_SOURCE_DIR}/include``` to your ```target_include_directories``` and then add ```marky``` to ```target_link_libraries```.

At the moment, the parser does not try to hide the dependency on Antlr4. You do not have to link against antlr4, but you will need to include the header files. Marky provides a CMake variable to make this process simple.

Thus, you should have something similar to this in your projects CMake file in order to use the parser:

```cmake
target_include_directories(my_awesome_project
        ...
        PRIVATE
        ${marky_ANTLR_INCLUDE_DIRS}
        ${marky_SOURCE_DIR}/include
)
```

## In Code

Currently, to produce html requires two components: an instance of ```MarkdownToHtml``` and an instance of ```Marky```.

- ```Marky``` is the class that kick-starts the parsing process.
- ```MarkdownToHtml``` is the backend that walks the markdown-syntax-tree and outputs html.

These two can be combined in the following way:

```cpp
#include <marky/Marky.h>
#include <marky/backend/html_backend.h>

marky::Marky marky;
marky::backend::html::MarkdownToHtml backend;

marky.process_markdown(backend, markdown);
auto html = backend.get_html();
```

# Generating the Parser

To (re-)generate the parser when working with the code, the following command can be given from the project root on Windows. 

```ps
.\generate_parser.ps1
```