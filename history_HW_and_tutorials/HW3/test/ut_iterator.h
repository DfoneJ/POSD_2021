#include "../src/iterator/null_iterator.h"

TEST(CaseNullIterator, NullIterator){
    Iterator* it = new NullIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}