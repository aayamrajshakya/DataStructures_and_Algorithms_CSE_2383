#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* right, *left;

    int degree() {
        if (right != nullptr && left != nullptr) {return 2;}
        else if (right != nullptr || left != nullptr) {return 1;}
        else{return 0;}
    }
};

class BST {
private:
    TreeNode* root;

    bool insert(TreeNode*& node, int data) {
        if (node == nullptr) {
            node = new TreeNode();
            node->data = data;
            node->right = node->left = nullptr;
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


    bool find(TreeNode* node, int data) {
        if (node == nullptr) {
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

public:
    BST() : root(nullptr) {}

    bool insert(int data) {
        return insert(root, data);
    }

    bool find(int data) {
        return find(root, data);
    }

};
