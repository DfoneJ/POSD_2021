#pragma once

#include <exception>
#include <fstream>
#include <sstream>
#include "article_scanner.h"
#include "article_builder.h"
#include <iostream>

class ArticleParser {
public:
    // `filePath` is a relative path of makefile
    ArticleParser(std::string filePath) {
        std::ifstream infile(filePath);
        std::string line;
        while (std::getline(infile, line)) _input += line;
        infile.close();
        _scanner = new ArticleScanner(_input);
    } // OK

    ~ArticleParser() { delete _scanner; } // OK

    void parse() {
        std::string token="";
        while(!_scanner->isDone()) {
            token = _scanner->nextToken();
            // std::cout << token << std::endl;
            if(token == "ListItem") {
                if(_scanner->nextToken() != "(") { throw std::string("Invalid input !"); }
                std::string text = _scanner->nextStr();
                if(_scanner->nextToken() != ")") { throw std::string("Invalid input !"); }
                _builder->buildListItem(text);
            }
            else if(token == "Text") {
                if(_scanner->nextToken() != "(") { throw std::string("Invalid input !"); }
                std::string text = _scanner->nextStr();
                if(_scanner->nextToken() != ")") { throw std::string("Invalid input !"); }
                _builder->buildText(text);
            }
            else if(token == "Paragraph") {
                if(_scanner->nextToken() != "(") { throw std::string("Invalid input !"); }
                int level = _scanner->nextInt();
                std::string text = _scanner->nextStr();
                if(_scanner->nextToken() != ")") { throw std::string("Invalid input !"); }
                if(_scanner->nextToken() != "{") { throw std::string("Invalid input !"); }
                _builder->buildParagraphBegin(level, text);
            }
            else if(token == "}") _builder->buildParagraphEnd();
        }
    }

    Article* getArticle() {
        Article* result = _builder->getArticle();
        _builder->reset();
        return result;
    } // OK
private:
    std::string _input ="";
    ArticleScanner* _scanner;
    ArticleBuilder* _builder = ArticleBuilder::getInstance();
};
