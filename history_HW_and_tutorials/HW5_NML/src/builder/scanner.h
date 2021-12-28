#pragma once

#include <vector>
#include <exception>
#include <string>
#include <algorithm>
#include <iostream>

class Scanner {
public:
    Scanner(std::string input): _input(input) {
        std::string result = "";
        int endpos = _input.length();
        int nearestPos;
        int tokenIdx;
        while(pos<endpos) {
            nearestPos = endpos;
            tokenIdx = -1;
            result = "";
            for(std::string token : tokenList) { // scan every token
                if(_input.find(token,pos)!=std::string::npos) { //- check token exist
                tokenIdx = _input.find(token,pos);
                    if(nearestPos>tokenIdx) {          //-- refresh nearest token
                        nearestPos = tokenIdx;
                        result = token;
                    }
                }
            } // got nearest token OR get no token
            if(result != "") {
                Tokens.push_back(result);
                pos = nearestPos + result.length(); // refresh pos
            }
            else { pos = endpos; } // let find token end
        } // find token end.
        pos = 0;
        result = "";
        while(pos<endpos) {
            skipNotNum(); // jump to nearest digit pos, OR end
            result = "";
            if(pos<endpos) {
                while(isDigit(_input[pos])) {
                    result += _input[pos];
                    pos++;
                    if(pos>=endpos) { break; }
                } // met none-digit OR met the end
                if(pos<(endpos-1)) { //- Case : we have two or more cahr remained.
                    if(_input[pos]=='.' && isDigit(_input[pos+1])) { //-- Case : front one is dot & back one is digit
                        result += _input[pos];
                        pos++;
                        while(isDigit(_input[pos])) {
                            result += _input[pos];
                            pos++;
                            if(pos>=endpos) { break; }
                        }
                    }
                }
                Doubles.push_back(result);
            }
        }
        std::reverse(Tokens.begin(), Tokens.end());
        std::reverse(Doubles.begin(), Doubles.end());
    }

    std::string next() {
        if(Tokens.empty()) { throw std::string("No more token."); }
        std::string result = Tokens.back();
        Tokens.pop_back();
        return result;
    }

    double nextDouble() {
        if(Doubles.empty()) { throw std::string("No more doubles."); }
        std::string result = Doubles.back();
        Doubles.pop_back();
        return std::stod(result);
    }

    bool isDone() { return (Tokens.empty())&&(Doubles.empty()); }

private:
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    std::vector<std::string> Tokens = {};
    std::vector<std::string> Doubles = {};
    std::string _input ="";
    int pos = 0;
    void skipNotNum() { while((_input[pos]<'0'||_input[pos]>'9') && pos<_input.length()) pos++; }
    bool isDigit(char c) { return c>='0' && c<='9'; }
};