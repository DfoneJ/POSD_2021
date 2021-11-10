#pragma once

#include <stdio.h>
#include <exception>
#include "article.h"
#include "iterator/null_iterator.h"
#include "visitor/article_visitor"

class ListItem : public Article {
    public:
        ListItem(std::string text) { _text = "- "+text; }

        ~ListItem() {}

        std::string getText() const override { return _text; }

        int getLevel() const override { return 0; }

        Iterator* createIterator() override { return new NullIterator(); }

        void accept(ArticleVisitor* visitor) override { visitor->visitListItem(this); } // DO

        void add(Article* dpFormat) override { throw std::string("ListItem cannot do add!"); }
    private:
        std::string _text=""; 
};
