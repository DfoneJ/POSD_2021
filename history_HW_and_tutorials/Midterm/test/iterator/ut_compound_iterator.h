#include "../../src/iterator/compound_iterator.h"
#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"

TEST(CaseCompoundIterator, ParagraphIterator) {
    Paragraph p(1, "title");
    p.add(new ListItem("list1"));
    p.add(new ListItem("list2"));
    p.add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p.add(p2);
    Iterator* pit = p.createIterator();
    ASSERT_EQ(pit->isDone(), false);
    ASSERT_EQ(pit->currentItem()->getText(), "list1");
    pit->next();
    ASSERT_EQ(pit->currentItem()->getText(), "list2");
    pit->next();
    ASSERT_EQ(pit->currentItem()->getText(), "text");
    pit->next();
    ASSERT_EQ(pit->currentItem()->getText(), "title2");
    ASSERT_EQ(pit->isDone(), false);
    pit->next();
    ASSERT_TRUE(pit->isDone());
    try {
        pit->currentItem();
        FAIL();
    }catch (std::string e) {
        ASSERT_EQ(e, "Already met the end !");
    }
    try {
        pit->next();
        FAIL();
    }catch (std::string e) {
        ASSERT_EQ(e, "Already met the end !");
    }
    delete pit;
}