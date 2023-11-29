#include <iostream>
#include <vector>

using namespace std;


bool getPath(TreeNode* root, vector<int> &arr, int n) {
    if (root == NULL) {
        return false;
    }

    arr.push_back(root->val);

    if (root->val == n) {
        return true;
    }

    if (getPath(node->left, arr, n) || getPath(node->right, arr, n)) {
        return true;
    }

    arr.pop_back();

    turn false;
}


vector<int> solve(TreeNode* root, int n) {
    vector<int> arr;

    if (root == NULL) {
        return arr;
    }

    getPath(root, arr, n);
    return arr;
}

// T - O(n)
// S - O(h)