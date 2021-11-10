#pragma once

#include "article_visitor.h"

class MarkdownVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override{ _result = li->getText() + "\n" ;}

    void visitText(Text* t) override{ _result = t->getText() + "\n" ;}

    void visitParagraph(Paragraph* p) override{ _result = p->getFullText() + "\n" ;}

    std::string getResult() const override { return _result; }
private:
    std::string _result;
};