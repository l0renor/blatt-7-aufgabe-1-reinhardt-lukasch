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

TEST(AVLTreeTest, doubleRotateLRt2t3empty) {
    AVLTree avlTree;
    avlTree.insert(500);
    avlTree.insert(400);
    avlTree.insert(450);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(400,450,500));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(450,400,500));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(400,500,450));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0,0,0));
}

TEST(AVLTreeTest, doubleRotateRLt2t3empty) {
    AVLTree avlTree;
    avlTree.insert(500);
    avlTree.insert(600);
    avlTree.insert(550);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(500,550,600));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(550,500,600));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(500,600,550));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0,0,0));
}
// insert, remove

TEST(AVLTreeTest, RemoveOnlyNode ) {
    AVLTree avlTree;
    avlTree.insert(470);
    avlTree.remove(470);
    EXPECT_FALSE(avlTree.search(470));
    EXPECT_EQ(avlTree.preorder(), nullptr);
    EXPECT_EQ(avlTree.inorder(), nullptr);
    EXPECT_EQ(avlTree.postorder(), nullptr);
}

TEST(AVLTreeTest, RemoveNOrotation ) {
    AVLTree avlTree;
    avlTree.insert(450);
    avlTree.insert(400);
    avlTree.insert(500);
    avlTree.insert(470);
    avlTree.remove(470);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(400,450,500));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(450,400,500));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(400,500,450));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0,0,0));
}

TEST(AVLTreeTest, RemoveLRrotation ) {
    AVLTree avlTree;
    avlTree.insert(500);
    avlTree.insert(400);
    avlTree.insert(700);
    avlTree.insert(450);
    avlTree.remove(700);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(400,450,500));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(450,400,500));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(400,500,450));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0,0,0));
}

TEST(AVLTreeTest, RemoveRLrotation ) {
    AVLTree avlTree;
    avlTree.insert(450);
    avlTree.insert(400);
    avlTree.insert(500);
    avlTree.insert(470);
    avlTree.remove(400);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(450,470,500));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(470,450,500));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(450,500,470));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0,0,0));
}

TEST(AVLTreeTest, RemoveInner) {
    AVLTree avlTree;
    avlTree.insert(100);
    avlTree.insert(20);
    avlTree.insert(150);
    avlTree.insert(12);
    avlTree.insert(25);
    avlTree.remove(20);
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(12,25,100,150));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(100,25,12,150));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(12,25,150,100));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0,-1,0,-1));
}

TEST(AVLTreeTest, Remove_upoutTest) {
    AVLTree avlTree;
    avlTree.insert(70);
    avlTree.insert(30);
    avlTree.insert(100);
    avlTree.insert(15);
    avlTree.insert(40);
    avlTree.insert(85);
    avlTree.insert(150);
    avlTree.insert(7);
    avlTree.remove(7);
    EXPECT_FALSE(avlTree.search(7));
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(15, 30, 40, 70, 85, 100, 150));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(70,30,15,40,100,85,150));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(15, 40, 30, 85, 150, 100, 70));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0,0,0,0,0,0,0));
}

TEST(AVLTreeTest, Remove_upoutTest2) {
    AVLTree avlTree;
    avlTree.insert(70);
    avlTree.insert(30);
    avlTree.insert(100);
    avlTree.insert(15);
    avlTree.insert(40);
    avlTree.insert(85);
    avlTree.insert(150);
    avlTree.insert(7);
    avlTree.insert(120);
    avlTree.remove(7);
    EXPECT_FALSE(avlTree.search(7));
    EXPECT_THAT(*avlTree.inorder(), testing::ElementsAre(15, 30, 40, 70, 85, 100, 120,150));
    EXPECT_THAT(*avlTree.preorder(), testing::ElementsAre(70,30,15,40,100,85,150,120));
    EXPECT_THAT(*avlTree.postorder(), testing::ElementsAre(15, 40, 30, 85,120 ,150, 100, 70));
    EXPECT_THAT(*avlTree.inorderBalance(), testing::ElementsAre(0,0,0,1,0,1,0,-1));
}