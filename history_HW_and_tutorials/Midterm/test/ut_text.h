#include "../src/text.h"

TEST(CaseText, GetText) {
    Text tx("test_text");
    ASSERT_EQ(std::string("test_text"), tx.getText());
}

TEST(CaseText, GetLevel) {
    Text tx("test_text");
    ASSERT_EQ(0,tx.getLevel());
}

TEST(CaseText, Add) {
    Text tx("test_text");
    Text* atx = new Text("added_text");
    try{
        tx.add(atx);
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("Text cannot do add!"), e);
    }
    delete atx;
} 
