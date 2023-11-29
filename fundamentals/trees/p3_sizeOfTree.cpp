// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
};

class NodeOperation{

    public:
    
    Node* getNewNode(int new_data) {
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    
    void printInorder(Node* node) {
        if (node == NULL) {
            return;
        }    
        
        printInorder(node->left);
        cout<< node->data << " ";
        printInorder(node->right);
    }
    
    int sizeOfTree(Node* node) {
        if (node == NULL) {
            return 0;
        }
        
        return (sizeOfTree(node->left) + 1 + sizeOfTree(node->right));
    }

};


int main() {
    int treeSize = 0;
    
    class NodeOperation *temp = new NodeOperation();

    Node* root = temp->getNewNode(3);
    root->left = temp->getNewNode(1);
    root->right = temp->getNewNode(2);
    root->left->left = temp->getNewNode(4);
    root->left->right = temp->getNewNode(6);
    root->right->left = temp->getNewNode(5);
    root->right->right = temp->getNewNode(7);
    
    cout << "print InOrder of tree is \n";
    temp->printInorder(root);
    
    treeSize = temp->sizeOfTree(root);
    cout << "\nTree size is " << treeSize << endl;

    return 0;
}

/*

Sample Output:

print InOrder of tree is 
4 1 6 3 5 2 7 
Tree size is 7

*/