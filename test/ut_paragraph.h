#include "../src/text.h"
#include "../src/list_item.h"
#include "../src/paragraph.h"
#include <iostream>
#include <typeinfo>

TEST(CaseParagraph, Creat_Zero_Level_Fail){
    try{
        Paragraph p(0,"title_0");
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("level cannot smaller than 1"), e);
    }
}

TEST(CaseParagraph, Creat_Seven_Level_Fail){
    try{
        Paragraph p(7,"title_7");
        FAIL();
    }
    catch(std::string e){
        ASSERT_EQ(std::string("level cannot greater than 6"), e);
    }
}

TEST(CaseParagraph, Create){
    Paragraph p(1,"title_1");
    EXPECT_EQ(std::string("9Paragraph"),typeid(p).name());
}

TEST(CaseParagraph, GetLevel){
    Paragraph p(1,"title_1");
    ASSERT_EQ(1,p.getLevel());
}

TEST(CaseParagraph, GetText){
    Paragraph p(1,"title_1");
    ASSERT_EQ(std::string("# title_1"),p.getText());
}

TEST(CaseParagraph, AddFail){
    Paragraph p2(2, "title1");
    Paragraph* p1 = new Paragraph(1, "title2");
    try{
        p2.add(p1);
        FAIL();
    }
    catch(std::string e){
        EXPECT_EQ(std::string("cannot add smaller or equal level paragraph!"),e);
    }
}

TEST(CaseParagraph, Add){
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);
    ASSERT_EQ(std::string("# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text"),p.getText());
}
