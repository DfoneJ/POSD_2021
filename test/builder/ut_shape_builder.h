#include "../../src/builder/shape_builder.h"

TEST(CaseBuilder, Creatiom) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    Shape* result = builder->getShape();
    ASSERT_TRUE(result==nullptr);
}

TEST(CaseBuilder, BuildCircle) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    builder->buildCircle(1.0);
    Shape* result = builder->getShape();
    ASSERT_NEAR(1*1*M_PI, result->area(), 0.001);
}

TEST(CaseBuilder, BuildRectangle) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    builder->buildRectangle(3.0,4.0);
    Shape* result = builder->getShape();
    ASSERT_NEAR(3*4, result->area(), 0.001);
}

TEST(CaseBuilder, BuildTriangle) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    builder->buildTriangle(3,0,0,4);
    Shape* result = builder->getShape();
    ASSERT_NEAR(3*4/2, result->area(), 0.001);
}

TEST(CaseBuilder, BuildEmptyCompound) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    builder->buildCompoundBegin();
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR(0, result->area(), 0.001);
}

TEST(CaseBuilder, BuildSimpleCompound) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildRectangle(3.14,4.0);
    builder->buildTriangle(3,0,0,4);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR(1*1*M_PI + 3.14*4 + 3*4/2, result->area(), 0.001);
}

TEST(CaseBuilder, BuildComplexCompound) {
    ShapeBuilder* builder = ShapeBuilder::getInstance();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCompoundBegin();
    builder->buildRectangle(3.0,4.0);
    builder->buildTriangle(3,0,0,4);
    builder->buildCompoundEnd();
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR((1*1*M_PI)+(3*4)+(3*4/2), result->area(), 0.001);
}