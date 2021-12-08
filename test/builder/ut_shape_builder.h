#include "../../src/builder/shape_builder.h"

TEST(CaseBuilder, BuildCircle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCircle(1.0);
    Shape* result = builder->getShape();
    ASSERT_NEAR(1*1*M_PI, result->area(), 0.001);
    delete builder;
}

TEST(CaseBuilder, BuildRectangle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildRectangle(3.0,4.0);
    Shape* result = builder->getShape();
    ASSERT_NEAR(3*4, result->area(), 0.001);
    delete builder;
}

TEST(CaseBuilder, BuilderTriangle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildTriangle(3,0,0,4);
    Shape* result = builder->getShape();
    ASSERT_NEAR(3*4/2, result->area(), 0.001);
    delete builder;
}

TEST(CaseBuilder, BuilderOneLevelCompound) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildRectangle(3.0,4.0);
    builder->buildTriangle(3,0,0,4);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR((1*1*M_PI)+(3*4)+(3*4/2), result->area(), 0.001);
    delete builder;
}

TEST(CaseBuilder, BuilderTwoLevelCompound) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCompoundBegin();
    builder->buildRectangle(3.0,4.0);
    builder->buildTriangle(3,0,0,4);
    builder->buildCompoundEnd();
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR((1*1*M_PI)+(3*4)+(3*4/2), result->area(), 0.001);
    delete builder;
}