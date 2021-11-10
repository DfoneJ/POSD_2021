#ifndef SCANNER_H
#define SCANNER_H
#include <regex>
#include <iostream>
#include <string>
#include <vector>

class Scanner {
public:
    Scanner(std::string input): _input(input) {
        _currentTokenIdx = 0;
        int current = 0;
        int next = _input.find_first_of(",(){} ", current);
        while (next != string::npos) {
            int length = next - current > 0 ? next - current : 1;
            addToVector(_input.substr(current, length));
            if(current != next)
                addToVector(_input.substr(next, 1));
            current = next + 1;
            next = _input.find_first_of(",(){} ", current);
        }
    }
    void addToVector(std::string str) {
        if(str != " ")
            _ans_vector.push_back(str);
    }

    std::string nextToken() {
        if (_ans_vector.size()>0){
             std::string ans = _ans_vector.at(0);
            _ans_vector.erase(_ans_vector.begin());
            return ans;
        }else{
            throw std::string("next char doesn't exist.");
        }
    }

private:
    int _currentTokenIdx=0;
    std::string _input="";
    std::vector<std::string> _ans_vector;

};
#endif