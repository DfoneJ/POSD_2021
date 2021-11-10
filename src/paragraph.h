#pragma once

#include <stdio.h>
#include <exception>
#include <list>
#include "article.h"
#include "iterator/compound_iterator.h"
#include "visitor/article_visitor"

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
        }
    }

    ~Paragraph() {}

    std::string getText() const override { return _original_text; }

    int getLevel() const override { return _level; }

    Iterator* createIterator() override { return new CompoundIterator<std::list<Article *>::const_iterator>(_articles.begin(), _articles.end()); }

    void accept(ArticleVisitor* visitor) override { visitor->visitParagraph(this); } // DO

    void add(Article* dpFormat) override {
        if(dpFormat->getLevel()!=0 and dpFormat->getLevel()<=_level){
            throw std::string("cannot add smaller or equal level paragraph!");
        }
        else{
            _text = _text + "\n";
            _text = _text + dpFormat->getText();
            _articles.push_back(dpFormat);
        }
    }
private:
    std::string _text="";
    std::string _original_text="";
    std::list<Article*> _articles;
    int _level;
};
