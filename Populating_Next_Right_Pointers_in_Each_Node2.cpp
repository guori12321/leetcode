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

//Link by father: TLE
class Solution {
public:
    void connect(TreeLinkNode* root, TreeLinkNode* father)
    {
        if (root == NULL)
            return;

        if (father == NULL)
            root->next = NULL;
        else
        {
            if (root == father->left)
            {
                if (father->right != NULL)
                    root->next = father->right;
                else
                    connect(root, father->next);
            }
            else
                if (root == father->right)
                    connect(root, father->next);
                else
                    if (father->left != NULL)
                        root->next = father->left;
                    else
                        if (father->right != NULL)
                            root->next = father->right;
                        else
                            connect(root, father->next);
        }

        connect(root->left, root);
        connect(root->right, root);
    }

    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
};

//Link level by level
//I give up
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* leftSon = NULL, brother = NULL;

        while (root != NULL)
        {
            root->next = brother;
            if (root->left)
                leftSon = root->left;
            else
                if (root->right)
                    leftSon = root->right;
                else
                    root = root->next;



        }

    }
};
