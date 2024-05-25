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
void preorder(struct TreeNode* root, int* arr, int* returnSize) {
    if (!root) return;
    arr[*returnSize] = root->val;
    ++(*returnSize);
    preorder(root->left, arr, returnSize);
    preorder(root->right, arr, returnSize);
    return;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = malloc(sizeof(int) * 100);
    *returnSize = 0;
    preorder(root, arr, returnSize);
    return arr;
}
