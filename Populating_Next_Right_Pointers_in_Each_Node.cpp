/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//We can do it via BFS. However, extra O(n) space is required.
//By DFS, we just need to know the information about the right sibling, and connect the root's right son with the right sibling's left son if there is any.
class Solution {
public:
    void connect(TreeLinkNode* root, TreeLinkNode* right)
    {
        if (root == NULL)
            return;
        root->next = right;

        if (root->right == NULL)
            return;

        connect(root->left, root->right);

        if (right != NULL)
            connect(root->right, right->left);
        else
            connect(root->right, NULL);
    }

    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
};
