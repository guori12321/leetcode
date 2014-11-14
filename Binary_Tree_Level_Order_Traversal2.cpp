//BFS + post dealing data
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;

        struct queueItem
        {
            int level;
            TreeNode *root;
        };

        vector<queueItem> queue;
        int head = 0, tail = 0;

        if (root == NULL)
            return ans;

        queueItem t;
        t.level = 0;
        t.root = root;
        queue.push_back(t);

        while (tail <= head)
        {
            queueItem t = queue[tail];
            tail++;

            if (t.root->left != NULL)
            {
                queueItem left;
                left.root = t.root->left;
                left.level = t.level + 1;
                queue.push_back(left);
                head++;
            }

            if (t.root->right != NULL)
            {
                queueItem right;
                right.root = t.root->right;
                right.level = t.level + 1;
                queue.push_back(right);
                head++;
            }
        }

        t = queue.back();
        int levelMax = t.level;

        for (int i = levelMax; i >= 0; i--)
        {
            int last = head;
            while (queue[head].level == i && head >= 0)
                head--;

            vector<int> tans;
            for (int k = head+1; k <= last; k++)
                tans.push_back(queue[k].root->val);
            ans.push_back(tans);
        }

        return ans;
    }
};
