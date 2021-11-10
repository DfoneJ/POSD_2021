#include "../../src/iterator/null_iterator.h"

TEST(CaseNullIterator, First) {
    Iterator* it = new NullIterator();
    try{
        it->first();
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("nulptr has no first()!"), e);
    }
    delete it;
}

TEST(CaseNullIterator, CurrentItem) {
    Iterator* it = new NullIterator();
    try{
        it->currentItem();
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("nulptr has no currentItem()!"), e);
    }
    delete it;
}

TEST(CaseNullIterator, Next) {
    Iterator* it = new NullIterator();
    try{
        it->next();
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("nulptr has no next()!"), e);
    }
    delete it;
}

TEST(CaseNullIterator, IsDone) {
    Iterator* it = new NullIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}