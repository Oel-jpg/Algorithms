#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T key;
    Node<T> *left;
    Node<T> *right;

    Node() {
        key = T();
        left = nullptr;
        right = nullptr;
    }

    Node(T key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    };
};

template <typename T>
class BinaryTree {
    private:
    Node<T> *root;
    
    public:
    
    BinaryTree() {
        root = nullptr;
    }

    void push(T key) {
        Node<T> *newNode = new Node<T>(key);

        if(root == nullptr) {
            root = newNode;
            return;
        }

        Node<T> *curr = root;
        Node<T> *prev = nullptr;

        while (curr != nullptr) {
            prev = curr;
            if (key > curr->key) 
                curr = curr->right;
            else 
                curr = curr-> left;
        };

        if(key > prev->key) 
            prev->right = newNode;
        else
            prev->left = newNode;


    }

    void inorder(Node <T> *curr) {
        if (curr == nullptr) 
        return;

        inorder(curr->left);
        cout << curr->key << endl;
        inorder(curr->right);

    }   

    void traversal(){
        cout<<"Inorder traversal" << endl;
        inorder(root);
        cout << endl;
    }

};

int main(){
    
    BinaryTree <int> tree;

    tree.push(5);
    tree.push(10);
    tree.push(4);
    tree.push(2);
    tree.push(16);
    tree.push(7);
    tree.push(1);
    tree.push(20);
    tree.push(15);
    tree.push(3);

    tree.traversal();
    
    return 0;
}

