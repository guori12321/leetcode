/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findDepth(TreeNode *root, int depth)
    {
        if (root == NULL)
            return depth;
        int left = findDepth(root->left, depth + 1);
        int right = findDepth(root->right, depth + 1);
        return left>right?left:right;
    }
    int maxDepth(TreeNode *root) {
        return findDepth(root, 0);
    }
};
