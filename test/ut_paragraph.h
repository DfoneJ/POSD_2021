#include "../src/text.h"
#include "../src/list_item.h"
#include "../src/paragraph.h"

TEST(CaseParagraph, CreatZeroLevel) {
    try{
        Paragraph p(0,"title_0");
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("level cannot smaller than 1"), e);
    }
}

TEST(CaseParagraph, CreatSevenLevel) {
    try{
        Paragraph p(7,"title_7");
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("level cannot greater than 6"), e);
    }
}

TEST(CaseParagraph, GetLevel){
    Paragraph p(1,"title_1");
    ASSERT_EQ(1,p.getLevel());
}

TEST(CaseParagraph, GetText){
    Paragraph p(1,"title_1");
    ASSERT_EQ(std::string("title_1"),p.getText());
}

TEST(CaseParagraph, AddFail){
    Paragraph p2(2, "title1");
    Paragraph* p1 = new Paragraph(1, "title2");
    try{
        p2.add(p1);
        FAIL();
    }
    catch(std::string e){
        EXPECT_EQ(std::string("Invalid level!"),e);
    }
    delete p1;
}

TEST(CaseParagraph, Add){
    Paragraph p(1, "title");
    Text* atx = new Text("added_text");
    ListItem* alit = new ListItem("added_listitem");
    p.add(atx);
    p.add(alit);
    // should have no exception
}