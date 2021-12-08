#include "../../src/builder/shape_parser.h"
// `filePath` is a relative path of makefile

TEST(CaseParser, Circle) {
    std::string filepath = "test/data/circle.txt";
    ShapeParser* parser = new ShapeParser(filepath);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_EQ("Circle (1.00)", result->info());
    ASSERT_NEAR(1*1*M_PI, result->area(), 0.001);
    delete parser, result;
}

TEST(CaseParser, Rectangle) {
    std::string filepath = "test/data/rectangle.txt";
    ShapeParser* parser = new ShapeParser(filepath);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_EQ("Rectangle (3.14 4.00)", result->info());
    ASSERT_NEAR(3.14*4.00, result->area(), 0.001);
    delete parser, result;
}

TEST(CaseParser, Triangle) {
    std::string filepath = "test/data/triangle.txt";
    ShapeParser* parser = new ShapeParser(filepath);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_EQ("Triangle ([3.00,0.00] [0.00,4.00])", result->info());
    ASSERT_NEAR(3*4/2, result->area(), 0.001);
    delete parser, result;
}

TEST(CaseParser, EmptyCompound) {
    std::string filepath = "test/data/empty_compound.txt";
    ShapeParser* parser = new ShapeParser(filepath);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_EQ("CompoundShape", result->info());
    ASSERT_NEAR(0, result->area(), 0.001);
    delete parser, result;
}

TEST(CaseParser, SimpleCompound) {
    std::string filepath = "test/data/simple_compound.txt";
    ShapeParser* parser = new ShapeParser(filepath);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_NEAR(1*1*M_PI + 3.14*4.00 + 3*4/2, result->area(), 0.001);
    delete parser, result;
}

TEST(CaseParser, ComplexCompound) {
    std::string filepath = "test/data/complex_compound.txt";
    ShapeParser* parser = new ShapeParser(filepath);
    parser->parse();
    Shape* result = parser->getShape();
    ASSERT_NEAR((1*1*M_PI + 3.14*4.00 + 3*4/2)*2, result->area(), 0.001);
    delete parser, result;
}