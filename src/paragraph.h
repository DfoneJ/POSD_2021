#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include <stdio.h>
#include <exception>
#include <iostream>
#include "article.h"

class Paragraph : public Article {
    public:
        Paragraph(int level, std::string text) {
            if(level<1)
                throw std::string("level cannot smaller than 1");
            else if(level >6)
                throw std::string("level cannot greater than 6");
            else{
                _level = level;
                for(int i=1;i<=_level;i++)
                    _text = "#"+_text;
                _text = _text+" "+text;
            }
        }

        ~Paragraph() {}

        std::string getText() const override {
            return _text;
        }

        int getLevel() const override {
            return _level;
        }

        void add(Article* content) override {
            if(content->getLevel()!=0 and content->getLevel()<_level){
                throw std::string("cannot add smaller level paragraph to greater level paragraph!");
            }
            else{
                _text = _text + "\n";
                _text = _text + content->getText();
            }
        }
    private:
        std::string _text="";
        int _level;


};

#endif