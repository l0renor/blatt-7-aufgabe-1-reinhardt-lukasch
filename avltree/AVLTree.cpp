#include <functional>
#include "AVLTree.h"

using namespace ::std;
/// \param k key of the node
AVLTree::Node::Node(const int k) : key(k) {}
/// \param k key of the node
/// \param p parent of the node
AVLTree::Node::Node(const int k, Node *p) : key(k),parent(p) {}
/// \param k key of the node
/// \param p parent of the node
/// \param l left child of the node
/// \param r right child of the node
AVLTree::Node::Node(const int k, Node *l, Node *r, Node *p)
        : key(k), left(l), right(r), parent(p){}

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
/// \param value value which schould be searched
/// \returns whether given value is present in the tree
bool AVLTree::search(const int value) const {
    if (root == nullptr)
        return false;
    return root->search(value);
}
/// \param value value which is searched
/// \returns whether given value is present in the tree
bool AVLTree::Node::search(const int value) const {
    if (value == key) return true;
    if (value < key && left != nullptr) return left->search(value);
    if (value > key && right != nullptr) return right->search(value);
    return false;
}

/********************************************************************
 * Insert
 *******************************************************************/

/// \param value value to be inserted
void AVLTree::insert(int value) {
    if (root == nullptr)
        root = new Node(value);
    else
        root->insert(value,this);
}
/// \param value value to be inserted
/// \param tree passes on the tree in case the root needs to be changed
void AVLTree::Node::insert(int value, AVLTree *tree) {
    if (value == key)
        return;

    if (value < key) {
         if(left == nullptr){
             left = new Node(value,this);
             if(balance == 0) {
                 balance = -1;
                 upin(tree);
             } else {
                 balance = 0;
             }

             } else left->insert(value,tree);
         }


    if (value > key) {
        if (right == nullptr) {
            right = new Node(value,this);

            if (balance == 0) {
                balance = 1;
                upin(tree);
            } else {
                balance = 0;
            }


        }
        else right->insert(value,tree);
    }
}
/// \param tree passes on the tree in case the root needs to be changed
void AVLTree::Node::upin(AVLTree* tree) {
    if(parent == nullptr){
        return;
    }
    if(this == parent->left){
        if(parent->balance == 1)
            parent->balance =0;
        else if (parent->balance == 0){
            parent->balance = -1;
            parent->upin(tree);
        }
        else if(parent->balance == -1){
            if(balance == -1){
                parent->rotateRight(tree);
            } else if(balance = 1) {
                auto p = parent;
                rotateLeft(tree);
                p->rotateRight(tree);
                balance = -1;
            }
        }
    } else {
        if(parent->balance == -1) {
            parent->balance = 0;
            return;
        }
        if (parent->balance == 0){
            parent->balance =1;
            parent->upin(tree);
            return;
        }

        if(parent->balance == 1){
                if(balance == 1){
                    parent->rotateLeft(tree);
                } else if(balance = -1) {
                    auto p = parent;
                    rotateRight(tree);
                    p->rotateLeft(tree);
                    balance = 1;
                }
        }

    }

}
/// \param tree passes on the tree in case the root needs to be changed
void AVLTree::Node::rotateRight(AVLTree *tree){
    auto x = left;
    if(this == tree->root ){
        tree->root = x;
    } else if (parent->left == this){
        parent->left = x;
    }
    else {
        parent->right = x;
    }
    x->balance = 0;
    balance = 0;
    left = left->right;
    if(left != nullptr)
        left->parent = this;
    x->right = this;
    x->parent = parent;
    parent = x;

}
/// \param tree passes on the tree in case the root needs to be changed
void AVLTree::Node::rotateLeft(AVLTree *tree){

    auto x = right;
    if(this == tree->root){
        tree->root = x;
    }
    else if (parent->left == this){
        parent->left =x;
    }
    else {
        parent->right = x;
    }
    x->balance  = 0;
    balance = 0;

    right = right->left;
    x->left = this;
    x->parent = parent;
    parent = x;

}


