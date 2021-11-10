#include <gtest/gtest.h>
#include "../src/shape_builder.h"

TEST(ShapeBuilderTest, build_triangle) {
    ShapeBuilder sb;
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::deque<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}


TEST(ShapeBuilderTest, build_ellipse) {
    ShapeBuilder sb;
    sb.buildEllipse( 12.0,  9.0);
    std::deque<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Ellipse (12.000, 9.000)", results[0]->info());
}

TEST(ShapeBuilderTest, build_rectangle) {
    ShapeBuilder sb;
    sb.buildRectangle( 12.0,  9.0);
    std::deque<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Rectangle (12.000, 9.000)", results[0]->info());
}

TEST(ShapeBuilderTest, BuildForest){
    ShapeBuilder  sb;
    sb.buildRectangle( 12.0,  9.0);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3, 4);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(2, 2);
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ(2,results.size());
    ASSERT_EQ(108,results[0]->area());
    ASSERT_EQ(16,results[1]->area()); //Compound Shape {Rectangle (3.000, 4.000), Compound Shape {Rectangle (2.000, 2.000)}}
    
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_a_empty_compoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    
    std::deque<Shape*> results = sb.getResult();
    ASSERT_EQ("Compound Shape {Compound Shape {}}", results[0]->info());
    ASSERT_EQ(1, results.size());
    
}


TEST(ShapeBuilderTest, large_context) {
    // Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), 
// CompoundShape {Rectangle (3.000, 4.000),Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)},
//   Rectangle (3.000, 4.000), 
//   CompoundShape {}, 
//   Ellipse (4.200, 3.700)

    ShapeBuilder sb;
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3, 4);
    sb.buildEllipse(4.200, 3.700);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();
    sb.buildRectangle(3, 4);
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildEllipse(4.200, 3.700);

    std::deque<Shape*> results = sb.getResult();

    ASSERT_EQ("Ellipse (4.200, 3.700)", results[4]->info());
}




