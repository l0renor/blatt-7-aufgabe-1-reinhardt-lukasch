#include "testBinTree.h"
#include <memory>

using namespace std;

// empty tree

TEST(BinTreeTest, Empty_Tree) {
    BinTree b;
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}

// insert and search

TEST(BinTreeTest, One_Node) {
    BinTree b;
    b.insert(12213);
    EXPECT_TRUE(b.search(12213));
    EXPECT_FALSE(b.search(123));
    EXPECT_FALSE(b.search(-123));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12213));
}

TEST(BinTreeTest, Two_Nodes) {
    BinTree b;
    b.insert(12213);
    b.insert(215);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 12213));
}

TEST(BinTreeTest, Three_Nodes) {
    BinTree b;
    b.insert(12213);
    b.insert(215);
    b.insert(123712);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(123712));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 123712, 12213));
}

// insert, remove and search

TEST(BinTreeTest, One_Node_Insert_Remove) {
    BinTree b;
    b.insert(12213);
    EXPECT_TRUE(b.search(12213));
    EXPECT_FALSE(b.search(123));
    EXPECT_FALSE(b.search(-123));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12213));
    b.remove(12213);
    EXPECT_FALSE(b.search(12213));
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}

TEST(BinTreeTest, Two_Nodes_Insert_Remove) {
    BinTree b;
    b.insert(12213);
    b.insert(215);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 12213));
    b.remove(12213);
    EXPECT_FALSE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215));
    b.remove(215);
    EXPECT_FALSE(b.search(215));
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}



TEST(BinTreeTest, Three_Nodes_Insert_Remove_Big_Tree) {
    BinTree b;
    b.insert(250);
    b.insert(270);
    b.insert(200);
    b.insert(130);
    b.insert(203);
    b.insert(100);

    EXPECT_TRUE(b.search(250));
    EXPECT_TRUE(b.search(270));
    EXPECT_TRUE(b.search(200));
    EXPECT_TRUE(b.search(130));
    EXPECT_TRUE(b.search(203));
    EXPECT_TRUE(b.search(100));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(250, 200, 130, 100,203,270));
    b.remove(200);
    EXPECT_FALSE(b.search(200));
    EXPECT_TRUE(b.search(250));
    EXPECT_TRUE(b.search(270));
    EXPECT_FALSE(b.search(200));
    EXPECT_TRUE(b.search(130));
    EXPECT_TRUE(b.search(203));
    EXPECT_TRUE(b.search(100));
   // EXPECT_THAT(*b.preorder(), testing::ElementsAre(250,130, 100,203,270));
}
