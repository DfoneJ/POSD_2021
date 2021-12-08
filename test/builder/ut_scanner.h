#include "../../src/builder/scanner.h"

TEST(CaseScanner, Circle) {
    std::string data_txt = "Circle (1.0)";
    Scanner* scanner = new Scanner(data_txt);
    ASSERT_EQ("Circle", scanner->next());
    ASSERT_NEAR(1.0, scanner->nextDouble(), 0.001);
    ASSERT_EQ("", scanner->next());
    ASSERT_TRUE(scanner->isDone());
    delete scanner;
}

TEST(CaseScanner, Rectangle) {
    std::string data_txt = "Rectangle (3.14, 4.00)";
    Scanner* scanner = new Scanner(data_txt);
    ASSERT_EQ("Rectangle", scanner->next());
    ASSERT_NEAR(3.14, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(4, scanner->nextDouble(), 0.001);
    ASSERT_EQ("", scanner->next());
    ASSERT_TRUE(scanner->isDone());
    delete scanner;
}

TEST(CaseScanner, Triangle) {
    std::string data_txt = "Triangle ([3, 0] [0.000, 4.0])";
    Scanner* scanner = new Scanner(data_txt);
    ASSERT_EQ("Triangle", scanner->next());
    ASSERT_NEAR(3, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(0, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(0, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(4, scanner->nextDouble(), 0.001);
    ASSERT_EQ("", scanner->next());
    ASSERT_TRUE(scanner->isDone());
    delete scanner;
}

TEST(CaseScanner, EmptyCompound) {
    std::string data_txt = "CompoundShape {}";
    Scanner* scanner = new Scanner(data_txt);
    ASSERT_EQ("CompoundShape", scanner->next());
    ASSERT_EQ("}", scanner->next());
    ASSERT_EQ("", scanner->next());
    ASSERT_TRUE(scanner->isDone());
    delete scanner;
}

TEST(CaseScanner, SimpleCompound) {
    std::string data_txt = "CompoundShape {\n  Circle (1.0)\n  Rectangle (3.14 4.00)\n  Triangle ([3,0] [0,4])\n}\n";
    Scanner* scanner = new Scanner(data_txt);
    ASSERT_EQ("CompoundShape", scanner->next());
    ASSERT_EQ("Circle", scanner->next());
    ASSERT_NEAR(1.0, scanner->nextDouble(), 0.001);
    ASSERT_EQ("Rectangle", scanner->next());
    ASSERT_NEAR(3.14, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(4.00, scanner->nextDouble(), 0.001);
    ASSERT_EQ("Triangle", scanner->next());
    ASSERT_NEAR(3, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(0, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(0, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(4, scanner->nextDouble(), 0.001);
    ASSERT_EQ("}", scanner->next());
    ASSERT_EQ("", scanner->next());
    ASSERT_TRUE(scanner->isDone());
    delete scanner;
}

TEST(CaseScanner, ComplexCompound) {
    std::string data_txt = "CompoundShape {\n  Circle (1.0)\n  Triangle ([3,0] [0,4])\n  CompoundShape {\n    Circle (1.0)\n    Rectangle (3.14 4.00)\n    Triangle ([3,0] [0,4])\n  }\n  Rectangle (3.14 4.00)\n}";
    Scanner* scanner = new Scanner(data_txt);
    ASSERT_EQ("CompoundShape", scanner->next());
    ASSERT_EQ("Circle", scanner->next());
    ASSERT_NEAR(1.0, scanner->nextDouble(), 0.001);
    ASSERT_EQ("Triangle", scanner->next());
    ASSERT_NEAR(3, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(0, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(0, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(4, scanner->nextDouble(), 0.001);
    ASSERT_EQ("CompoundShape", scanner->next());
    ASSERT_EQ("Circle", scanner->next());
    ASSERT_NEAR(1.0, scanner->nextDouble(), 0.001);
    ASSERT_EQ("Rectangle", scanner->next());
    ASSERT_NEAR(3.14, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(4.00, scanner->nextDouble(), 0.001);
    ASSERT_EQ("Triangle", scanner->next());
    ASSERT_NEAR(3, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(0, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(0, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(4, scanner->nextDouble(), 0.001);
    ASSERT_EQ("}", scanner->next());
    ASSERT_EQ("Rectangle", scanner->next());
    ASSERT_NEAR(3.14, scanner->nextDouble(), 0.001);
    ASSERT_NEAR(4.00, scanner->nextDouble(), 0.001);
    ASSERT_EQ("}", scanner->next());
    ASSERT_EQ("", scanner->next());
    ASSERT_TRUE(scanner->isDone());
    delete scanner;
}
