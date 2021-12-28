#pragma once

#include <stdio.h>
#include <exception>
#include <list>
#include "article.h"
//#include "iterator/compound_iterator.h"
#include "visitor/article_visitor.h"
#include <string>

class Paragraph : public Article {
public:
    Paragraph(int level, std::string text) {
        if(level<1)
            throw std::string("level cannot smaller than 1");
        else if(level>6)
            throw std::string("level cannot greater than 6");
        else{
            _level = level;
            _s_level = std::to_string(level);
            _text = text;
            _HtmlText = "<h"+_s_level+">"+text+"</h"+_s_level+">";
            for(int i=1;i<=_level;i++)
                _FullText = "#" + _FullText;
            _FullText = _FullText+" "+text;
        }
    }

    ~Paragraph() {}

    std::string getText() const override { return _text; }

    std::string getFullText() const override { return _FullText; } // Markdown

    std::string getHtmlText() const override { return "<div>" + _HtmlText + "</div>"; } //<div><h1>title</h1></div>

    int getLevel() const override { return _level; }

    //Iterator* createIterator() override { /*return new CompoundIterator<std::list<Article *>::const_iterator>(_articles.begin(), _articles.end()); */}

    void accept(ArticleVisitor* visitor) override { visitor->visitParagraph(this); } // DO

    void add(Article* dpFormat) override {
        if(dpFormat->getLevel()!=0 and dpFormat->getLevel()<=_level){
            throw std::string("cannot add smaller or equal level paragraph!");
        }
        else{
            _FullText = _FullText + "\n" + dpFormat->getFullText();
            _HtmlText = _HtmlText + dpFormat->getHtmlText();
            _articles.push_back(dpFormat);
        }
    }
private:
    std::string _text="";
    std::string _FullText="";
    std::string _HtmlText="";
    std::list<Article*> _articles;
    int _level;
    std::string _s_level ="";
};