#pragma once

#include "article_visitor.h"

class MarkdownVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override{ _result = "- " + li->getText() + "\n" ;}

    void visitText(Text* t) override{ _result = t->getText() + "\n" ;}

    void visitParagraph(Paragraph* p) override{
        std::string P_result="";
        for(int i=1; i<=p->getLevel(); i++) { P_result += "#"; }
        P_result = P_result + " " + p->getText() + "\n"; // # title
        Iterator* pit = p->createIterator();
        for(pit->first(); !pit->isDone(); pit->next()) {
            pit->currentItem()->accept(this);
            P_result += this->getResult();
        }
        _result = P_result;
    }

    std::string getResult() const override { return _result; }
private:
    std::string _result="";
};