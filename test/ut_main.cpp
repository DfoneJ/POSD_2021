#include <iostream>
#include <gtest/gtest.h>
#include "ut_paragraph.h"
#include "ut_list_item.h"
#include "ut_text.h"

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}