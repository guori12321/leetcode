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
    bool DFS(TreeNode *root, int val, int sum)
    {
        //The node with no left or right child is a leave
        if (root->left == NULL && root->right == NULL)
            if (val + root->val == sum)
                return true;
            else
                return false;

        bool a = false;
        if (root->left != NULL)
            a = DFS(root->left, val+root->val, sum);
        bool b = false;
        if (root->right != NULL)
            b = DFS(root->right, val+root->val, sum);
        return a||b;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        //Attention to what we should give about {}, 0, leetcode thinks it should be false
        if (root == NULL)
            return false;
        return DFS(root, 0, sum);
    }
};


