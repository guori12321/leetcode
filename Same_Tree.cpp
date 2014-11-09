//Note that you need to add values to stand for NULL pointers. Otherwise you need to compare both inorder traversal and one of {preorder, postorder} traversal.
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
    int valp[50000], valq[50000];
    int totp = 0, totq = 0;

    void DFSp(TreeNode *p)
    {
        if (p == NULL)
        {
            valp[totp] = -99999;
            totp++;
            return;
        }
        valp[totp] = p->val;
        totp++;

        DFSp(p->left);
        DFSp(p->right);

        return;
    }

    void DFSq(TreeNode *q)
    {
        if (q == NULL)
        {
            valq[totq] = -99999;
            totq++;
            return;
        }
        valq[totq] = q->val;
        totq++;

        DFSq(q->left);
        DFSq(q->right);

        return;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        DFSp(p);
        DFSq(q);
        if (totp != totq)
            return false;

        for (int i = 0; i < totp; i++)
            if (valp[i] != valq[i])
                return false;

        return true;
    }
};
