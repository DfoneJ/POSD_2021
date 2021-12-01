#include "filter.h"

typedef void (*SettingFunction)(Shape *);

class ShapeSetter : public Filter {
public:

    ShapeSetter(SettingFunction set) {
        // `Setter` is a template name for lambda,
        //  you may use your own name.
        shapeSettingFunc = set;
    }
    Filter* setNext(Filter* filter) {
        // setting next filter.
        nextFil = filter;
        return nextFil;
    }

    std::list<Shape*> push(std::list<Shape*> shapes) {
        // push down setted data and return result.
        for (auto shape = shapes.begin();shape!=shapes.end();shape++){
            shapeSettingFunc(*shape);
            shapeList.push_back(*shape);
        }
        if (nextFil==nullptr){
            //顯示用
            // for (auto shape = shapeList.begin();shape!=shapeList.end();shape++){
            //     cout<<(*shape)->info()<<endl;
            // }
            return shapeList;
        }   
        else {
            return nextFil->push(shapeList);
        }
    }
private:
    std::list<Shape*> shapeList;
    Filter* nextFil = nullptr;
    SettingFunction shapeSettingFunc;
};