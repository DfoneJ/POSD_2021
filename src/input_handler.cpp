#include "input_handler.h"

void InputHandler::handle() {
    int InsNumber;
    while(isContinued) {
        printEditorInstructions();
        InsNumber = getchar();
        if((InsNumber>='1') && (InsNumber<='6')) { handleEditorInstructions(InsNumber); }
        else { std::cout << _InvalidInsNum; }
    }
    builder->reset();
}

void InputHandler::printEditorInstructions() { std::cout << _Instruction; }

void InputHandler::handleEditorInstructions(int instruction) {
    switch(instruction) {
        case '1':
            addCircle();
            break;

        case '2':
            addRectangle();
            break;

        case '3':
            addTriangle();
            break;
        
        case '4':
            addCompound();
            break;

        case '5':
            save();
            break;

        case '6':
            isContinued = false;
            break;
    }
}

void InputHandler::save() {
    std::cout << "Please enter the file name to save the shape:\n";
    std::string FileName;
    std::cin >> FileName;
    if(FileName.length()==0) { // empty filename
        std::cout << "Empty file name!\n";
        return;
    }
    for(std::string s : InvalidChar) { // file name contains invalid character
        if(FileName.find(s)!=std::string::npos) {
            std::cout << "Invalid file name!\n";
            return;
        }
    }
    FileName += ".txt";
    // starting to get shapes info.
    std::string result ="";
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor;
    while(true) {
        Shape* builtShape = builder->getShape();
        if(builtShape==nullptr) { break; }
        builtShape->accept(visitor);
        result += visitor->getResult();
    }
    delete visitor;
    // starting to write file
    std::ofstream ofs;
    ofs.open(FileName);
    if(!ofs.is_open()) { std::cout << "Failed to save file!" << std::endl; }
    else {
        ofs << result;
        ofs.close();
    }
}

void InputHandler::addCircle() {
    double radius;
    std::cout << "Please enter the information of circle\n Radius of circle: ";
    try {
        std::cin >> radius;
        builder->buildCircle(radius);
    }catch (...) {
        std::cout << _InvalidArgument;
        return;
    }std::cout << "Circle added.\n";
}

void InputHandler::addRectangle() {
    double width, height;
    std::cout << "Please enter the information of rectangle\n Width of rectangle: ";
    try {
        std::cin >> width;
        std::cout << " Height of rectangle: ";
        std::cin >> height;
        builder->buildRectangle(width,height);
    }catch (...) {
        std::cout << _InvalidArgument;
        return;
    }std::cout << "Rectangle added.\n";
}

void InputHandler::addTriangle() {
    double x1,y1,x2,y2;
    std::cout << "Please enter the information of triangle\n X1 of triangle: ";
    try {
        std::cin >> x1;
        std::cout << " Y1 of triangle: ";
        std::cin >> y1;
        std::cout << " X2 of triangle: ";
        std::cin >> x2;
        std::cout << " Y2 of triangle: ";
        std::cin >> y2;
        builder->buildTriangle(x1,y1,x2,y2);
    }catch (...) {
        std::cout << _InvalidArgument;
        return;
    }std::cout << "Triangle added.\n";
}

void InputHandler::printCompoundInstructions() { std::cout << _CompoundInstruction; }

void InputHandler::handleCompoundInstructions(int instruction) {
    switch(instruction) {
        case '1':
            addCircle();
            break;

        case '2':
            addRectangle();
            break;

        case '3':
            addTriangle();
            break;
        
        case '4':
            addCompound();
            break;

        case '5':
            isContinued = false;
            break;
    }
}

void InputHandler::addCompound() {
    builder->buildCompoundBegin();
    int CompoundInsNumber;
    while(isContinued) {
        printCompoundInstructions();
        CompoundInsNumber = getchar();
        if((CompoundInsNumber>='1') && (CompoundInsNumber<='5')) { handleCompoundInstructions(CompoundInsNumber); }
        else { std::cout << _InvalidInsNum; }
    }
    builder->buildCompoundEnd();
    std::cout << "Compound added.\n";
    isContinued = true;
}
