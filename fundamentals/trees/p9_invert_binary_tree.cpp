/*
In this question we have to Invert the binary tree.
So we use Post Order Treversal in which first we go in Left subtree and then in 
Right subtree then we return to Parent node.
When we come back to the parent node we swap it's Left subtree and Right subtree.
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};