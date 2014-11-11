/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//vector.push_back(item)
//vector.pop_back(item)

//Recursive
class Solution {
public:
    vector<int> ans;

    void DFS(TreeNode *root)
    {
        if (root == NULL)
            return;

        ans.push_back(root->val);
        DFS(root->left);
        DFS(root->right);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        DFS(root);
        return ans;
    }
};

//Iterative: Preorder search is still DFS search: use a stack manually
//Pay attention to NULL input
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        vector<TreeNode*> nodes;

        nodes.push_back(root);

        while (nodes.size() > 0)
        {
            //a += b.back();
            //b.pop_back();
            //Note that pop_back() returns void
            TreeNode* t = nodes.back();
            nodes.pop_back();

            if (t == NULL)
                continue;

            ans.push_back(t->val);

            //Attention to the order!!! In the stack we push Right first, and Left second, so that we can get left first.
            if (t->right != NULL)
                nodes.push_back(t->right);
            if (t->left != NULL)
                nodes.push_back(t->left);

        }

        return ans;
    }
};
