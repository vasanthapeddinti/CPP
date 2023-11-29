/*
A Tree Data Structure can be traversed in following ways:

* Depth First Search or DFS
    * Inorder Traversal (left, root, right) - for BST, it prints elemenst in increasing order
    * Preorder Traversal (root, left, right) - used to get prefix expressions
    * Postorder Traversal (left, right, root) - used for deletion of tree
* Level Order Traversal or Breadth First Search or BFS
* Boundary Traversal
* Diagonal Traversal

This program is for DFS
*/

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

// function which creates and return a new node
Node* getNewNode(int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
} 

void printInorder(Node* new_node) {
    if (new_node == NULL) {
        return;
    }

    printInorder(new_node->left);
    cout << new_node->data << " ";
    printInorder(new_node->right);
    }
    
void preOrder(Node* new_node) {
    if (new_node == NULL) {
        return;
    }

    cout << new_node->data << " ";
    preOrder(new_node->left);
    preOrder(new_node->right);
    }    
    
void postOrder(Node* new_node) {
    if (new_node == NULL) {
        return;
    }

    postOrder(new_node->left);
    postOrder(new_node->right);
    cout << new_node->data << " ";
    }

int main() {
    
    Node* root = getNewNode(3);
    root->left = getNewNode(1);
    root->right = getNewNode(2);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(6);
    root->right->left = getNewNode(5);
    root->right->right = getNewNode(7);
    
    cout << "Inorder traversal is "<<endl;
    printInorder(root);

    cout << "\nPre-order traversal is "<<endl;
    preOrder(root);
    
    cout << "\nPost-order traversal is "<<endl;
    postOrder(root);

    return 0;
}

/*

Sample Output:

Inorder traversal is 
4 1 6 3 5 2 7 
Pre-order traversal is 
3 1 4 6 2 5 7 
Post-order traversal is 
4 6 1 5 7 2 3 
*/
