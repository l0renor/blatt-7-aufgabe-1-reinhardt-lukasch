#ifndef TREES_BINTREE_H
#define TREES_BINTREE_H

#include <iostream>
#include <vector>

using namespace std;

class AVLTree {

private:

    struct Node {
        const int key;
        int balance;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;
        Node(const int);
        Node(const int, Node *, Node *,);
        ~Node();
        bool search(const int) const;
        void insert(const int);
        Node *remove(const int);
        vector<int> *preorder() const; // (Hauptreihenfolge)
        vector<int> *inorder() const; // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)
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

    friend Node *findSymSucc(Node *);
    friend ostream &operator<<(ostream &, const AVLTree &);

};

#endif //TREES_BINTREE_H