java -jar .\third_party\antlr-4.13.0-complete.jar -Dlanguage=Cpp -listener -visitor -o src/generated/ -package marky .\Markdown.g4
mkdir -Force include/marky/parser/
rm include/marky/parser/*.cpp
mv src/generated/*.cpp include/marky/parser/