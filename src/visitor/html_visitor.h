#pragma once

#include "article_visitor.h"
#include <string>
#include <stdio.h>

class HtmlVisitor : public ArticleVisitor {
public:
    void visitListItem(ListItem* li) override { _result = "<li>"+ li->getText() +"</li>"; } // OK

    void visitText(Text* t) override { _result = "<span>"+ t->getText() +"</span>"; } // OK

    void visitParagraph(Paragraph* p) override {
        std::string P_result="";
        char headquote[10];
        char endquote[10];
        sprintf(headquote, "<h%d>", p->getLevel());
        sprintf(endquote, "</h%d>", p->getLevel());
        P_result += "<div>";
        P_result = P_result + headquote + p->getText() + endquote;
        Iterator* pit = p->createIterator();
        for(pit->first(); !pit->isDone(); pit->next()) {
            pit->currentItem()->accept(this);
            P_result += this->getResult();
        }
        delete pit;
        P_result += "</div>";
        _result = P_result;
    }

    std::string getResult() const override { return _result; } // OK
private:
    std::string _result="";
};