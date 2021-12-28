#include "../src/text.h"
#include <typeinfo>

TEST(CaseText, Create){
    Text tx("test_text");
    EXPECT_EQ(std::string("4Text"),typeid(tx).name());
}

TEST(CaseText, GetText){
    Text tx("test_text");
    ASSERT_EQ(std::string("test_text"),tx.getText());
}

TEST(CaseText, GetFullText){
    Text tx("test_text");
    ASSERT_EQ(std::string("test_text"),tx.getFullText());
}

TEST(CaseText, GetHtmlText){
    Text tx("test_text");
    ASSERT_EQ(std::string("<span>test_text</span>"),tx.getHtmlText());
}

TEST(CaseText, GetLevel){
    Text tx("test_text");
    ASSERT_EQ(0,tx.getLevel());
}

TEST(CaseText, AddFail){
    Text tx("test_text");
    try{
        tx.add(new Text("added_text"));
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("Text cannot do add!"), e);
    }
} 
