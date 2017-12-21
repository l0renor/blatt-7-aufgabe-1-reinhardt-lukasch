#ifndef TREES_BINTREE_H
#define TREES_BINTREE_H

#include <iostream>
#include <vector>

using namespace std;

class AVLTree {

private:

    struct Node {
        const int key;
        int balance = 0;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;
        Node(const int);
        Node(const int, Node*);
        Node(const int, Node *, Node *,Node *);
        ~Node();
        bool search(const int) const;
        void insert(const int,AVLTree *);
        void upin(AVLTree *);
        void rotateRight(AVLTree*);

        void rotateLeft(AVLTree*);

        Node *remove(const int);
        vector<int> *preorder() const; // (Hauptreihenfolge)
        vector<int> *inorder() const; // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)
        vector<int> *inorderBalance() const; // testing
    };

    Node *root = nullptr;

public:

    ~AVLTree();

    bool search(const int) const;

    void insert(const int);

    void remove(const int);



    vector<int> *preorder() const; // (Hauptreihenfolge)
    vector<int> *inorder() const; // (Symmetrische Reihenfolge)
    vector<int> *postorder() const; // (Nebenreihenfolge)
    vector<int> *inorderBalance() const; // testing

    friend Node *findSymSucc(Node *);
    friend ostream &operator<<(ostream &, const AVLTree &);

};

#endif //TREES_BINTREE_H