/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorder(struct TreeNode* root, int* arr, int* returnSize) {
    if (!root) return;
    postorder(root->left, arr, returnSize);
    postorder(root->right, arr, returnSize);
    arr[*returnSize] = root->val;
    ++(*returnSize);
    return;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = malloc(sizeof(int) * 100);
    *returnSize = 0;
    postorder(root, arr, returnSize);
    return arr;
}
