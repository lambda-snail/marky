# Marky

A simple parser for markdown based on Antlr4. It converts markdown to html based on a set of simple rules.

## Features

The parser can currently produce html for the following markdown elements:

- Headers (level 1 - 6)
- Paragraphs
- Italics
- Bold text

The grammar handles nested bold and italics, so it is possible to italicize text within a bold block and vice versa. The grammar also accepts italics withing italics, however there are currently no rules for how to translate these to html.  

## Roadmap

- Lists
- Links
- Tables

# Usage

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