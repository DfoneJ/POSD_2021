#include "../../src/builder/article_scanner.h"

TEST(CaseScanner, Text) {
    std::string data_txt = std::string("Text (\"This is a text\")");
    ArticleScanner* scanner = new ArticleScanner(data_txt);
    ASSERT_EQ("Text", scanner->nextToken());
    ASSERT_EQ("(", scanner->nextToken());
    ASSERT_EQ("This is a text", scanner->nextStr());
    ASSERT_EQ(")", scanner->nextToken());
    try {
        scanner->nextToken();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    try {
        scanner->nextInt();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    try {
        scanner->nextStr();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    delete scanner;
}

TEST(CaseScanner, List) {
    std::string data_txt = std::string("ListItem (\"This is a list item\")");
    ArticleScanner* scanner = new ArticleScanner(data_txt);
    ASSERT_EQ("ListItem", scanner->nextToken());
    ASSERT_EQ("(", scanner->nextToken());
    ASSERT_EQ("This is a list item", scanner->nextStr());
    ASSERT_EQ(")", scanner->nextToken());
    try {
        scanner->nextToken();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    try {
        scanner->nextInt();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    try {
        scanner->nextStr();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    delete scanner;
}

TEST(CaseScanner, EmptyParagraph) {
    std::string data_txt = std::string("Paragraph (1 \"This is an empty paragraph\") {}");
    ArticleScanner* scanner = new ArticleScanner(data_txt);
    ASSERT_EQ("Paragraph", scanner->nextToken());
    ASSERT_EQ("(", scanner->nextToken());
    ASSERT_EQ(1, scanner->nextInt());
    ASSERT_EQ("This is an empty paragraph", scanner->nextStr());
    ASSERT_EQ(")", scanner->nextToken());
    ASSERT_EQ("{", scanner->nextToken());
    ASSERT_EQ("}", scanner->nextToken());
    try {
        scanner->nextToken();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    try {
        scanner->nextInt();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    try {
        scanner->nextStr();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    delete scanner;
}

TEST(CaseScanner, SimpleParagraph) {
    std::string data_txt = std::string("Paragraph (1 \"This is a simple paragraph\") {\n    ListItem (\"This is a list item\")\n    Text (\"This is a text\")\n}  \n ");
    ArticleScanner* scanner = new ArticleScanner(data_txt);
    ASSERT_EQ("Paragraph", scanner->nextToken());
    ASSERT_EQ("(", scanner->nextToken());
    ASSERT_EQ(1, scanner->nextInt());
    ASSERT_EQ("This is a simple paragraph", scanner->nextStr());
    ASSERT_EQ(")", scanner->nextToken());
    ASSERT_EQ("{", scanner->nextToken());
    ASSERT_EQ("ListItem", scanner->nextToken());
    ASSERT_EQ("(", scanner->nextToken());
    ASSERT_EQ("This is a list item", scanner->nextStr());
    ASSERT_EQ(")", scanner->nextToken());
    ASSERT_EQ("Text", scanner->nextToken());
    ASSERT_EQ("(", scanner->nextToken());
    ASSERT_EQ("This is a text", scanner->nextStr());
    ASSERT_EQ(")", scanner->nextToken());
    ASSERT_EQ("}", scanner->nextToken());
    ASSERT_TRUE(scanner->isDone());
    try {
        scanner->nextToken();
        FAIL();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    try {
        scanner->nextInt();
        FAIL();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    try {
        scanner->nextStr();
        FAIL();
    }catch (std::string e) {
        ASSERT_EQ("Already met the end", e);
    }
    delete scanner;
}