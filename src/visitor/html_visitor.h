#pragma once

#include "article_visitor.h"

class HtmlVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override { }

    void visitText(Text* t) override { }

    void visitParagraph(Paragraph* p) override { }

    std::string getResult() const override { }
};