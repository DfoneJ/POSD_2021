#pragma once

#include "./iterator.h"

class NullIterator : public Iterator {
   public:
    void first() override { throw std::string("Already met the end !"); }
    Shape* currentItem() const override { throw std::string("Already met the end !"); }
    void next() override { throw std::string("Already met the end !"); }
    bool isDone() const override { return true; }
};