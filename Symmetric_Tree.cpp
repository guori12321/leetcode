//Note that the entire tree is symmetric doesn't mean the left and right subtree are both symmetric. So we need to search the whole tree.

//Pay attention to empty input

//BFS Version.

//BFS Version.
//Failed!!
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;

        struct {
            int val;
            TreeNode *root;
            int level;
        }result[50000];
        int head = 0;
        int tail = 0;

        result[0].root = root;
        result[0].level = 0;

        while (head >= tail){
            TreeNode* node = result[tail].root;
            if (node != NULL){
                head += 1;
                result[head].root = node->left;
                if (node->left != NULL)
                    result[head].val = node->left->val;
                else
                    result[head].val = -99999;
                result[head].level = result[tail].level + 1;

                head += 1;
                result[head].root = node->right;
                if (node->right != NULL)
                    result[head].val = node->right->val;
                else
                    result[head].val = -99999;
                result[head].level = result[tail].level + 1;
            }

            tail += 1;
        }

        int left = 0, right = 0, maxLevel = result[head].level;
        for (int i = 0; i <= maxLevel; i++) {
            for (left = 0; left <= head; left++)
                if (result[left].level == i)
                    break;

            for (right = head; right >= 0; right--)
                if (result[right].level == i)
                    break;

            //Note that j should be able to equal to (right-left) / 2
            for (int j = 0; j <= (right - left) / 2 ; j++)
                if (result[left+j].val != result[right-j].val)
                    return false;
        }

        return true;
    }
};



//DFS Version. We need to DFS twice, one from left to right, and one from right to left. If the tree is symmetric, then the two results should be the same.
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
    int leftResult[50000];
    int rightResult[50000];
    int leftN = 0;
    int rightN = 0;

    void DFSLeft(TreeNode *root){
        if (root == NULL){
            //We can not just skip those empty nodes, otherwise we will WA.
            leftResult[leftN] = -999;
            leftN += 1;
            return;
        }

        leftResult[leftN] = root->val;
        leftN += 1;
        DFSLeft(root->left);
        DFSLeft(root->right);

        return;
    }

    void DFSRight(TreeNode *root){
        if (root == NULL){
            rightResult[rightN] = -999;
            rightN += 1;
            return;
        }

        rightResult[rightN] = root->val;
        rightN += 1;
        DFSRight(root->right);
        DFSRight(root->left);

        return;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;

        DFSLeft(root);
        DFSRight(root);

        for ( int i = 0; i < leftN; i++)
            if ( leftResult[i] != rightResult[i])
                return false;

        return true;
    }
};


