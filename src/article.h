#pragma once

class Iterator;
class ArticleVisitor;

class Article {
   public:
    virtual ~Article(){};

    virtual std::string getText() const = 0;

    virtual std::string getFullText() const = 0;

    virtual std::string getHtmlText() const = 0;

    virtual int getLevel() const {}

    virtual Iterator* createIterator() = 0;

    virtual void accept(ArticleVisitor* visitor) = 0;

    virtual void add(Article* dpFormat){};
};