#pragma once

#include <stack>
#include "../text.h"
#include "../list_item.h"
#include "../paragraph.h"

class ArticleBuilder {
public:
    static ArticleBuilder* getInstance() {
        static ArticleBuilder instance;
        return &instance;
    } // OK

    ~ArticleBuilder() { reset();} // OK

    void buildListItem(std::string text) { _articleStack.push(new ListItem(text)); } // OK

    void buildText(std::string text) { _articleStack.push(new Text(text)); } // OK

    void buildParagraphBegin(int level, std::string text) { _articleStack.push(new Paragraph(level, text)); } // OK

    void buildParagraphEnd() {
        std::stack<Article*> components;
        while( !isParagraph(_articleStack.top()) || isNoneEmptyParagraph(_articleStack.top()) ) {
            components.push(_articleStack.top());
            _articleStack.pop();
        }
        while(!components.empty()) {
            _articleStack.top()->add(components.top());
            components.pop();
        }
    } // OK

    Article* getArticle() {
        if(!_articleStack.empty()) {
            Article* result = _articleStack.top();
            _articleStack.pop();
            return result;
        }
        else {
            Article* result = nullptr;
            return result;
        }
    } // OK

    void reset() {
        while(!_articleStack.empty()) {
            Article* article = _articleStack.top();
            _articleStack.pop();
            delete article;
        }
    } // OK
private:
    ArticleBuilder(){};
    std::stack<Article*> _articleStack;
    bool isParagraph(Article* a) { return a->getLevel()!=0; }
    bool isNoneEmptyParagraph(Article* a) {
            Iterator* pit = a->createIterator();
            bool done = pit->isDone();
            delete pit;
            return isParagraph(a)&&!done;
        }
};
