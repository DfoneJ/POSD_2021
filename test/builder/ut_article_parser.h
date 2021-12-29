#include "../../src/builder/article_parser.h"
#include "../../src/visitor/markdown_visitor.h"

TEST(CaseParser, Text) {
    std::string filepath = "test/data/text.txt";
    ArticleParser* parser = new ArticleParser(filepath);
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is a text", result->getText());
    ASSERT_EQ(result->getLevel(), 0);
    delete parser;
    delete result;
}

TEST(CaseParser, List) {
    std::string filepath = "test/data/list_item.txt";
    ArticleParser* parser = new ArticleParser(filepath);
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is a list item", result->getText());
    ASSERT_EQ(result->getLevel(), 0);
    delete parser;
    delete result;
}

TEST(CaseParser, BuildEmptyParagraph) {
    std::string filepath = "test/data/empty_paragraph.txt";
    ArticleParser* parser = new ArticleParser(filepath);
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is an empty paragraph", result->getText());
    ASSERT_EQ(result->getLevel(), 1);
    delete parser;
    delete result;
}

TEST(CaseParser, BuildSimpleParagraph) {
    std::string filepath = "test/data/simple_paragraph.txt";
    ArticleParser* parser = new ArticleParser(filepath);
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is a simple paragraph", result->getText());
    ASSERT_EQ(result->getLevel(), 1);
    MarkdownVisitor* visitor = new MarkdownVisitor();
    result->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "# This is a simple paragraph\n- This is a list item\nThis is a text\n");
    delete parser;
    delete result;
    delete visitor;
}

TEST(CaseParser, BuildComplexParagraph) {
    std::string filepath = "test/data/complex_paragraph.txt";
    ArticleParser* parser = new ArticleParser(filepath);
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is a complex paragraph", result->getText());
    ASSERT_EQ(result->getLevel(), 1);
    MarkdownVisitor* visitor = new MarkdownVisitor();
    result->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "# This is a complex paragraph\n- This is a list item\n## This is an inner paragraph\nThis is an inner text\n- This is an inner list item\nThis is a text\n");
    delete parser;
    delete result;
    delete visitor;
}