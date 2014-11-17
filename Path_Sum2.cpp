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
    vector<vector<int>> ansList;
    vector<int> ans;

    void DFS(TreeNode *root,int totVal, int sum)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (totVal + root-> val == sum)
            {
                ans.push_back(root->val);
                ansList.push_back(ans);
                ans.pop_back();
                return;
            }
        }

        ans.push_back(root->val);
        if (root->left != NULL)
            DFS(root->left, totVal + root->val, sum);
        if (root->right != NULL)
            DFS(root->right, totVal + root->val, sum);
        ans.pop_back();
        return;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return ansList;
        DFS(root, 0, sum);

        return ansList;
    }
};
