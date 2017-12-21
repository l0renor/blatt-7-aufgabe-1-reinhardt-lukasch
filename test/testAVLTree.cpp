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
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(100, 200, 210, 230 , 240 ,250));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(210, 200, 100, 240 , 230 ,250));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(100, 200, 230 , 250 ,240, 210));
    EXPECT_THAT(*b.inorderBalance(), testing::ElementsAre(0, -1, 0, 0 , 0 ,0));

}

TEST(AVLTreeTest, Insert_only_bigger) {
    AVLTree b;
    b.insert(250);
    b.insert(270);
    b.insert(280);
    b.insert(300);
    b.insert(350);
    b.insert(400);
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(250, 270, 280, 300 , 350 ,400));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(300, 270, 250, 280 , 350, 400));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(250, 280, 270 , 400 ,350, 300));
    EXPECT_THAT(*b.inorderBalance(), testing::ElementsAre(0, 0, 0, 0 , 1,0));

   // EXPECT_THAT(*b.preorder(), testing::ElementsAre(250,130, 100,203,270));
}

TEST(AVLTreeTest, doubleRotateRL) {
    AVLTree b;
    b.insert(5);
    b.insert(6);
    b.insert(13);
    b.insert(12);
    b.insert(11);
    b.insert(10);
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(5, 6, 10, 11 , 12 ,13));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(11, 6, 5, 10 , 12, 13));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(5, 10, 6 , 13 ,12, 11));
    EXPECT_THAT(*b.inorderBalance(), testing::ElementsAre(0, 0, 0, 0 , 1,0));
}


TEST(AVLTreeTest, doubleRotateLR) {
    AVLTree b;
    b.insert(15);
    b.insert(6);
    b.insert(18);
    b.insert(3);
    b.insert(9);
    b.insert(10);
    EXPECT_THAT(*b.inorder(), testing::ElementsAre(3, 6, 9,10, 15 ,18));
    EXPECT_THAT(*b.preorder(), testing::ElementsAre(9, 6, 3, 15 , 10, 18));
    EXPECT_THAT(*b.postorder(), testing::ElementsAre(3, 6, 10 , 18 ,15, 9));
    EXPECT_THAT(*b.inorderBalance(), testing::ElementsAre(0, -1, 0, 0 , 0,0));
}