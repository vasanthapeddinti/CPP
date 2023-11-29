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

    void printAtKDistance(Node *node, int k) {
        if (node == NULL || k < 0) {
            return;
        }

        if (k == 0) {
            cout << node->data << " "; // print happens only when we reach k
        }
        printAtKDistance(node->left, k-1); // This is just travrsal until k depth
        printAtKDistance(node->right, k-1);

        /*
        The untold assumption is 
        
                                    5                0
                                 /      \
                                4        2.          1
                               / \
                              9   6                  2
                             /
                            45                       3
        
        levels are assumed like this
        
        If we want to print at level 2, traverse till k == 0 and print nodes
        */
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
    root1->right->right->right = temp->getNode(102);
    root1->right->right->right->right = temp->getNode(1022);

    temp->printInorder(root1);
    
    cout << "\n\n\n";
    temp->printAtKDistance(root1, 2);
    
    return 0;
}