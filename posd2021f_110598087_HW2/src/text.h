#ifndef TEXT_H
#define TEXT_H
#include <stdio.h>
#include <exception>
#include <iostream>
#include "article.h"

using namespace std;
using std::exception;

class Text : public Article {
    public:
        Text(std::string text) {
            _text = text;
        }

        ~Text() {}

        std::string getText() const override {
            return _text;
        }

        int getLevel() const override {
            return 0;
        }

        void add(Article* content) override {
            throw std::string("Text cannot do add!");
        }
    private:
        std::string _text=""; 
};

#endif 