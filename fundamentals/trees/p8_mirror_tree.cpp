// print nodes at k distance from root
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

    void mirrorTree(Node *node) {
        if (node == NULL) {
            return;
        }
        
        mirrorTree(node->left);
        mirrorTree(node->right);
        
        Node *temp;
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

};

int main() {
    
    class NodeOperation *temp = new NodeOperation();
    
    Node *root1 = temp->getNode(6);
    root1->left = temp->getNode(3);
    root1->left->left = temp->getNode(1);
    root1->left->right = temp->getNode(2);
    root1->right = temp->getNode(8);
    root1->right->left = temp->getNode(7);
    root1->right->right = temp->getNode(10);
    
    cout << "Constructed tree is \n"; 
    temp->printInorder(root1);
    
    cout << "\n\n\n";
    cout << "Mirror tree is \n"; 
    temp->mirrorTree(root1);
    temp->printInorder(root1);
    
    return 0;
}

/*

Sample output:

Constructed tree is 
1 3 2 6 7 8 10 


Mirror tree is 
10 8 7 6 2 3 1  

*/