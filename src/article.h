#pragma once

class Iterator;
class ArticleVisitor;

class Article {
   public:
    virtual ~Article(){};

    virtual std::string getText() = 0;

    virtual int getLevel() = 0 ;

    virtual Iterator* createIterator() = 0;

    virtual void accept(ArticleVisitor* visitor) = 0;

    virtual void add(Article* dpFormat){};
};