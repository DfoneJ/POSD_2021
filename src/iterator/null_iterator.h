#pragma once

#include "iterator.h"

class NullIterator : public Iterator {
   public:
    void first() override {throw std::string("nulptr has no first()!");} // OK

    Article* currentItem() const override {throw std::string("nulptr has no currentItem()!");} // OK

    void next() override {throw std::string("nulptr has no next()!");} // OK

    bool isDone() const override {return true;} // OK
};
