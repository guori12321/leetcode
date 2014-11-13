//Pay more attention to reading the question:
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//It's NOT complete tree. For instance, {1,2,2,3,3,3,3,4,4,4,4,4,4,#,#,5,5} is not a complete tree but a height-balanced tree.

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
    //initialized with max and min value, rather than all with 0.
    int minDep = INT_MAX, maxDep = INT_MIN;
    bool ans = true;

    int findDepth(TreeNode *root, int level)
    {
        if (ans == false)
            return 0;

        if (root == NULL)
            return level;

        int leftDep = findDepth(root->left, level+1);
        int rightDep = findDepth(root->right, level+1);

        if (abs(leftDep - rightDep) > 1)
            ans = false;

        return max(leftDep, rightDep);
    }

    bool isBalanced(TreeNode *root) {
        findDepth(root, 0);

        return ans;
    }
};

