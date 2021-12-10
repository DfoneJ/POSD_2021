#pragma once

#include <vector>
#include <exception>
#include <string>
#include <iostream>

class Scanner {
public:
    Scanner(std::string input): _input(input) {}

    std::string next() {  // 預設不會是空input, 一定會有一個以上的 token
        if(isDone()) { throw std::string("Scanning Is Done!"); }
        std::string result ="";
        int nearestPos = _input.length();
        int tokenIdx = -1;
        for(std::string token : tokenList) { // scan every token
            if(_input.find(token,pos)!=std::string::npos) { //- check token exist
                tokenIdx = _input.find(token,pos);
                if(nearestPos>tokenIdx) {          //-- refresh nearest token
                    nearestPos = tokenIdx;
                    result = token;
                }
            }
        }
        pos = nearestPos + result.length(); // refresh pos
        if(!hasNextToken()) pos = _input.length(); // if we dont have next token, then done
        return result;
    }

    double nextDouble() { // 預設最少有一次正確資料
        std::string result ="";
        bool findDouble = false;
        bool hasDot = false;
        skipNotNum();
        while(isDigit(_input[pos])) {
            result += _input[pos];
            pos++;
        }
        if(isDot(_input[pos]) && isDigit(_input[pos+1])) {
            result += _input[pos];
            pos++;
        }
        while(isDigit(_input[pos])) {
            result += _input[pos];
            pos++;
        }
        return std::stod(result);
    }

    bool isDone() { return pos>=_input.length(); }

private:
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    const std::vector<std::string> DigitList = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::string _input ="";
    std::size_t pos = 0;
    bool hasNextToken() {
        for(std::string token : tokenList) {
            if(_input.find(token,pos)>=0) return true;
        }
        return false;
    }
    void skipNotNum() { while(_input[pos]<'0'||_input[pos]>'9') pos++; }
    bool isDot(char c) { return c=='.'; }
    bool isDigit(char c) { return c>='0' && c<='9'; }
};