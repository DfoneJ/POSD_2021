#pragma once

#include <stdio.h>
#include <exception>
#include "article.h"
//#include "iterator/null_iterator.h"
#include "visitor/article_visitor.h"

class Text : public Article {
    public:
        Text(std::string text) { _text = text; }

        ~Text() {}

        std::string getText() const override { return _text; }

        std::string getFullText() const override { return _text; }

        std::string getHtmlText() const override { return "<span>" + _text + "</span>"; } //<span>text</span>

        int getLevel() const override { return 0; }

        //Iterator* createIterator() override { /*return new NullIterator();*/ }

        void accept(ArticleVisitor* visitor) override { visitor->visitText(this); } // DO

        void add(Article* dpFormat) override { throw std::string("Text cannot do add!"); }
    private:
        std::string _text=""; 
};
