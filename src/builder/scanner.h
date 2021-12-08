#pragma once

#include <vector>
#include <string>

class Scanner {
public:
    Scanner(std::string input): _input(input) {} // OK

    std::string next() {
        std::string shapeResult="";
        skipNotToken();
        for(std::string token : shapeToken) {
            if((_input.compare(pos, token.length(), token)==0) && !scanEnded()) {
                pos += token.length();
                shapeResult = token;
            }
        }
        return shapeResult;
    }

    double nextDouble() {
        std::string numResult="";
        skipNotNum();
        while((isDigit(_input[pos])||isDot(_input[pos])) && !scanEnded()) {
            numResult += _input[pos];
            pos++;
        }
        return std::stod(numResult);
    }

    bool isDone() { return pos==_input.length() || pos>_input.length(); } // OK

private:
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
    const std::vector<std::string> shapeToken = {"Circle", "Rectangle", "Triangle", "CompoundShape", "}"};
    std::string _input ="";
    std::size_t pos = 0;

    void skipNotToken() { while(_input[pos]!='C' && _input[pos]!='R' && _input[pos]!='T' && _input[pos]!='}' && !scanEnded()) pos++; }
    void skipNotNum() { while((_input[pos]<48||_input[pos]>57) && !scanEnded()) pos++; }
    bool isDigit(char c) { return c>='0' && c<='9'; }
    bool isDot(char c) { return c=='.'; }
    bool scanEnded() { return pos>=_input.length(); }
};