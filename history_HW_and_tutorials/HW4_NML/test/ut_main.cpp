#include <gtest/gtest.h>

#include "ut_compound_shape.h"
#include "ut_circle.h"
#include "ut_rectangle.h"
#include "ut_triangle.h"
#include "ut_two_dimensional_vector.h"
#include "iterator/ut_null_iterator.h"
#include "iterator/ut_compound_iterator.h"
#include "visitor/ut_shape_info_visitor.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}