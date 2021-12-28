#include "../../src/iterator/null_iterator.h"

TEST(CaseNullIterator, First) {
    Iterator* nit = new NullIterator();
    try {
        nit->first();
    }
    catch(std::string e) {
        ASSERT_EQ(e,std::string("Already met the end !"));
    }
    delete nit;
}

TEST(CaseNullIterator, CurrentItem) {
    Iterator* nit = new NullIterator();
    try {
        nit->currentItem();
    }
    catch(std::string e) {
        ASSERT_EQ(e,std::string("Already met the end !"));
    }
    delete nit;
}

TEST(CaseNullIterator, Next) {
    Iterator* nit = new NullIterator();
    try {
        nit->next();
    }
    catch(std::string e) {
        ASSERT_EQ(e,std::string("Already met the end !"));
    }
    delete nit;
}

TEST(CaseNullIterator, IsDone) {
    Iterator* nit = new NullIterator();
    ASSERT_TRUE(nit->isDone());
    delete nit;
}