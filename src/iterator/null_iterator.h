#pragma once

#include <stdio.h>
#include <exception>
#include <iostream>
#include "iterator.h"

class NullIterator : public Iterator {
public:
    
    void first() override {throw std::string("nulptr has no first()!");}

    Shape* currentItem() const override {throw std::string("nulptr has no currentItem()!");}

    void next() override {throw std::string("nulptr has no next()!");}

    bool isDone() const override {return true;}
};