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

    int isIdentical(Node *rootA, Node *rootB) {
        // if both are null, they are identical
        if (rootA == NULL && rootB == NULL) {
            return 1;
        }
        
        // if both are not null, compare
        if (rootA != NULL && rootB != NULL){
            return (rootA->data == rootB->data && isIdentical(rootA->left, rootB->left) && isIdentical(rootA->right, rootB->right));
        }
        // if one is null and other is non null
        return 0;

    }

};

int main() {
    
    int minValue, maxValue;
    class NodeOperation *temp = new NodeOperation();
    

    Node *root1 = temp->getNode(6);
    root1->left = temp->getNode(3);
    root1->left->left = temp->getNode(1);
    root1->left->right = temp->getNode(2);
    root1->right = temp->getNode(8);
    root1->right->left = temp->getNode(7);
    root1->right->right = temp->getNode(10);

    temp->printInorder(root1);
    
    cout << "\n\n\n";
    Node *root2 = temp->getNode(6);
    root2->left = temp->getNode(3);
    root2->left->left = temp->getNode(1);
    root2->left->right = temp->getNode(2);
    root2->right = temp->getNode(8);
    root2->right->left = temp->getNode(7);
    root2->right->right = temp->getNode(10);

    temp->printInorder(root2);
    
    cout << "\n\n\n";
    Node *root3 = temp->getNode(6);
    root3->left = temp->getNode(3);
    root3->left->left = temp->getNode(1);
    root3->left->right = temp->getNode(2);
    root3->right = temp->getNode(8);
    root3->right->left = temp->getNode(7);
    root3->right->right = temp->getNode(11);

    temp->printInorder(root3);

    
    
    if (temp->isIdentical(root1, root2)) {
        cout << "\nidentical trees";
    }
    else {
        cout << "\nnot identical";
    }
    
    if (temp->isIdentical(root1, root3)) {
        cout << "\nidentical trees";
    }
    else {
        cout << "\nnot identical";
    }
    
    return 0;
}

/*

Sample Output:

1 3 2 6 7 8 10 


1 3 2 6 7 8 10 


1 3 2 6 7 8 11 
identical trees
not identical

*/