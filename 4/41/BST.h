#include <iostream>
using namespace std;

class NodeBST {
public:
    int data;
    NodeBST* right, *left;

    int degree() {
        if (left != NULL && right != NULL) {
            return 2;
        }
        else if (left != NULL || right != NULL) {
            return 1;
        }
        else{
            return 0;
        }
    }
};

class BST {
private:
    NodeBST* root;

    bool insert(NodeBST*& node, int data) {
        if (node == NULL) {
            node = new NodeBST();
            node->data = data;
            node->right = node->left = NULL;
            return true;
        }
        if (data < node->data) {
            return insert(node->left, data);
        }
        else if (data > node->data) {
            return insert(node->right, data);
        }
        return false;
    }

    bool remove(NodeBST*& node, int data) {
        if (node == NULL) {
            return false;
        }
        if (data < node->data) {
            return remove(node->left, data);
        }
        else if (data > node->data) {
            return remove(node->right, data);
        }
        
        int deg = node->degree();
        if (deg == 0) {
            delete node;
            node = NULL;
        }
        else if (deg == 1) {
            NodeBST* tmp = node;
            if (node->left != NULL) {
                node = node->left;
            }
            else {
                node = node->right;
            }
            delete tmp;
        }
        else {
            NodeBST* tmp = node->left;
            while (tmp->right != NULL) {
                tmp = tmp->right;
            }
            node->data = tmp->data;
            remove(node->left, tmp->data);
        }
        return true;
    }

    bool find(NodeBST* node, int data) {
        if (node == NULL) {
            return false;
        }
        if (data < node->data) {
            return find(node->left, data);
        }
        else if (data > node->data) {
            return find(node->right, data);
        }
        else {
            return true;
        }
    }

    void inOrder(NodeBST* node, ostream& os) {
        if (node == NULL) {
            return;
        }
        inOrder(node->left, os);
        os << node->data << " ";
        inOrder(node->right, os);
    }

    void preOrder(NodeBST* node, ostream& os) {
        if (node == NULL) {
            return;
        }
        os << node->data << " ";
        preOrder(node->left, os);
        preOrder(node->right, os);
    }

    void postOrder(NodeBST* node, ostream& os) {
        if (node == NULL) {
            return;
        }
        postOrder(node->left, os);
        postOrder(node->right, os);
        os << node->data << " ";
    }

    void destroy(NodeBST*& node) {
        if (node == NULL) {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
        node = NULL;
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroy(root);
    }

    bool insert(int data) {
        return insert(root, data);
    }

    bool remove(int data) {
        return remove(root, data);
    }

    bool find(int data) {
        return find(root, data);
    }

    void inOrder(ostream& os) {
        os<<"inOrder: ";
        inOrder(root, os);
        os<<endl;
    }

    void preOrder(ostream& os) {
        os<<"preOrder: ";
        preOrder(root, os);
        os<<endl;
    }

    void postOrder(ostream& os) {
        os<<"postOrder: ";
        postOrder(root, os);
        os<<endl;
    }
};