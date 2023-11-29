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
    
    int printLeastNode(Node *node) {
        if (node == NULL) {
            return -1;
        }
        
        while (node->left != NULL) {
            node = node->left;
        }
        return node->data;
    }
    
    int printMaxNode(Node *node) {
        if (node == NULL) {
            return -1;
        }
        
        while (node->right != NULL) {
            node = node->right;
        }
        return node->data;
    }

};

int main() {
    
    int minValue, maxValue;
    class NodeOperation *temp = new NodeOperation();
    

    Node *root = temp->getNode(6);
    root->left = temp->getNode(3);
    root->left->left = temp->getNode(1);
    root->left->right = temp->getNode(2);
    root->right = temp->getNode(8);
    root->right->left = temp->getNode(7);
    root->right->right = temp->getNode(10);

    temp->printInorder(root);
    
    minValue = temp->printLeastNode(root);
    cout << "\nLeast number is " << minValue; 
    
    maxValue = temp->printMaxNode(root);
    cout << "\nMax value is " << maxValue;
    return 0;
}

/*

Sample output:

1 3 2 6 7 8 10 
Least number is 1
Max value is 10


*/