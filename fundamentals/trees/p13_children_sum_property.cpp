// sum of chidren = parent
// you can not decrement any node value

/*
Self Notes 📜:
🥥 if both children sum is less than parent, make children's value to parent's value.
🥥 if both children values sum is greater than or equal to parent, make parent's value to children's sum.
🥥 recursively go left and right. Traversal type: DFS.
🥥 when coming back up the tree, take children sum and replace it in parent.
🥥 at any point we reach null, just return (base case)
🥥 Intuition: while going down, increase the children values so we make sure to never fall short, then all we have to do is sum both children and replace it in parent.
*/

#include <iostream>
#include <vector>

using namespace std;


void changeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    int child = 0;

    if (root->left) {
        child += root->left->data;
    }

    if (root->right) {
        child += root->right->data;
    }

    if (child >= root->data) {
        root->data = child;
    }
    else {
        if (root->left) {
            root->left->data = root->data;
        }
        else if (root->right) {
            root->right->data = root->data;
        }
    }

    changeTree(root->left); // move to left and  right
    changeTree(root->right);

    int total = 0;
    if (root->left) {
        total += root->left->data;
    }

    if (root->right) {
        total += root->right->data;
    }

    if (root->left || root->right) {
        root->data = total;
    }
}