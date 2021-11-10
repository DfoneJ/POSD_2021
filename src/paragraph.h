#pragma once

#include <stdio.h>
#include <exception>
#include <list>
#include "article.h"
#include "iterator/compound_iterator.h"
#include "visitor/article_visitor.h"

typedef CompoundIterator<std::list<Article *>::iterator> CompoundArticleIterator;

class Paragraph : public Article {
public:
    Paragraph(int level, std::string text) {
        if(level<1)
            throw std::string("level cannot smaller than 1");
        else if(level>6)
            throw std::string("level cannot greater than 6");
        else{
            _level = level;
            for(int i=1;i<=_level;i++)
                _text = "#"+_text;
            _text = _text+" "+text;
            _original_text = _text;
            _HtmlText = _text;
        }
    }

    ~Paragraph() {}

    std::string getText() const override { return _original_text; }

    std::string getFullText() const override { return _text; }

    std::string getHtmlText() const override { return "<div>" + _HtmlText + "</div>"; } //<span>text</span>

    int getLevel() const override { return _level; }

    Iterator* createIterator() override { return new CompoundArticleIterator(_articles.begin(), _articles.end()); }

    void accept(ArticleVisitor* visitor) override { visitor->visitParagraph(this); } // DO

    void add(Article* dpFormat) override {
        if(dpFormat->getLevel()!=0 and dpFormat->getLevel()<=_level){
            throw std::string("cannot add smaller or equal level paragraph!");
        }
        else{
            _text = _text + "\n";
            _text = _text + dpFormat->getText();
            _HtmlText = _HtmlText + dpFormat->getHtmlText();
            _articles.push_back(dpFormat);
        }
    }
private:
    std::string _text="";
    std::string _HtmlText="";
    std::string _original_text="";
    std::list<Article*> _articles;
    int _level;
};
