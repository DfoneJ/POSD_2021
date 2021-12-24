#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <exception>

#include "./builder/shape_builder.h"
#include "./visitor/shape_info_visitor.h"

class InputHandler {
   public:
    void handle();

   private:
    void printEditorInstructions();
    void handleEditorInstructions(int instruction);
    void save();
    void addCircle();
    void addRectangle();
    void addTriangle();
    void printCompoundInstructions();
    void handleCompoundInstructions(int instruction);
    void addCompound();

    ShapeBuilder* builder = ShapeBuilder::getInstance();
    bool isContinued = true;
    std::string _Instruction = "Please enter the following instruction number to start building:\n 1. 'add circle': to add a circle\n 2. 'add rectangle': to add a rectangle\n 3. 'add triangle': to add a triangle\n 4. 'add compound': to add a compound\n 5. 'save': output shape to file\n 6. 'exit': to exit the program\n";
    std::string _CompoundInstruction = "Please enter the following instruction number to build the compound:\n 1. 'add circle': to add a circle\n 2. 'add rectangle': to add a rectangle\n 3. 'add triangle': to add a triangle\n 4. 'add compound': to add a compound\n 5. 'end': finish building compound\n";
    std::string _InvalidInsNum = "Invalid instruction number!\n";
    std::string _InvalidArgument = "Invalid argument!\n";
    std::vector<std::string> InvalidChar = {"<", ">", "/", "\\", ":", "?", "*", "\"", "|"};
};
