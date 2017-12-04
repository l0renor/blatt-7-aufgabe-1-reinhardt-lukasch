#include "BinTree.h"
#include <functional>

using namespace ::std;
BinTree::~BinTree(){
recDestruct(root);
}
void BinTree::recDestruct(Node * knoten) {
    if(knoten == nullptr){
        return;
    }
    auto l = knoten->left;
    auto r = knoten->right;
    delete knoten;
    recDestruct(l);
    recDestruct(r);
}

/********************************************************************
 * Search
 *******************************************************************/

bool BinTree::search(const int value) const {
    rekSearch(value,root);

}

bool BinTree::rekSearch(const int value, Node* knoten) const {
    if(knoten == nullptr){
        return false;
    }
    if(knoten->key == value){
        return true;
    } else if(value < knoten->key){
        return rekSearch(value,knoten->left);
    } else {
        return  rekSearch(value,knoten->right);
    }
}

/********************************************************************
 * Insert
 *******************************************************************/

void BinTree::insert(const int value) {
if(root== nullptr){
    root = new Node(value);
    return;
}
    rekInsert(value,root);
}

void BinTree::rekInsert(const int value,Node* knoten) {
if(value <knoten->key){
    if(knoten->left == nullptr){
        knoten->left = new Node(value, nullptr, nullptr);
        return;
    } else{
        return rekInsert(value,knoten->left);
    }
}else if(value > knoten->key){
    if(knoten->right == nullptr){
        knoten->right = new Node(value);
        return;
    } else{
        return rekInsert(value,knoten->right);
    }
} else{
    return; // knoten == value schon vorhanden
}
}

/********************************************************************
 * Remove
 *******************************************************************/

void BinTree::remove(const int value) {
    if(root == nullptr){
        return;
    }
    if(root->key = value){
        auto knoten = root;
        if (knoten->left == nullptr) {
            return;
        } else if (knoten->left->key == value) { //links remove
            if (knoten->left->left == nullptr && knoten->left->right == nullptr) {
                auto toRemove = knoten->left;
                knoten->left == nullptr;
                delete toRemove;
                return;
            }
            if (knoten->left->left == nullptr && knoten->left->right != nullptr) {
                auto toRemove = knoten->left;
                knoten->left = knoten->left->right;
                delete toRemove;
                return;
            }
            if (knoten->left->left != nullptr && knoten->left->right == nullptr) {
                auto toRemove = knoten->left;
                knoten->left = knoten->left->left;
                delete toRemove;
                return;
            }
            if (knoten->left->left != nullptr && knoten->left->right != nullptr) {
                auto current = knoten->right;
                auto prev = knoten;
                while (current->left != nullptr) {

                    prev = current;
                    current = current->left;
                }
                if (current->right == nullptr) {
                    knoten->key = current->key;
                    delete current;
                    return;

                } else {
                    knoten->key = current->key;
                    prev->left = current->right;
                    delete current;
                    return;

                }
            }
        }
    }


}




void BinTree::rekRemove(const int value,Node* knoten) {

    if (value < knoten->key) {
        if (knoten->left == nullptr) {
            return;
        } else if (knoten->left->key == value) { //links remove
            if (knoten->left->left == nullptr && knoten->left->right == nullptr) {
                auto toRemove = knoten->left;
                knoten->left == nullptr;
                delete toRemove;
                return;
            }
            if (knoten->left->left == nullptr && knoten->left->right != nullptr) {
                auto toRemove = knoten->left;
                knoten->left = knoten->left->right;
                delete toRemove;
                return;
            }
            if (knoten->left->left != nullptr && knoten->left->right == nullptr) {
                auto toRemove = knoten->left;
                knoten->left = knoten->left->left;
                delete toRemove;
                return;
            }
            if (knoten->left->left != nullptr && knoten->left->right != nullptr) {
                auto current = knoten->right;
                auto prev = knoten;
                while (current->left != nullptr) {

                    prev = current;
                    current = current->left;
                }
                if (current->right == nullptr) {
                    knoten->key = current->key;
                    delete current;
                    return;

                } else {
                    knoten->key = current->key;
                    prev->left = current->right;
                    delete current;
                    return;

                }
            }
            return rekRemove(value,knoten->left);
        }
    } else if (value > knoten->key) {
        if (knoten->right == nullptr) {
            return;
        } else if (knoten->right->key == value) { //rechts remove
            if (knoten->right->left == nullptr && knoten->right->right == nullptr) {
                auto toRemove = knoten->right;
                knoten->right == nullptr;
                delete toRemove;
                return;
            }
            if (knoten->right->left == nullptr && knoten->right->right != nullptr) {
                auto toRemove = knoten->right;
                knoten->right = knoten->right->right;
                delete toRemove;
                return;
            }
            if (knoten->right->left != nullptr && knoten->right->right == nullptr) {
                auto toRemove = knoten->right;
                knoten->right = knoten->right->left;
                delete toRemove;
                return;
            }
            if (knoten->right->left != nullptr && knoten->right->right != nullptr) {
                auto current = knoten->right;
                auto prev = knoten;
                while (current->left != nullptr) {

                    prev = current;
                    current = current->left;
                }
                if (current->right == nullptr) {
                    knoten->key = current->key;
                    delete current;
                    return;

                } else {
                    knoten->key = current->key;
                    prev->left = current->right;
                    delete current;
                    return;

                }
            }
            return rekRemove(value,knoten->right);
        }


    }
}

/********************************************************************
 * Traversal
 *******************************************************************/

vector<int> *BinTree::preorder() const {
    if (root == nullptr)
        return nullptr;
    return root->preorder();
}

vector<int> *BinTree::Node::preorder() const {
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

vector<int> *BinTree::inorder() const {
    if (root == nullptr)
        return nullptr;
    return root->inorder();
}

vector<int> *BinTree::Node::inorder() const {
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

vector<int> *BinTree::postorder() const {
    if (root == nullptr)
        return nullptr;
    return root->postorder();
}

vector<int> *BinTree::Node::postorder() const {
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
std::ostream &operator<<(std::ostream &os, const BinTree &tree) {
    function<void(std::ostream &, const int, const BinTree::Node *, const string)> printToOs
            = [&](std::ostream &os, const int value, const BinTree::Node *node, const string l) {

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
