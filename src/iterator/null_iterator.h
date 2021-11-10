#pragma once

#include "iterator.h"
#include <stdio.h>
#include <exception>

class NullIterator : public Iterator {
   public:
    void first() override {throw std::string("nulptr has no first()!");}

    Shape* currentItem() const override {throw std::string("nulptr has no currentItem()!");}

    void next() override {throw std::string("nulptr has no next()!");}

    bool isDone() const override {return true;}
};
