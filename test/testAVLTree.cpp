#include "testAVLTree.h"
#include <memory>

using namespace std;

// empty tree


TEST(AVLTreeTest, Empty_Tree) {
    AVLTree avlTree;
    EXPECT_EQ(nullptr, avlTree.preorder());
    EXPECT_EQ(nullptr, avlTree.inorder());
    EXPECT_EQ(nullptr, avlTree.postorder());
}

// insert and search

TEST(AVLTreeTest, One_Node) {
    AVLTree avlTree;
    avlTree.insert(12213);
    EXPECT_TRUE(avlTree.search(12213));
    EXPECT_FALSE(avlTree.search(123));
    EXPECT_FALSE(avlTree.search(-123));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(12213));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(12213));
}

TEST(AVLTreeTest, Two_Nodes) {
    AVLTree avlTree;
    avlTree.insert(12213);
    avlTree.insert(215);
    EXPECT_TRUE(avlTree.search(12213));
    EXPECT_TRUE(avlTree.search(215));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(12213, 215));
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(215, 12213));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(215, 12213));
}

TEST(AVLTreeTest, Three_Nodes) {
    AVLTree avlTree;
    avlTree.insert(12213);
    avlTree.insert(215);
    avlTree.insert(123712);
    EXPECT_TRUE(avlTree.search(12213));
    EXPECT_TRUE(avlTree.search(123712));
    EXPECT_TRUE(avlTree.search(215));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(12213, 215, 123712));
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(215, 12213, 123712));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(215, 123712, 12213));
}
/*
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
    AVLTree avlTree;
    avlTree.insert(250);
    avlTree.insert(240);
    avlTree.insert(230);
    avlTree.insert(210);
    avlTree.insert(200);
    avlTree.insert(100);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(100, 200, 210, 230 , 240 ,250));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(210, 200, 100, 240 , 230 ,250));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(100, 200, 230 , 250 ,240, 210));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0, -1, 0, 0 , 0 ,0));

}

TEST(AVLTreeTest, Insert_only_bigger) {
    AVLTree avlTree;
    avlTree.insert(250);
    avlTree.insert(270);
    avlTree.insert(280);
    avlTree.insert(300);
    avlTree.insert(350);
    avlTree.insert(400);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(250, 270, 280, 300 , 350 ,400));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(300, 270, 250, 280 , 350, 400));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(250, 280, 270 , 400 ,350, 300));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0, 0, 0, 0 , 1,0));

}

TEST(AVLTreeTest, doubleRotateRL) {
    AVLTree avlTree;
    avlTree.insert(5);
    avlTree.insert(6);
    avlTree.insert(13);
    avlTree.insert(12);
    avlTree.insert(11);
    avlTree.insert(10);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(5, 6, 10, 11 , 12 ,13));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(11, 6, 5, 10 , 12, 13));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(5, 10, 6 , 13 ,12, 11));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0, 0, 0, 0 , 1,0));
}


TEST(AVLTreeTest, doubleRotateLR) {
    AVLTree avlTree;
    avlTree.insert(15);
    avlTree.insert(6);
    avlTree.insert(18);
    avlTree.insert(3);
    avlTree.insert(9);
    avlTree.insert(10);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(3, 6, 9,10, 15 ,18));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(9, 6, 3, 15 , 10, 18));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(3, 6, 10 , 18 ,15, 9));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0, -1, 0, 0 , 0,0));
}