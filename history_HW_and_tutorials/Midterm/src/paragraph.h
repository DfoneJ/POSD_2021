#pragma once

#include <list>
#include "article.h"
#include "iterator/compound_iterator.h"
#include "visitor/article_visitor.h"

class Paragraph : public Article {
public:
    Paragraph(int level, std::string text) {
        if(level<1) throw std::string("level cannot smaller than 1");
        else if(level>6) throw std::string("level cannot greater than 6");
        _level = level;
        _text = text;
    } // OK

    ~Paragraph() { for(Article* a : _articles) delete a; }

    std::string getText() const override { return _text; } // OK

    int getLevel() const override { return _level; } // OK

    Iterator* createIterator() override { return new CompoundIterator<std::list<Article*>::iterator>(_articles.begin(), _articles.end()); } // OK

    void accept(ArticleVisitor* visitor) override { visitor->visitParagraph(this); } //  OK

    void add(Article* article) override {
        if(article->getLevel()!=0 && article->getLevel()<=_level) throw std::string("Invalid level!");
        else _articles.push_back(article);
    } // OK
private:
    int _level;
    std::string _text="";
    std::list<Article*> _articles;
};
