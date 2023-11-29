// Depth First Search - Recursive

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
};

class NodeOperation{
    public:

    Node *getNode(int new_data) {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    
    void printInorder(Node *node) {
        if (node == NULL) {
            return;
        }

        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }
    
    int maxDepth(Node *node) {
        if (node == NULL) {
            return 0;
        }
        
        return (1 + max(maxDepth(node->left), maxDepth(node->right)));
    }


};

int main() {
    
    int depth;
    class NodeOperation *temp = new NodeOperation();
    

    Node *root1 = temp->getNode(6);
    root1->left = temp->getNode(3);
    root1->left->left = temp->getNode(1);
    root1->left->right = temp->getNode(2);
    root1->right = temp->getNode(8);
    root1->right->left = temp->getNode(7);
    root1->right->right = temp->getNode(10);
    root1->right->right->right = temp->getNode(102);
    root1->right->right->right->right = temp->getNode(1022);

    temp->printInorder(root1);
    
    depth = temp->maxDepth(root1);
    
    cout << "\nDepth of tree is " << depth;
    
    return 0;
}

