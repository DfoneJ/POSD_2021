#pragma once

#include <vector>
#include <exception>
#include <string>
#include <algorithm>
#include <iostream>

class ArticleScanner {
public:
    ArticleScanner(std::string input) {
        _input = input;
        skipWhiteSpace();
    }

    std::string nextToken() {
        if(noTokens) throw std::string("Already met the end");
        int nearest_pos = _input.length();
        int token_pos = 0;
        std::string result ="";
        for(std::string token : tokenList){ // find every token in the remaining part of input
            if(_input.find(token,pos)!=std::string::npos) { // - token exist
                token_pos = _input.find(token,pos);
                if(token_pos < nearest_pos) { // -- compare the nearest token
                    nearest_pos = token_pos;
                    result = token;
                }
            }
        }
        if(nearest_pos == _input.length()) { // no token exist in the remaining part of input
            noTokens = true;
            throw std::string("Already met the end");
        }
        pos = nearest_pos + result.length();
        skipWhiteSpace();
        return result;
    } // OK

    int nextInt() {
        if(isDone()) throw std::string("Already met the end");
        skipNotNum();
        if(isDone()) throw std::string("Already met the end");
        std::string result ="";
        while(!isDone()) {
            if(isDigit(_input[pos])) {
                result += _input[pos];
                pos++;
            }
            else break;
        }
        skipWhiteSpace();
        return std::stoi(result);
    } // OK

    std::string nextStr() {
        if(isDone()) throw std::string("Already met the end");
        findQuote(); // find head quote
        if(isDone()) throw std::string("Already met the end");
        pos++;
        int startPos = pos;// skip head quote of string
        findQuote(); // find end quote
        if(isDone()) throw std::string("Already met the end");
        int endPos = pos;// back 1 pos of end quote
        std::string result ="";
        for(int i=startPos; i<endPos; i++) result += _input[i];
        skipWhiteSpace();
        return result;
    } // OK

    bool isDone(){ return pos >= _input.length(); }

private:
    std::string _input="";
    const std::vector<std::string> tokenList = {"ListItem", "Text", "Paragraph", "(", ")", "{", "}"};
    int pos = 0;
    bool noTokens = false;

    void skipWhiteSpace() {
        while(!isDone()) {
            if(_input[pos]==' ' || _input[pos]=='\n') pos++;
            else break;
        }
    }

    void skipNotNum() {
        if(!isDone()) {
            while((_input[pos]<'0'||_input[pos]>'9') && !isDone()) pos++;
        }
    }

    void findQuote() {
        if(!isDone()) {
            while((_input[pos]!='\"')&&!isDone()) pos++;
        }
    }

    bool isDigit(char c) {
        if(isDone()) return false;
        else return c>='0' && c<='9';
    }
};