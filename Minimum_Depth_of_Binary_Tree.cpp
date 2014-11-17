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
    int DFS(TreeNode *root, int sum)
    {
        if (root == NULL)
            return sum;

        //They ask the length of the path, rather than the sum of the values...
        root->val = 1;

        if (root->left == NULL && root->right == NULL)
            return sum + root->val;

        //You can not just return min(DFS(left), DFS(right)), otherwise the nodes with one child will be treated as leaves.
        int a = INT_MAX;
        if (root->left != NULL)
            a = DFS(root->left, sum+root->val);
        int b = INT_MAX;
        if (root->right != NULL)
            b = DFS(root->right, sum+root->val);

        return min(a, b);
    }
    int minDepth(TreeNode *root) {
        //The root node is at level 1, and if we have a root, we will return 1
        return DFS(root, 0);
    }
};
