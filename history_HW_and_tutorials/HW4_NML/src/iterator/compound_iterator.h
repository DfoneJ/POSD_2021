#pragma once

#include "./iterator.h"

template <class ForwardIterator>
class CompoundIterator : public Iterator {
   public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) : _begin(begin), _end(end) { first(); }

    void first() override { _current = _begin; }

    Shape* currentItem() const override {
        if(_current == _end) { throw "Already met the end !"; }
        else { return *_current; }
    }

    void next() override {
        if(_current == _end) { throw "Already met the end !"; }
        else { _current++; }
    }

    bool isDone() const override { return _current==_end; }

   private:
    ForwardIterator _current;
    ForwardIterator _begin;
    ForwardIterator _end;
};