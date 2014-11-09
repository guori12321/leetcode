//A tricky DP. When we have n nodes, we place one as the root, and for the rest of them, j on the left and n-1-j on the right, so there are f[j]*f[n-1-j] conditions. j can vary from 0 to n-1.
//
//Pay attention to all the boundaries. I submitted 5 times to AC.
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1, 0);
        //We have n nodes, so n+1 conditions, from 0 to n.

        f[0] = 1;
        f[1] = 1;

        for (int i = 2; i <= n; i++)
        //Attention that i can be n.
        {
            for (int j = 0; j <= i-1; j++)
            //attention that j can be i-1
                f[i] += f[j]*f[ i-1-j ];
        }

        return f[n];
        //Note that when we want to use f[n], we need to claim n+1 integers.
    }
};
