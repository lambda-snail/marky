# marky
 A simple parser for markdown based on Boost::Spirit

# Generating the Parser

To (re-)generate the parser the following command can be given from the project root. 

```sh
java -jar .\third_party\antlr-4.13.0-complete.jar -Dlanguage=Cpp -listener -visitor -o src/generated/ -package marky .\Markdown.g4
```