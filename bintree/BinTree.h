#ifndef TREES_BINTREE_H
#define TREES_BINTREE_H

#include <iostream>
#include <vector>

using namespace std;

class BinTree {

private:

    struct Node {
        int key;
        Node *left = nullptr;
        Node *right = nullptr;
        Node(const int k){key = k;};
        Node(const int k, Node *l, Node *r){key = k;left = l;right=r;};
        ~Node(){
            delete left;
            delete  right;
        };
        vector<int> *preorder() const;  // (Hauptreihenfolge)
        vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        vector<int> *postorder() const; // (Nebenreihenfolge)
    };

    Node *root = nullptr;

    bool rekSearch(const int, Node*) const;

    void rekInsert(const int, Node*);

    void rekRemove(const int, Node*);

    void symetricPre(Node*);

    void recDestruct(Node*);
public:

    ~BinTree();

    bool search(const int) const;

    void insert(const int);

    void remove(const int);

    vector<int> *preorder() const;  // (Hauptreihenfolge)
    vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
    vector<int> *postorder() const; // (Nebenreihenfolge)

    friend ostream &operator<<(ostream &, const BinTree &);

};

#endif //TREES_BINTREE_H
