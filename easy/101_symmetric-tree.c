/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSym(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) return true;

    if (p && q) {
        if (p->val != q->val) return false;
        if (!isSym(p->left, q->right)) return false;
        if (!isSym(p->right, q->left)) return false;
        return true;
    }
    else return false;
}

bool isSymmetric(struct TreeNode* root) {
    return isSym(root->left, root->right);
}
