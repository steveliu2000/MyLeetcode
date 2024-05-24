/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root) return false;
    if (root->val == targetSum && root->right == NULL && root->left == NULL) return true;
    int lack = targetSum - root->val;
    /*
    if (hasPathSum(root->left, lack)) return true;
    if (hasPathSum(root->right, lack)) return true;
    return false;
    */
    return (hasPathSum(root->left, lack) || hasPathSum(root->right, lack));
}
