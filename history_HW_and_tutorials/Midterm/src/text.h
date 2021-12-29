#pragma once

#include "article.h"
#include "iterator/null_iterator.h"
#include "visitor/article_visitor.h"

class Text : public Article {
    public:
        Text(std::string text) { _text = text; } // OK

        ~Text() {}

        std::string getText() const override { return _text; } // OK

        int getLevel() const override { return 0; } // OK

        Iterator* createIterator() override { return new NullIterator(); } // OK

        void accept(ArticleVisitor* visitor) override { visitor->visitText(this); } // OK

        void add(Article* dpFormat) override { throw std::string("Text cannot do add!"); } // OK
    private:
        std::string _text=""; 
};
