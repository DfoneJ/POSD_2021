#include "input_handler.h"

void InputHandler::handle() {
    int InsNumber;
    char check;
    while(isContinued) {
        printEditorInstructions();
        InsNumber = int(getchar())-48; // get a char, expected to be an single int number
        if(InsNumber!=-38) { // - the char is not a newline symbol
            check = getchar();
            if(check == '\n') { // -- the next char is newline, then handle the instruction
                if((InsNumber>=1) && (InsNumber<=6)) { handleEditorInstructions(InsNumber); }
                else { std::cout << _InvalidInsNum; }
            }
            else { // -- next char is not newline symbol, then its an invalid input, need clear buffer.
                std::cout << _InvalidInsNum;
                cleanBuffer();
            }
        }
        else { std::cout << _InvalidInsNum; } // - the char is a newline symbol
    }
    builder->reset();
}

void InputHandler::printEditorInstructions() { std::cout << _Instruction; }

void InputHandler::handleEditorInstructions(int instruction) {
    switch(instruction) {
        case 1:
            addCircle();
            break;

        case 2:
            addRectangle();
            break;

        case 3:
            addTriangle();
            break;
        
        case 4:
            addCompound();
            break;

        case 5:
            save();
            break;

        case 6:
            isContinued = false;
            break;
    }
}

void InputHandler::save() {
    std::cout << "Please enter the file name to save the shape:\n";
    char temp[120]="";
    scanf("%115[^\n]", temp);
    if(getchar()!='\n') { cleanBuffer(); }
    std::string FileName = temp;
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
    std::stack<Shape*> StackHolders;
    while(true) {
        Shape* ShapeInStack = builder->getShape();
        if(ShapeInStack==nullptr) { break; }
        StackHolders.push(ShapeInStack);
    }
    std::string result ="";
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor;
    while(!StackHolders.empty()) {
        StackHolders.top()->accept(visitor);
        result += visitor->getResult();
        delete StackHolders.top();
        StackHolders.pop();
    }
    delete visitor;
    // starting to write file
    std::ofstream ofs;
    ofs.open(FileName);
    if(!ofs.is_open()) { std::cout << "Failed to save file!" << std::endl; }
    else {
        ofs << result;
        ofs.close();
        std::cout << "Save complete." << std::endl;
    }
}

void InputHandler::addCircle() {
    std::cout << "Please enter the information of circle\n Radius of circle: ";
    char temp[10];
    scanf("%9[^\n]", temp);
    if(getchar()!='\n') { cleanBuffer(); }
    std::string radius = temp;
    if(!isDouble(radius)) {
        std::cout << _InvalidArgument;
        return;
    }
    try {
        builder->buildCircle(std::stod(radius));
        std::cout << "Circle added.\n";
    }catch (...) {
        std::cout << _InvalidArgument;
        return;
    }
}

void InputHandler::addRectangle() {
    std::cout << "Please enter the information of rectangle\n Width of rectangle: ";
    char temp[10];
    scanf("%9[^\n]", temp);
    if(getchar()!='\n') { cleanBuffer(); }
    std::string width = temp;
    sprintf(temp, " ");
    std::cout << " Height of rectangle: ";
    scanf("%9[^\n]", temp);
    if(getchar()!='\n') { cleanBuffer(); }
    std::string height = temp;
    if(!isDouble(width) || !isDouble(height)) {
        std::cout << _InvalidArgument;
        return;
    }
    try {
        builder->buildRectangle(std::stod(width), std::stod(height));
        std::cout << "Rectangle added.\n";
    }catch (...) {
        std::cout << _InvalidArgument;
        return;
    }
}

void InputHandler::addTriangle() {
    std::cout << "Please enter the information of triangle\n X1 of triangle: ";
    char temp[10];
    scanf("%9[^\n]", temp);
    if(getchar()!='\n') { cleanBuffer(); }
    std::string x1 = temp;
    std::cout << " Y1 of triangle: ";
    scanf("%9[^\n]", temp);
    if(getchar()!='\n') { cleanBuffer(); }
    std::string y1 = temp;
    std::cout << " X2 of triangle: ";
    scanf("%9[^\n]", temp);
    if(getchar()!='\n') { cleanBuffer(); }
    std::string x2 = temp;
    std::cout << " Y2 of triangle: ";
    scanf("%9[^\n]", temp);
    if(getchar()!='\n') { cleanBuffer(); }
    std::string y2 = temp;
    if(!isDouble(x1) || !isDouble(y1) || !isDouble(x2) || !isDouble(y2)) {
        std::cout << _InvalidArgument;
        return;
    }
    try {
        builder->buildTriangle(std::stod(x1), std::stod(y1), std::stod(x2), std::stod(y2));
        std::cout << "Triangle added.\n";
    }catch (...) {
        std::cout << _InvalidArgument;
        return;
    }
}

void InputHandler::printCompoundInstructions() { std::cout << _CompoundInstruction; }

void InputHandler::handleCompoundInstructions(int instruction) {
    switch(instruction) {
        case 1:
            addCircle();
            break;

        case 2:
            addRectangle();
            break;

        case 3:
            addTriangle();
            break;
        
        case 4:
            addCompound();
            break;

        case 5:
            isContinued = false;
            break;
    }
}

void InputHandler::addCompound() {
    builder->buildCompoundBegin();
    int CompoundInsNumber;
    char check;
    while(isContinued) {
        printCompoundInstructions();
        CompoundInsNumber = int(getchar())-48;
        if(CompoundInsNumber!=-38) {
            check = getchar();
            if(check=='\n') {
                if((CompoundInsNumber>=1) && (CompoundInsNumber<=5)) { handleCompoundInstructions(CompoundInsNumber); }
                else { std::cout << _InvalidInsNum; }
            }
            else {
                std::cout << _InvalidInsNum;
                cleanBuffer();
            }
        }
        else { std::cout << _InvalidInsNum; }
    }
    builder->buildCompoundEnd();
    std::cout << "Compound added.\n";
    isContinued = true;
}
