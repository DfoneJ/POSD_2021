#include "../../src/builder/article_builder.h"
#include "../../src/visitor/markdown_visitor.h"

TEST(CaseBuilder, Creation) {
    ArticleBuilder* builder = ArticleBuilder::getInstance();
    Article* result = builder->getArticle();
    ASSERT_TRUE(result==nullptr);
    delete result;
}

TEST(CaseBuilder, BuildText) {
    ArticleBuilder* builder = ArticleBuilder::getInstance();
    builder->buildText("This is a text");
    Article* result = builder->getArticle();
    ASSERT_EQ(result->getText(), "This is a text");
    delete result;
}

TEST(CaseBuilder, BuildList) {
    ArticleBuilder* builder = ArticleBuilder::getInstance();
    builder->buildListItem("This is a list item");
    Article* result = builder->getArticle();
    ASSERT_EQ(result->getText(), "This is a list item");
    delete result;
}

TEST(CaseBuilder, BuildEmptyParagraph) {
    ArticleBuilder* builder = ArticleBuilder::getInstance();
    builder->buildParagraphBegin(1, "This is an empty paragraph");
    builder->buildParagraphEnd();
    Article* result = builder->getArticle();
    MarkdownVisitor* visitor = new MarkdownVisitor();
    result->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "# This is an empty paragraph\n");
    delete result;
    delete visitor;
}

TEST(CaseBuilder, BuildSimpleParagraph) {
    ArticleBuilder* builder = ArticleBuilder::getInstance();
    builder->buildParagraphBegin(1, "This is a simple paragraph");
    builder->buildListItem("This is a list item");
    builder->buildText("This is a text");
    builder->buildParagraphEnd();
    Article* result = builder->getArticle();
    MarkdownVisitor* visitor = new MarkdownVisitor();
    result->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "# This is a simple paragraph\n- This is a list item\nThis is a text\n");
    delete result;
    delete visitor;
}

TEST(CaseBuilder, BuildComplexParagraph) {
    ArticleBuilder* builder = ArticleBuilder::getInstance();
    builder->buildParagraphBegin(1, "This is a complex paragraph");
    builder->buildListItem("This is a list item");
    builder->buildParagraphBegin(2, "This is an inner paragraph");
    builder->buildText("This is an inner text");
    builder->buildListItem("This is an inner list item");
    builder->buildParagraphEnd();
    builder->buildText("This is a text");
    builder->buildParagraphEnd();
    Article* result = builder->getArticle();
    MarkdownVisitor* visitor = new MarkdownVisitor();
    result->accept(visitor);
    ASSERT_EQ(visitor->getResult(), "# This is a complex paragraph\n- This is a list item\n## This is an inner paragraph\nThis is an inner text\n- This is an inner list item\nThis is a text\n");
    delete result;
    delete visitor;
}