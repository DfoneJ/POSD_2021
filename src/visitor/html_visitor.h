#pragma once

#include "article_visitor.h"
#include <string>

class HtmlVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override { _result = "<li>"+ li->getText() +"</li>"; } // OK

    void visitText(Text* t) override { _result = "<span>"+ t->getText() +"</span>"; } // OK

    void visitParagraph(Paragraph* p) override {
        std::string P_result="";
        P_result = P_result + "<h>" + p->getText() + "</h>";
        Iterator* pit = p->createIterator();
        for(pit->first(); !pit->isDone(); pit->next()) {
            pit->currentItem()->accept(this);
            P_result += this->getResult();
        }
        delete pit;
        _result = P_result;
    }

    std::string getResult() const override { return _result; } // OK
private:
    std::string _result="";
};