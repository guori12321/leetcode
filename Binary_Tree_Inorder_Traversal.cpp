//Recursively
class Solution {
public:
    vector<int> ans;

    void DFS(TreeNode *root)
    {
        if (root == NULL)
            return;
        DFS(root->left);
        ans.push_back(root->val);
        DFS(root->right);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        DFS(root);
        return ans;
    }
};

//Iteratively:
//Unlike the Preorder Traversal, we need to push and pop the roots items twice, and the second time we print the roots' val. So I just add one flag to notice weather it has been visited once or twice.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        struct flagTreeNode
        {
            TreeNode* node;
            bool flag;
        //There should be ; at the end of struct
        };

        vector<flagTreeNode> nodes;

        flagTreeNode t;
        t.node = root;
        t.flag = false;

        nodes.push_back(t);

        while(nodes.size() > 0)
        {
            flagTreeNode t = nodes.back();
            nodes.pop_back();

            if (t.node == NULL)
                continue;

            if (t.flag == true)
            {
                ans.push_back(t.node->val);
            }
            else
            {
                flagTreeNode tRight;
                tRight.node = t.node->right;
                tRight.flag = false;
                nodes.push_back(tRight);

                t.flag = true;
                nodes.push_back(t);

                flagTreeNode tLeft;
                tLeft.node = t.node->left;
                tLeft.flag = false;
                nodes.push_back(tLeft);
            }
        }

        return ans;
    }
};
