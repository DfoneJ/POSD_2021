#pragma once

#include <stdio.h>
#include <exception>
#include "article.h"
//#include "iterator/null_iterator.h"
#include "visitor/article_visitor.h"

class ListItem : public Article {
    public:
        ListItem(std::string text) { _text = text; }

        ~ListItem() {}

        std::string getText() const override { return _text; }

        std::string getFullText() const override { return "- " + _text; }

        std::string getHtmlText() const override { return "<li>" + _text + "</li>"; } //<li>list1</li>

        int getLevel() const override { return 0; }

        //Iterator* createIterator() override {/* return new NullIterator(); */}

        void accept(ArticleVisitor* visitor) override { visitor->visitListItem(this); } // DO

        void add(Article* dpFormat) override { throw std::string("ListItem cannot do add!"); }
    private:
        std::string _text=""; 
};
