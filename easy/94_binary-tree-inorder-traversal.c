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
int Tra(struct TreeNode* root, int* ptr, int count) {
    if (root != NULL) {
        count = Tra(root->left, ptr, count);
        ptr[count] = root->val;
        ++count;
        count = Tra(root->right, ptr, count);
    }
    return count;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ptr = malloc(sizeof(int) * 100);
    int count = 0;
    count = Tra(root, ptr, count);
    *returnSize = count;
    return ptr;
}
