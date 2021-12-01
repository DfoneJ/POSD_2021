#ifndef ARTICLE_H
#define ARTICLE_H

class Article {
   public:
    virtual ~Article(){};

    virtual std::string getText() const = 0;

    virtual int getLevel() const = 0;

    virtual void add(Article* dpFormat){};
};

#endif