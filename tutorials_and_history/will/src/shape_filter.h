#include "filter.h"

typedef bool (*FilterFunction)(Shape *);
class ShapeFilter : public Filter {
public:

    ShapeFilter(FilterFunction pred){
        // `Predicate` is a template name for lambda,
        //  you may use your own name.
        shapePred = pred;
        // cout<<"in a new ShapeFilter"<<endl;
    }
         
    Filter* setNext(Filter* filter) {
        // setting next filter.
        nextFil = filter;
        return nextFil;
    }

    std::list<Shape*> push(std::list<Shape*> shapes) {
        // push down filtered data and return result.
        for (auto shape = shapes.begin();shape!=shapes.end();shape++){
            if (shapePred(*shape)){
                 shapeList.push_back(*shape);
            }
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
    FilterFunction shapePred;
};
