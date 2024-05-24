/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (!root) return 0;
    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;
    int Depth_l = minDepth(root->left);
    int Depth_r = minDepth(root->right);
    if (Depth_l > Depth_r) return Depth_r + 1;
    else return Depth_l + 1;
}
