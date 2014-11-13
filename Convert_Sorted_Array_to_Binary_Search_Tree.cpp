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

    void DFS(int l, int r, TreeNode* root, vector<int> &num)
    {
        if (l > r)
            return;

        int m = (l+r)/2;
        root->val = num[m];

        //We have to check the boundary, otherwise there will be 0 in the NULL nodes
        if (l <= m-1)
        {
            root->left = new TreeNode(0);
            DFS(l, m-1, root->left, num);
        }

        if (m+1 <= r)
        {
            root->right = new TreeNode(0);
            DFS(m+1, r, root->right, num);
        }
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        //Note about empty input
        if (num.size() == 0)
            return NULL;

        //You have to pass a value to new a TreeNode
        //The following is the given initialize function
        //TreeNode(int x) : val(x), left(NULL), right(NULL) {}

        TreeNode *ans = new TreeNode(0);
        //Note about the boundary
        DFS(0, num.size() - 1, ans, num);
        return ans;
    }
};
