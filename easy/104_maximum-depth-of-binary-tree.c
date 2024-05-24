/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    int Depth_l = maxDepth(root->left);
    int Depth_r = maxDepth(root->right);
    if (Depth_l > Depth_r) return Depth_l + 1;
    else return Depth_r + 1;
}
