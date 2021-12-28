#include "../src/list_item.h"
#include <iostream>
#include <typeinfo>

TEST(CaseListItem, Create){
    ListItem lit("test_listitem");
    EXPECT_EQ(std::string("8ListItem"),typeid(lit).name());
}

TEST(CaseListItem, GetText){
    ListItem lit("test_listitem");
    ASSERT_EQ(std::string("- test_listitem"),lit.getText());
}

TEST(CaseListItem, GetLevel){
    ListItem lit("test_listitem");
    ASSERT_EQ(0,lit.getLevel());
}

TEST(CaseListItem, AddFail){
    ListItem lit("test_listitem");
    ListItem* alit = new ListItem("added_listitem");
    try{
        lit.add(alit);
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("ListItem cannot do add!"), e);
    }
    delete alit;
}