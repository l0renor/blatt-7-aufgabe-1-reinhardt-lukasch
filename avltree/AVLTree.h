#ifndef TREES_BINTREE_H
#define TREES_BINTREE_H

#include <iostream>
#include <vector>

using namespace std;

///Selft balanceing AVL tree
/// \authors Fabian Reinold, Leon Lukas
class AVLTree {

private:
    /// A node of the tree
    struct Node {
        /// Key of the node
        const int key;
        /// The balance factor of the node
        int balance = 0;
        /// left child
        Node *left = nullptr;
        /// right child
        Node *right = nullptr;
        /// parent of the node
        Node *parent = nullptr;
        ///creates Node with a key and no relatives
        Node(const int);
        /// creates Node with a key and a parent
        Node(const int, Node*);
        /// creates Node with a key and a parent and two childs
        Node(const int, Node *, Node *,Node *);
        /// Node destructor
        ~Node();
        /// recursive seach method implemented in the node
        bool search(const int) const;
        /// recursive insert method implemented in the node
        void insert(const int,AVLTree *);
        /// recursive  method to make shure the tree is still balanced after an insert
        void upin(AVLTree *);
        ///right rotation around this node
        void rotateRight(AVLTree*);
        ///left rotation around this node
        void rotateLeft(AVLTree*);
        /// recursive remove method implemented in the node
        Node *remove(const int);
        /// recursive remove method implemented in the node
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


    /// Preorder traversal
    vector<int> *preorder() const; // (Hauptreihenfolge)
    /// Inorder traversal
    vector<int> *inorder() const; // (Symmetrische Reihenfolge)
    /// Postorder traversal
    vector<int> *postorder() const; // (Nebenreihenfolge)
    /// Inorder traversal of balance factors only needed for testing
    vector<int> *inorderBalance() const; // testing
    /// Searches the symetric succsessor of given node
    friend Node *findSymSucc(Node *);
    /// outputs the tree for Graphviz
    friend ostream &operator<<(ostream &, const AVLTree &);

};

#endif //TREES_BINTREE_H