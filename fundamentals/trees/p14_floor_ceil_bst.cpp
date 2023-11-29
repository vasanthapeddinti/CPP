#include <iostream> 

using namespace std;

int findCeil(BinaryTreeNode* node, int num) {
    int ceil = -1;

    while (node != NULL) {
        if (num == node->data) {
            ceil = node->data;
        }
        else if (num < node->data) {
            ceil = node->data;
            num = num->left;
        }
        else {
            num = num->right;
        }
    }
    return ceil;
}

int findFloor(BinaryTreeNode* node, int key) {
    int floor = -1;
    while (node != NULL) {
        if (node->val == key) {
            return node;
        }
        else if (key > node->val) {
            floor = node->val;
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return floor;
}