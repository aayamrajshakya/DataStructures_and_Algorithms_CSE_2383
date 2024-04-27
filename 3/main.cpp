#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right, *left;

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
    Node* root;

    bool insert(Node*& node, int data) {
        if (node == NULL) {
            node = new Node();
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

    bool remove(Node*& node, int data) {
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
            Node* tmp = node;
            if (node->left != NULL) {
                node = node->left;
            }
            else {
                node = node->right;
            }
            delete tmp;
        }
        else {
            Node* tmp = node->left;
            while (tmp->right != NULL) {
                tmp = tmp->right;
            }
            node->data = tmp->data;
            remove(node->left, tmp->data);
        }
        return true;
    }

    bool find(Node* node, int data) {
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

    void inOrder(Node* node, ostream& os) {
        if (node == NULL) {
            return;
        }
        inOrder(node->left, os);
        os << node->data << " ";
        inOrder(node->right, os);
    }

    void preOrder(Node* node, ostream& os) {
        if (node == NULL) {
            return;
        }
        os << node->data << " ";
        preOrder(node->left, os);
        preOrder(node->right, os);
    }

    void postOrder(Node* node, ostream& os) {
        if (node == NULL) {
            return;
        }
        postOrder(node->left, os);
        postOrder(node->right, os);
        os << node->data << " ";
    }

    void destroy(Node*& node) {
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

int main() {
    BST b;
    b.insert(56);
    b.insert(34);
    b.insert(70);
    b.insert(5);
    b.insert(1);
    b.insert(42);
    b.insert(40);
    b.insert(52);
    b.insert(62);
    b.insert(57);
    b.insert(89);
    b.insert(90);
    cout << b.find(44) << endl;
    cout << b.find(62) << endl;
    b.remove(62);
    cout << b.find(62) << endl;
    b.insert(44);
    cout << b.find(44) << endl;
    b.postOrder(cout);
    b.preOrder(cout);
    b.inOrder(cout);
    return 0;
}


