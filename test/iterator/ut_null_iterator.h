#include "../../src/iterator/null_iterator.h"

class CaseNullIterator : public ::testing::Test {
protected:
    void SetUp() override { nit = new NullIterator(); }

    void TearDown() override { delete nit; }

    Iterator* nit;
};

TEST_F(CaseNullIterator, First) {
    try {
        nit->first();
    }
    catch(std::string e) {
        ASSERT_EQ(e,std::string("Already met the end !"));
    }
}

TEST_F(CaseNullIterator, CurrentItem) {
    try {
        nit->currentItem();
    }
    catch(std::string e) {
        ASSERT_EQ(e,std::string("Already met the end !"));
    }
}

TEST_F(CaseNullIterator, Next) {
    try {
        nit->next();
    }
    catch(std::string e) {
        ASSERT_EQ(e,std::string("Already met the end !"));
    }
}

TEST_F(CaseNullIterator, IsDone) {
    ASSERT_TRUE(nit->isDone());
}