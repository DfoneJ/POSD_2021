#pragma once

#include "article.h"
#include "iterator/null_iterator.h"
#include "visitor/article_visitor.h"

class ListItem : public Article {
    public:
        ListItem(std::string text) { _text = text; } // OK

        ~ListItem() {}

        std::string getText() const override { return _text; } // OK

        int getLevel() const override { return 0; } // OK

        Iterator* createIterator() override { return new NullIterator(); } // OK

        void accept(ArticleVisitor* visitor) override { visitor->visitListItem(this); } // OK

        void add(Article* dpFormat) override { throw std::string("ListItem cannot do add!"); } // OK
    private:
        std::string _text=""; 
};
