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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        struct queueItem{
            TreeNode* root;
            int level;
        };

        vector<queueItem> queue;
        queueItem t;
        t.root = root;
        t.level = 0;
        queue.push_back(t);

        int head = 0, tail = 0;

        while (tail <= head)
        {
            queueItem t = queue[tail];
            tail++;

            if (t.root->left != NULL)
            {
                queueItem left;
                left.root = t.root->left;
                left.level = t.level+1;
                queue.push_back(left);
                head++;
            }

            if (t.root->right != NULL)
            {
                queueItem right;
                right.root = t.root->right;
                right.level = t.level+1;
                queue.push_back(right);
                head++;
            }
        }

        int nowLevel = 0;
        vector<int> tans;
        for (int i = 0; i < queue.size(); i++)
        {
            if (queue[i].level == nowLevel)
                tans.push_back(queue[i].root->val);
            else
            {
                nowLevel = queue[i].level;
                ans.push_back(tans);

                vector<int> tt;
                tans = tt;
                tans.push_back(queue[i].root->val);
            }
        }

        ans.push_back(tans);
        return ans;
    }
};

