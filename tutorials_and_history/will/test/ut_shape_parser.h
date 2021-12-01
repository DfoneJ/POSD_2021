#pragma once
#include <deque>
#include <set>

#include "../src/shape_builder.h"
#include "../src/scanner.h"

class ShapeParser {
    public:
        ShapeParser(std::string input) {
            cout << "ShapeParser:" << input << endl;
            // initialize a scanner for handling input.
            // initialize a shape builder for handling building shape.
            scanner = new Scanner(input);
            sb = new ShapeBuilder();
        }

    void parser() {

        strVec.clear();
        // using Scanner::nextToken() to get all information to determine what to build,
        // and provide the argument the shape needed.
        // use functions in ShapeBuilder to build out the shape.
        // the shape with invalid argument should be ignored (see example bellow).
        try {
            std::string str = scanner -> nextToken();

            while (str.length() > 0) {
                // if not in the set ,add into vector
                strVec.push_back(str);
                if( str==")"){
                    handingSimpleShape();
                }
                if (str == "CompoundShape") {
                    
                    sb->buildCompoundShapeBegin();
                } else if (str == "}") {
                    
                    sb->buildCompoundShapeEnd();
                }

                str = scanner -> nextToken();
            }
        } catch (std::string e) {

        }
    }
    void handingSimpleShape() {
        cout << "strVec" << endl;
        for (int i = 0; i < strVec.size(); i++) {
            cout << strVec.at(i) << endl;
        }
        if (strVec.at(0) == "Triangle") {
            if(strVec.size()<14){return ;}
            if(strVec.at(13)==")" ) {
                sb -> buildTriangle(std::stod(strVec.at(2)), std::stod(strVec.at(4)), std::stod(strVec.at(6)), std::stod(strVec.at(8)), std::stod(strVec.at(10)), std::stod(strVec.at(12)));
            }
            
            strVec.erase(strVec.begin(), strVec.begin() + 13);
           
            
            
        } else if (strVec.at(0) == "Ellipse") {
            if(strVec.size()<6){return ;}
            if(strVec.at(5)==")"){
                sb -> buildEllipse(std::stod(strVec.at(2)), std::stod(strVec.at(4)));
            }
            
            strVec.erase(strVec.begin(), strVec.begin() + 5);
           

        } else if (strVec.at(0) == "Rectangle") {
            if(strVec.size()<6){return ;}
            if(strVec.at(5)==")"){
                sb -> buildRectangle(std::stod(strVec.at(2)), std::stod(strVec.at(4)));
            }
            strVec.erase(strVec.begin(), strVec.begin() + 5);
           
        } else if (strVec.at(0) == "CompoundShape"||strVec.at(0) =="}") {
           return;
        } 
        
         //clean the trash 
        else {
            if(strVec.size()==0){
                return;
            }
            // cout << "       else" << endl;
            while (shapeSet.find(strVec.at(0)) == shapeSet.end()) {
                strVec.erase(strVec.begin());
            }
            // cout << "strVec 2 " << endl;
            // for (int i = 0; i < strVec.size(); i++) {
            //     cout << strVec.at(i) << endl;
            // }
            handingSimpleShape();
        }
    }
   
    std::deque < Shape * > getResult() {
        // return result.
        return sb -> getResult();

    }
    private:
    int flag = 0;
    Scanner * scanner;
    ShapeBuilder * sb;
    std::vector < std::string > strVec;
    std::deque < Shape * > result;
    
    std::set < string > shapeSet {
        "Triangle",
        "Ellipse",
        "Rectangle"
    };
};