#include <functional>
#include "AVLTree.h"

using namespace ::std;

AVLTree::Node::Node(const int k) : key(k) {}

AVLTree::Node::Node(const int k, Node *l, Node *r)
        : key(k), left(l), right(r) {}

AVLTree::Node::~Node() {
    delete left;
    delete right;
}

AVLTree::~AVLTree() {
    delete root;
}

/********************************************************************
 * Search
 *******************************************************************/
bool AVLTree::search(const int value) const {
    if (root == nullptr)
        return false;
    return root->search(value);
}

bool AVLTree::Node::search(const int value) const {
    if (value == key) return true;
    if (value < key && left != nullptr) return left->search(value);
    if (value > key && right != nullptr) return right->search(value);
    return false;
}

/********************************************************************
 * Insert
 *******************************************************************/
void AVLTree::insert(int value) {
    if (root == nullptr)
        root = new Node(value);
    else
        root->insert(value);
}

void AVLTree::Node::insert(int value) {
    if (value == key)
        return;

    if (value < key) {
        if (left == nullptr)
            left = new Node(value);
        else
            left->insert(value);
    }

    if (value > key) {
        if (right == nullptr)
            right = new Node(value);
        else right->insert(value);
    }
}

/********************************************************************
 * Remove
 *******************************************************************/

AVLTree::Node *findSymSucc(AVLTree::Node *node) {
    if (node->right == nullptr)
        return nullptr;
    auto result = node->right;
    while (result->left != nullptr) {
        result = result->left;
    }
    return result;
}

void AVLTree::remove(const int value) {
    if (root != nullptr) {
        if (root->key == value) {
            auto toDelete = root;
            if (root->left == nullptr && root->right == nullptr) {
                root = nullptr;
            } else if (root->left == nullptr) {
                root = root->right;
            } else if (root->right == nullptr)
                root = root->left;
            else {
                auto symSucc = findSymSucc(root);
                auto toDeleteNode = symSucc;
                root->right = root->right->remove(symSucc->key);
                toDeleteNode->left = nullptr;
                toDeleteNode->right = nullptr;
                root = new Node(symSucc->key, root->left, root->right);
                delete toDeleteNode;
            }
            toDelete->left = nullptr;
            toDelete->right = nullptr;
            delete toDelete;
        } else
            root->remove(value);
    }
}

AVLTree::Node *AVLTree::Node::remove(const int value) {

    if (value < key) {
        if (left != nullptr) {
            auto toDelete = left;
            left = left->remove(value);
            if (toDelete->key == value) {
                toDelete->left = nullptr;
                toDelete->right = nullptr;
                delete toDelete;
            }
        }
        return this;
    }

    if (value > key) {
        if (right != nullptr) {
            auto toDelete = right;
            right = right->remove(value);
            if (toDelete->key == value) {
                toDelete->left = nullptr;
                toDelete->right = nullptr;
                delete toDelete;
            }
        }
        return this;
    }

    if (key == value) {
        if (left == nullptr && right == nullptr)
            return nullptr;
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        auto symSucc = findSymSucc(this);
        return new Node(symSucc->key, left, right->remove(symSucc->key));
    }
    // code should not be reached, just to make the compiler happy
    return nullptr;
}

/********************************************************************
 * Traversal
 *******************************************************************/

vector<int> *AVLTree::preorder() const {
    if (root == nullptr)
        return nullptr;
    return root->preorder();
}

vector<int> *AVLTree::Node::preorder() const {
    auto vec = new vector<int>();
    // Wurzel in vec
    vec->push_back(key);
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->preorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->preorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AVLTree::inorder() const {
    if (root == nullptr)
        return nullptr;
    return root->inorder();
}

vector<int> *AVLTree::Node::inorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->inorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->inorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

vector<int> *AVLTree::postorder() const {
    if (root == nullptr)
        return nullptr;
    return root->postorder();
}

vector<int> *AVLTree::Node::postorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->postorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->postorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    return vec;
}

/********************************************************************
 * operator<<
 *******************************************************************/
std::ostream &operator<<(std::ostream &os, const AVLTree &tree) {
    function<void(std::ostream &, const int, const AVLTree::Node *, const string)> printToOs
            = [&](std::ostream &os, const int value, const AVLTree::Node *node, const string l) {

                static int nullcount = 0;

                if (node == nullptr) {
                    os << "    null" << nullcount << "[shape=point];" << endl;
                    os << "    " << value << " -> null" << nullcount
                       << " [label=\"" << l << "\"];" << endl;
                    nullcount++;
                } else {
                    os << "    " << value << " -> " << node->key
                       << " [label=\"" << l << "\"];" << endl;

                    printToOs(os, node->key, node->left, "l");
                    printToOs(os, node->key, node->right, "r");
                }
            };
    os << "digraph tree {" << endl;
    if (tree.root == nullptr) {
        os << "    null " << "[shape=point];" << endl;
    } else {
        printToOs(os, tree.root->key, tree.root->left, "l");
        printToOs(os, tree.root->key, tree.root->right, "r");
    }
    os << "}" << endl;
    return os;
}