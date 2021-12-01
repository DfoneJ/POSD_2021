#ifndef LIST_ITEM_H
#define LIST_ITEM_H
#include <stdio.h>
#include <exception>
#include <iostream>
#include "article.h"

using namespace std;
using std::exception;

class ListItem : public Article {
    public:
        ListItem(std::string text) {
            _text = "- "+text;
        }

        ~ListItem() {}

        std::string getText() const override {
            return _text;
        }

        int getLevel() const override {
            return 0;
        }

        void add(Article* content) override {
            throw std::string("ListItem cannot do add!");
        }
    private:
        std::string _text=""; 
};

#endif