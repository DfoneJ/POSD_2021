#include "../../src/builder/shape_builder.h"

TEST(CaseBuilder, BuildCircle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCircle(1.0);
    Shape* result = builder->getShape();
    ASSERT_NEAR(1*1*M_PI, result->area(), 0.001);
    delete builder;
    delete result;
}

TEST(CaseBuilder, BuildRectangle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildRectangle(3.0,4.0);
    Shape* result = builder->getShape();
    ASSERT_NEAR(3*4, result->area(), 0.001);
    delete builder;
    delete result;
}

TEST(CaseBuilder, BuildTriangle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildTriangle(3,0,0,4);
    Shape* result = builder->getShape();
    ASSERT_NEAR(3*4/2, result->area(), 0.001);
    delete builder;
    delete result;
}

TEST(CaseBuilder, BuildEmptyCompound) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCompoundBegin();
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR(0, result->area(), 0.001);
    delete builder;
    delete result;
}

TEST(CaseBuilder, BuildSimpleCompound) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildRectangle(3.14,4.0);
    builder->buildTriangle(3,0,0,4);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();
    ASSERT_NEAR(1*1*M_PI + 3.14*4 + 3*4/2, result->area(), 0.001);
    delete builder;
    delete result;
}

TEST(CaseBuilder, BuildComplexCompound) {
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
    delete result;
}