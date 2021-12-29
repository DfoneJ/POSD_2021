#pragma once

#include "article_visitor.h"

class HtmlVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override{ _result = li->getText(); }

    void visitText(Text* t) override{ _result = t->getText(); }

    void visitParagraph(Paragraph* p) override{ _result = p->getText(); }

    std::string getResult() const override { return _result; }
private:
    std::string _result;
};