/********************************************************************
 * Remove
 *******************************************************************/
/// \param node node of which the successor should be looked for
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
            //TODO Wenn key = value
            /*auto toDelete = root;
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
                root = new Node(symSucc->key, root->left, root->right, nullptr);
                delete toDeleteNode;
            }
            toDelete->left = nullptr;
            toDelete->right = nullptr;
            delete toDelete;*/
        } else
            root->remove(value, this);
    }
}

AVLTree::Node *AVLTree::Node::remove(const int value, AVLTree *tree) {

    if (value < key) {
        if (left != nullptr) {
            auto toDelete = left;
            left = left->remove(value, tree);
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
            right = right->remove(value, tree);
            if (toDelete->key == value) {
                toDelete->left = nullptr;
                toDelete->right = nullptr;
                delete toDelete;
            }
        }
        return this;
    }

    if (key == value) {
        if (left == nullptr && right == nullptr) {
            // Both successors are leafs

            if (parent->left->key == key) {
                // Node is left successor of parent

                if (parent->right == nullptr) {
                    // Parent has height 0
                    parent->balance = 0;
                    tree->upoutNode = parent;
                } else if (parent->right->right != nullptr && parent->right->left != nullptr) {
                    // Parent has height 1
                    parent->balance = 1;
                } else {
                    // Parent has height 2
                    //TODO Rotation zum Ausgleichen & upout()

                }
            } else {
                // Node is right successor of parent

                if (parent->left == nullptr) {
                    // Parent has height 0
                    parent->balance = 0;
                    tree->upoutNode = parent;
                } else if (parent->left->left == nullptr && parent->left->right == nullptr) {
                    // Parent has height 1
                    parent->balance = 1;
                } else {
                    // Parent has height 2
                    //TODO Rotation zum Ausgleich & upout()
                }
            }
            return this;
        } else if (left == nullptr) {
            // Left successor is a leaf

            if (parent->left->key == key) {
                // parent.left = right
            } else {
                // parent.right = right
            }
            tree->upoutNode = parent;
            return this;
        } else if (right == nullptr) {
            // Right successor is a leaf

            if (parent->left->key == key) {
                // parent.left = left
            } else {
                // parent.right = left
            }
            tree->upoutNode = parent;
            return this;
        } else {
            // Both successors are nodes
            auto symSucc = findSymSucc(this);
            return new Node(symSucc->key, left, right->remove(symSucc->key, tree), parent);
        }
    }
    // code should not be reached, just to make the compiler happy
    return nullptr;
}

void AVLTree::Node::upout(AVLTree* tree) {
    if (parent == nullptr) {
        return;
    }

    if (parent->left->key == key) {
        // Node is left successor of parent

        if(parent->balance == -1) {
            parent->balance = 0;
            parent->upout(tree);
        } else if (parent->balance == 0) {
            parent->balance = 1;
        } else {
            // Parent's balance must be 1
            if (parent->right->balance == 0) {
                parent->rotateLeft(tree);
            } else if (parent->right->balance == 1) {
                auto r = parent->right;
                rotateLeft(tree);
                r->upout(tree);
            } else {
                // Right brothers balance must be -1
                //TODO Double Rotate right-left
            }
        }
    } else {
        // Node is right successor of parent

        if(parent->balance == 1) {
            parent->balance = 0;
            parent->upout(tree);
        } else if (parent->balance == 0) {
            parent->balance = 1;
        } else {
            // Parent's balance must be -1
            if(parent->left->balance == 0) {
                parent->rotateRight(tree);
            } else if (parent->left->balance == -1) {
                auto l = parent->left;
                rotateLeft(tree);
                l->upout(tree);
            } else {
                // Left brother's balance must be 1
                //TODO Double Rotate left-right
            }
        }

    }

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

vector<int> *AVLTree::inorderBalance() const {
    if (root == nullptr)
        return nullptr;
    return root->inorderBalance();
}

vector<int> *AVLTree::Node::inorderBalance() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->inorderBalance();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // Wurzel in vec
    vec->push_back(balance);
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->inorderBalance();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
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