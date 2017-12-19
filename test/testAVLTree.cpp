#include "testAVLTree.h"
#include <memory>

using namespace std;

// empty tree

/*
TEST(AVLTreeTest, Empty_Tree) {
    AVLTree b;
    EXPECT_EQ(nullptr, b.preorder());
    EXPECT_EQ(nullptr, b.inorder());
    EXPECT_EQ(nullptr, b.postorder());
}

// insert and search

TEST(AVLTreeTest, One_Node) {
    AVLTree b;
    b.insert(12213);
    EXPECT_TRUE(b.search(12213));
    EXPECT_FALSE(b.search(123));
    EXPECT_FALSE(b.search(-123));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(12213));
}

TEST(AVLTreeTest, Two_Nodes) {
    AVLTree b;
    b.insert(12213);
    b.insert(215);
    EXPECT_TRUE(b.search(12213));
    EXPECT_TRUE(b.search(215));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(12213, 215));
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(215, 12213));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(215, 12213));
}

TEST(AVLTreeTest, Three_Nodes) {
    AVLTree b;
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

TEST(AVLTreeTest, One_Node_Insert_Remove) {
    AVLTree b;
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

TEST(AVLTreeTest, Two_Nodes_Insert_Remove) {
    AVLTree b;
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
*/

TEST(AVLTreeTest, Insert_only_smaller) {
    AVLTree b;
    b.insert(250);
    b.insert(240);
    b.insert(230);
    b.insert(210);
    b.insert(200);
    b.insert(100);


    // EXPECT_THAT(*b.preorder(), testing::ElementsAre(250,130, 100,203,270));
}

TEST(AVLTreeTest, Insert_only_bigger) {
    AVLTree b;
    b.insert(250);
    b.insert(270);
    b.insert(280);
    b.insert(300);
    b.insert(350);
    b.insert(400);


   // EXPECT_THAT(*b.preorder(), testing::ElementsAre(250,130, 100,203,270));
}

TEST(AVLTreeTest, doubleRotate) {
    AVLTree b;
    b.insert(250);
    b.insert(270);
    b.insert(280);
    b.insert(300);
    b.insert(350);
 //   b.insert(400);
    b.insert(269);
    b.insert(269);


    // EXPECT_THAT(*b.preorder(), testing::ElementsAre(250,130, 100,203,270));
}